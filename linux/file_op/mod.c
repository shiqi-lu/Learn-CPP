// mod.c
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#define NEW_MOD S_IRUSR | S_IRGRP | S_IROTH
int main()
{
    int fd;
    struct stat statbuf;
    mode_t mode;
    if (chmod("test.txt", NEW_MOD) == -1) {
        perror("fail to change mode");
        exit(1);
    }

    if (stat("test2.txt", &statbuf) == -1) {
        perror("fail to stat");
        exit(1);
    }

    mode = statbuf.st_mode;
    mode &= (~ S_IRWXU & ~ S_IRWXG & ~ S_IRWXO);

    mode |= (NEW_MOD);
    if (chmod("test2.txt", mode) == -1) {
        perror("fail to change modee");
        exit(1);
    }

    return 0;
}
