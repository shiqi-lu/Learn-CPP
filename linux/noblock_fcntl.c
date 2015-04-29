#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define MAX 100000
#define LEN 1024

int main(int argc, char * argv[])
{
    int fd1, fd2;
    FILE * fp;
    int flags;
    char buf[MAX];
    int n, rest;
    char * p = buf;
    char content[LEN];
    if (argc != 3) {
        printf("expect args\n");
        exit(1);
    }
    fd1 = open(argv[1], O_RDONLY);
    if (fd1 == -1) {
        perror("fail to read");
        exit(1);
    }
    fd2 = open(argv[2], O_WRONLY);
    if (fd2 == -1) {
        perror("fail to read");
        exit(1);
    }

    fp = fdopen(fd2, "w");
    if (fp == NULL) {
        perror("fail to open");
        exit(1);
    }

    flags = fcntl(STDOUT_FILENO, F_GETFL, 0);
    if (flags == -1) {
        perror("fail to fcntl");
        exit(1);
    }

    flags |= O_NONBLOCK;
    if (fcntl(STDOUT_FILENO, F_SETFL, 0) == -1) {
        perror("fail to fcntl");
        exit(1);
    }

    rest = read(fd1, buf, MAX);
    printf("get %d bytes from %s\n", rest, argv[1]);
    while (rest > 0) {
        errno = 0;
        n = write(STDOUT_FILENO, p, rest);
        fprintf(fp, "write %d, errno %s\n", n, strerror(errno));
        if (rest > 0) {
            p += n;
            rest -= n;
        }
    }
    printf("done\n");
    close(fd1);
    fclose(fp);

    return 0;
}
