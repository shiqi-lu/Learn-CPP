#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <setjmp.h>
#include <signal.h>
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

    buf = (char *)mmap(NULL, statbuf.st_size, PROT_READ, MAP_SHARED, fd, 0);
    if (buf == MAP_FAILED) {
        perror("fail to mmap");
        exit(1);
    }

    printf("chang mode\n");
    if (mprotect(buf, statbuf.st_size, PROT_READ | PROT_WRITE) == -1) {
        perror("fail to alter permission");
        exit(1);
    }
    
    printf("write done\n");
    strcpy(buf, "China\n");
    if (munmap(buf, statbuf.st_size) == -1) {
        perror("fail to munmap");
        exit(1);
    }
    close(fd);

    return 0;
}
