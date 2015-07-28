// write_fifo.c - use FIFO to communicate
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#define BUFSZ PIPE_BUF
int main()
{
    int fd;
    int n, i;
    char buf[BUFSZ];
    time_t tp;
    printf("I am %d\n", getpid());
    if ((fd = open("fifo1", O_WRONLY)) < 0) {
        perror("open");
        exit(1);
    }
    for (i = 0; i < 10; ++i) {
        time(&tp);
        n = sprintf(buf, "write_fifo %d sends %d", getpid(), ctime(&tp));
        printf("Send msg: %s\n", buf);
        if ((write(fd, buf, n+1)) < 0) {
            perror("write");
            close(fd);
            exit(1);
        }
        sleep(3);
    }
    close(fd);

    return 0;
}
