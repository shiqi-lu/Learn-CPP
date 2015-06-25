// chown.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main()
{
    struct stat statbuf;
    if (stat("test.txt", &statbuf) == -1) {
        perror("fail to get status");
        exit(1);
    }
    printf("before changing owner\n");
    printf("the owner of test.txt is : %d\n", (unsigned int)statbuf.st_uid);
    printf("the group of test.txt is : %d\n", (unsigned int)statbuf.st_gid);
    printf("\n");
    if (chown("test.txt", 0, -1) == -1) {
        perror("fail to change owner");
        exit(1);
    }
    if (stat("test.txt", &statbuf) == -1) {
        perror("fail to get status");
        exit(1);
    }

    printf("after changing owner\n");
    printf("the owner of test.txt is : %d\n", (unsigned int)statbuf.st_uid);
    printf("the group of test.txt is : %d\n", (unsigned int)statbuf.st_gid);
    printf("\n");

    if (chown("test.txt", 100, -1) == -1) {
        perror("fail to change owner");
        exit(1);
    }

    if (stat("test.txt", &statbuf) == -1) {
        perror("fail to get status");
        exit(1);
    }

    printf("noexist owner\n");
    printf("the owner of test.txt is : %d\n", (unsigned int)statbuf.st_uid);
    printf("the group of test.txt is : %d\n", (unsigned int)statbuf.st_gid);

    return 0;
}
