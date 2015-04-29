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
    char * p;
    int i;
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

    buf = (char *)mmap(NULL, statbuf.st_size, PROT_WRITE, MAP_SHARED, fd, 0);
    if (buf == MAP_FAILED) {
        perror("fail to mmap");
        exit(1);
    }
    i = 0;
    p = buf;
    while (i < 3) {
        sleep(3);
        printf("hello world\n");
        memcpy(p, "hello world\n", 12);
        ++i;
        p += 12;
        if (msync(buf, 12, MS_SYNC) == -1) {
            perror("fail to msync");
            exit(1);
        }
    }

    if (munmap(buf, statbuf.st_size) == -1) {
        perror("fail to munmap");
        exit(1);
    }
    close(fd);

    return 0;
}
