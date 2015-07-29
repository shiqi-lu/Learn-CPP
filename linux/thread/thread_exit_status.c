// thread_exit_status.c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct a {
    int b;
    int c;
}r3;

void * tfn1(void * arg)
{
    struct a r1;
    printf("the first one:\n");
    r1.b = 10;
    r1.c = 11;
    return (void *)(&r1);
}

void * tfn2(void * arg)
{
    struct a * r2;
    printf("the second one:\n");
    r2 = (struct a *)malloc(sizeof(struct a));
    printf("structure at %x\n", (unsigned int)r2);
    r2->b = 10;
    r2->c = 11;
    return (void *)r2;
}

void * tfn3(void * arg)
{
    printf("the third one:\n");
    r3.b = 10;
    r3.c = 11;
    return (void *)(&r3);
}

void * tfn4(void * arg)
{
    struct a * r4 = (struct a *)arg;
    printf("the fourth one:\n");
    r4->b = 10;
    r4->c = 11;
    return (void *)(&r4);
}

int main()
{
    pthread_t tid1, tid2, tid3, tid4;
    void * res;
    int err;

    err = pthread_create(&tid1, NULL, tfn1, NULL);
    if (err != 0) {
        printf("can't create thread %d\n", strerror(err));
        exit(1);
    }
    err = pthread_join(tid1, &res);
    if (err != 0) {
        printf("can't join thread %d\n", strerror(err));
        exit(1);
    }
    printf("1st result: %d, %d\n", ((struct a *)res)->b, ((struct a *)res)->c);

    err = pthread_create(&tid2, NULL, tfn2, NULL);
    if (err != 0) {
        printf("can't create thread %d\n", strerror(err));
        exit(1);
    }
    err = pthread_join(tid2, &res);
    if (err != 0) {
        printf("can't join thread %d\n", strerror(err));
        exit(1);
    }
    printf("2nd result: %d, %d\n", ((struct a *)res)->b, ((struct a *)res)->c);
    free(res);

    err = pthread_create(&tid3, NULL, tfn3, NULL);
    if (err != 0) {
        printf("can't create thread %d\n", strerror(err));
        exit(1);
    }
    err = pthread_join(tid3, &res);
    if (err != 0) {
        printf("can't join thread %d\n", strerror(err));
        exit(1);
    }
    printf("3rd result: %d, %d\n", ((struct a *)res)->b, ((struct a *)res)->c);

    err = pthread_create(&tid4, NULL, tfn2, NULL);
    if (err != 0) {
        printf("can't create thread %d\n", strerror(err));
        exit(1);
    }
    err = pthread_join(tid4, &res);
    if (err != 0) {
        printf("can't join thread %d\n", strerror(err));
        exit(1);
    }
    printf("4th result: %d, %d\n", ((struct a *)res)->b, ((struct a *)res)->c);

    return 0;
}
