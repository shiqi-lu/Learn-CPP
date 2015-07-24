// putenv.c - assign an env var
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char * p = getenv("HOME");
    if (p == NULL) {
        perror("fail to getenv");
        exit(1);
    }

    printf("$HOME is %s\n", p);
    if (putenv("HOME=/home/admin") == -1) {
        perror("fail to putenv");
        exit(1);
    }

    p = getenv("HOME");
    if (p == NULL) {
        perror("fail to getenv");
        exit(1);
    }

    printf("$HOME is %s\n", p);
    if (putenv("ADMIN=hello") == -1) {
        perror("fail to putenv");
        exit(1);
    }

    p = getenv("ADMIN");
    if (p == NULL) {
        perror("fail to getenv");
        exit(1);
    }
    printf("$ADMIN is %s\n", p);

    return 0;
}
