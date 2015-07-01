// readlink.c - read the content of symbol link
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX 1024

int main()
{
    char buf[MAX];
    int fd, n;

    if (symlink("test.txt", "sl1") == -1) {
        perror("fail to create symbol link");
        exit(1);
    }
    if (symlink("sl1", "sl2") == -1) {
        perror("fail to create symbol link");
        exit(1);
    }
    if ((n = readlink("sl1", buf, MAX)) == -1) {
        perror("fail to read symbol link");
        exit(1);
    }
    buf[n] = '\0';
    printf("%s\n", buf);
    if ((n = readlink("sl2", buf, MAX)) == -1) {
        perror("fail to read symbol link");
        exit(1);
    }
    buf[n] = '\0';
    printf("%s\n", buf);

    return 0;
}
