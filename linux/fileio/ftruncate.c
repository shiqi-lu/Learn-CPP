// ftruncate.c -- truncate an existing file
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = open("test.txt", O_WRONLY);
    if (fd == -1) {
        perror("fail to open");
        exit(1);
    }

    if (ftruncate(fd, 0) == -1) {
        perror("fail to truncate");
        exit(1);
    }
    close(fd);

    return 0;
}
