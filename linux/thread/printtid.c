// printtid.c - create thread and print
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void * thfn(void * arg)
{
    pid_t pid = getpid();
    pthread_t tid = pthread_self();
    printf("the new thread; pid is :%u, tid is:%u\n", (unsigned int)pid, (unsigned int)tid);
    return NULL;
}

int main()
{
    pid_t pid = getpid();
    pthread_t tid, mtid;
    mtid = pthread_self();
    int err = pthread_create(&mtid, NULL, thfn, NULL);

    if (err != 0) {
        printf("can't create thread %d\n", strerror(err));
        exit(1);
    }
    sleep(1);
    printf("the main thread: pid is %u, tid is : %u\n", (unsigned int)pid, (unsigned int)mtid);

    return 0;
}
