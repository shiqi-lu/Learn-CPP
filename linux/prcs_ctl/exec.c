// exec.c - exec()
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    pid_t pid = fork();
    if (pid < 0) {
        printf("fail to fork\n");
        exit(1);
    } else if (pid == 0) {
        if (execp("hello", NULL) < 0) {
            printf("fail to exec\n");
            exit(0);
        }
        printf("the child is not hello\n");
        exit(0);
    }
    printf("the parent\n");

    return 0;
}
