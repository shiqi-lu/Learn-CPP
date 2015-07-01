// readsym.c - read and write symlink
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#define MAX 1024

int main()
{
    int fd, n;
    char buf[MAX];
    if (symlink("test.txt", "sym_link") == -1) {
        perror("fail to create symbol link");
        exit(1);
    }

    printf("already create a symbol-link\n");
    if ((fd = open("sym_link", O_RDWR)) == -1) {
        perror("fail to open");
        exit(1);
    }

    if ((n = read(fd, buf, MAX)) == -1) {
        perror("fail to read");
        exit(1);
    }
    buf[n] = '\0';
    printf("file content is : %s\n", buf);
    strcat(buf, ", admin");
    if (write(fd, buf, strlen(buf)) == -1) {
        perror("fail to write");
        exit(1);
    }
    printf("done\n");
    close(fd);

    return 0;
}
