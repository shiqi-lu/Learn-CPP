// get_cwd.c - get current working directory
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX 1024

int main()
{
    pid_t pid;
    char buf[MAX];
    if (chdir("./tmp") == -1) {
        perror("fail to change dir");
        exit(1);
    }
    if (getcwd(buf, MAX) == NULL) {
        perror("fail to get pwd");
        exit(1);
    }
    printf("the parent : %s \n", buf);
    pid = fork();
    if (pid == -1) {
        perror("fail to fork");
        exit(1);
    } else if (pid == 0) {
        if (getcwd(buf, MAX) == NULL) {
            perror("fail to get pwd");
            exit(1);
        }
        printf("the child : %s\n", buf);
    } else {
        if (wait(NULL) == -1) {
            perror("fail to wait");
            exit(1);
        }
    }

    return 0;
}
