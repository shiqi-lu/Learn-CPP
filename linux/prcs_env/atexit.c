// atexit.c - set process ending function
#include <stdio.h>
#include <stdlib.h>

void f1()
{
    printf("the first exit handler\n");
}

void f2()
{
    printf("the second exit handler\n");
}

int main()
{
    if (atexit(f1) == -1) {
        perror("fail to set exit handler");
        exit(1);
    }

    if (atexit(f1) == -1) {
        perror("fail to set exit handler");
        exit(1);
    }

    if (atexit(f2) == -1) {
        perror("fail to set exit handler");
        exit(1);
    }

    return 0;
}
