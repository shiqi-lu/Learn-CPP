#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    char * buf;
    int i;
    struct stat statbuf;
    if (stat("test.txt", &statbuf) == -1) {
        perror("fail to get stat");
        exit(1);
    }

    fd = open("test.txt", O_RDONLY);
    if (fd == -1) {
        perror("fail to open");
        exit(1);
    }

    buf = (char *)mmap(NULL, statbuf.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (buf == MAP_FAILED) {
        perror("fail to mmap");
        exit(1);
    }
    i = 0;
    while (i < statbuf.st_size) {
        printf("%c", buf[i]);
        ++i;
    }
    printf("\n");
    if (munmap(buf, statbuf.st_size) == -1) {
        perror("fail to munmap");
        exit(1);
    }
    close(fd);

    return 0;
}
