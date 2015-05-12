#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main()
{
    struct stat buf;
    if (stat("./test.txt", &buf) == -1) {
        printf("stat error\n");
        exit(0);
    }

    if ((buf.st_mode & S_IRGRP) != 0) {
        printf("user of the group can read\n");
    } else {
        printf("user of the group can not read\n");
    }

    return 0;
}
