#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd;
    char * buf;
    struct stat statbuf;
    if (stat("test.txt", &statbuf) == -1) {
        perror("fail to get stat");
        exit(1);
    }

    fd = open("test.txt", O_RDWR);
    if (fd == -1) {
        perror("fail to open");
        exit(1);
    }

    buf = (char *)mmap(NULL, statbuf.st_size, PROT_WRITE, MAP_PRIVATE, fd, 0);
    if (buf == MAP_FAILED) {
        perror("fail to mmap");
        exit(1);
    }

    strcpy(buf, "China beijing");
    if (munmap(buf, statbuf.st_size) == -1) {
        perror("fail to munmap");
        exit(1);
    }
    close(fd);

    return 0;
}
