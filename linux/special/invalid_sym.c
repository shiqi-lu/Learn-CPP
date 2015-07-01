// invalid_sym.c - create a n invalid symlink
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
    int fd;
    if (symlink("nothing.txt", "invalid_link") == -1) {
        perror("fail to create symbol link");
        exit(1);
    }
    printf("already create a symbol-link\n");
    if ((fd = open("invalid_link", O_RDWR)) == -1) {
        perror("fail to open");
        exit(1);
    }
    printf("should not be here\n");

    return 0;
}
