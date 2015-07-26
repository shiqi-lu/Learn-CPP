// nozombie.c - avoid create zombie process
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
        printf("the child\n");
        pid = fork();
        if (pid < 0) {
            printf("fail to fork\n");
            exit(1);
        } else if (pid == 0) {
            printf("do something you want\n");
            sleep(5);
            printf("done\n");
            exit(0);
        } else {
            exit(0);
        }
    } else {
        if (waitpid(pid, NULL, 0) > 0) {
            printf("child exited\n", pid);
        }
            sleep(10);
            printf("the parent\n");
    }

    return 0;
}
