// file_error.c - open failed
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    fd = open("no_such_file", O_RDONLY);
    if (fd == -1) {
        perror("fail to open");
    } else {
        close(fd);
    }

    fd = open("denied", O_WRONLY);
    if (fd == -1) {
        perror("fail to open");
    } else {
        close(fd);
    }

    return 0;
}
