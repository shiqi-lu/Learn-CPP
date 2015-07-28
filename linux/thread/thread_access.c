// thread_access.c - pthread access resources
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
typedef struct arg_struct {
    int * heap;
    int * stack;
}ARG;
FILE * fp = NULL;
void * thfn(void * arg)
{
    ARG * p;
    p = (ARG *)arg;
    ++(*p->heap);
    ++(*p->stack);
    fprintf(fp, "new thread heap: %d stack : %d\n", *(p->heap), *(p->stack));
    printf("the new thread done\n");
    return NULL;
}

int main()
{
    pthread_t tid, tid2;
    ARG arg;
    int stack;
    int err;
    int * heap = (int *)malloc(1 * sizeof(int));
    if (heap == NULL) {
        perror("fail to malloc");
        exit(1);
    }
    *heap = 2;
    stack = 3;
    arg.heap = heap;
    arg.stack = & stack;
    if ((fp = fopen("test.txt", "wb")) == NULL) {
        perror("fail to open");
        exit(1);
    }
    err = pthread_create(&tid, NULL, thfn, (void *)&arg);
    if (err != 0) {
        printf("can't create thread %d\n", strerror(err));
        exit(1);
    }
    sleep(10);
    ++(*heap);
    ++stack;
    fprintf(fp, "main thread: heap %d stack : %d\n", *(arg.heap), *(arg.stack));
    printf("the main thread done\n");
    fclose(fp);
    free(heap);

    return 0;
}
