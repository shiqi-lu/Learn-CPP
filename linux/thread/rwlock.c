// rwlock.c - 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/time.h>
#include <time.h>
typedef struct job * Job;
struct job {
    pthread_t tid;
    Job next;
    int val;
};
struct timeval begintime;

int insert(Job head, int val, pthread_t tid)
{
    Job p, q;
    p = head;
    if (p != NULL) {
        while (p->next != NULL) {
            p = p->next;
        }
    }
    q = (Job)malloc(sizeof(struct job));
    if (q == NULL) {
        perror("fail to malloc");
        return -1;
    }
    q->next = NULL;
    q->val = val;
    q->tid = tid;
    if (p == NULL) {
        head = q;
        return 0;
    }
    p->next = q;
    return 0;
}

int free_job(Job head)
{
    Job p, q;
    for (p = head; p != NULL; p = p->next) {
        q = p;
        free(q);
    }
    return 0;
}

void print(Job head)
{
    Job p;
    for (p = head->next; p != NULL; p = p->next) {
        printf("thread %u : %d\n", (unsigned int)p->tid, p->val);
    }
}

void * tf10(void * arg)
{
    pthread_rwlock_t q_rwlock;
    Job p, q;
    Job task = (struct job *)malloc(sizeof(struct job));
    task->next = NULL;
    task->val = 0;
    task->tid = -1;
    struct timeval endtime;
    float elapsed_time;
    pthread_t tid = pthread_self();
    long long count = 0;
    while (count < 100000000) {
        if (pthread_rwlock_tryrdlock(&q_rwlock) == 0) {
            q = (Job)arg;
            p = q->next;
            while (p != NULL) {
                if (tid == p->tid) {
                    ++count;
                }
                p = p->next;
            }
            pthread_rwlock_unlock(&q_rwlock);
        }
    }
    gettimeofday(&endtime, NULL);
    elapsed_time = 1000000 * (endtime.tv_sec-begintime.tv_sec) + endtime.tv_usec - begintime.tv_usec;
    elapsed_time /= 1000000;
    printf("This total used time is: %f seconds.\n", elapsed_time);
    return (void *)0;
}

int main()
{
    pthread_t tid1, tid2;
    int i, err;
    pthread_rwlock_t q_rwlock;
    pthread_rwlock_init(&q_rwlock, NULL);
    gettimeofday(&begintime, NULL);
    Job item = (Job)malloc(sizeof(struct job));
    item->next = NULL;
    item->val = 0;
    item->tid = -1;
    if ((err = pthread_create(&tid1, NULL, tf10, item)) == -1) {
        printf("fail to create thread %s\n", strerror(err));
        exit(1);
    }
    if ((err = pthread_create(&tid2, NULL, tf10, item)) == -1) {
        printf("fail to create thread %s\n", strerror(err));
        exit(1);
    }
    printf("===the 1st put===\n");
    pthread_rwlock_wrlock(&q_rwlock);
    for (i = 0; i < 2; ++i) {
        if (insert(item, i, tid1) == -1) {
            exit(1);
        }
        if (insert(item, i + 1, tid2) == -1) {
            exit(1);
        }
    }
    if (insert(item, 10, tid1) == -1) {
        exit(1);
    }
    pthread_rwlock_unlock(&q_rwlock);
    printf("===the 2nd put===\n");
    pthread_rwlock_wrlock(&q_rwlock);
    if (insert(item, 9, tid2) == -1) {
        exit(1);
    }
    pthread_rwlock_unlock(&q_rwlock);
    err = pthread_join(tid1, NULL);
    if (err != 0) {
        printf("can't join thread %s\n", strerror(err));
        exit(1);
    }
    pthread_join(tid2, NULL);
    if (err != 0) {
        printf("can't join thread %s\n", strerror(err));
        exit(1);
    }
    printf("main thread done\n");
    pthread_rwlock_destroy(&q_rwlock);

    return 0;
}
