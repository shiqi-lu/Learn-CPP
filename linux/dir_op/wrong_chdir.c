// wrong_chdir.c - Wrong on change working directory
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 1024

int main()
{
    char buf[MAX];
    if (getcwd(buf, MAX) == NULL) {
        perror("fail to get cwd");
        exit(1);
    }
    printf("%s\n", buf);
    if (system("cd ./tmp") == -1) {
        perror("fail to exec");
        exit(1);
    }
    if (getcwd(buf, MAX) == NULL) {
        perror("fail to get pwd");
        exit(1);
    }
    printf("%s\n", buf);

    return 0;
}
