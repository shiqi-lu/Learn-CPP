// truncate.c - truncate the file to expand the file size
// Usage: ./truncate 32 20
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define MAX 32

int main(int argc, char * argv[])
{
    int fd;
    int len;
    int rest;
    char buf[MAX];
    if (argc != 3) {
        len = MAX;
        rest = 0;
    } else {
        len = atoi(argv[1]);
        rest = atoi(argv[2]);
    }

    if (truncate("test.txt", len) == -1) {
        perror("fail to truncate");
        exit(1);
    }

    fd = open("test.txt", O_RDWR | O_APPEND);
    if (fd == -1) {
        perror("fail to open");
        exit(1);
    }

    int i;
    for (i = 0; i < rest; ++i) {
        buf[i] = 'a';
    }

    if (write(fd, buf, rest) == -1) {
        perror("fail to write");
        exit(1);
    }
    close(fd);

    return 0;
}
