// cancel.c - cancel a pthread
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void * tfn1(void * arg)
{
    printf("new thread\n");
    sleep(10);
}

int main()
{
    pthread_t tid;
    void * res;
    int err;
    err = pthread_create(&tid, NULL, tfn1, NULL);
    if (err != 0) {
        printf("can't create thread %d\n", strerror(err));
        exit(1);
    }
    sleep(1);
    err = pthread_cancel(tid);
    if (err != 0) {
        printf("can't calcel thread %d\n", strerror(err));
        exit(1);
    }
    err = pthread_join(tid, &res);
    if (err != 0) {
        printf("can't join thread %d\n", strerror(err));
        exit(1);
    }

    if (res == PTHREAD_CANCELED) {
        printf("thread %u has been canceled\n", (unsigned int)tid);
    } else {
        printf("error\n");
    }

    return 0;
}
