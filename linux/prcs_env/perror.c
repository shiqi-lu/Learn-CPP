//perror.c - perror output errmsg
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main()
{
    int fd;
    fd = open("/tmp/test.txt", O_RDWR);
    if (fd == -1) {
        perror("fail to open");
        exit(1);
    }

    close(fd);
    return 0;
}
