#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = open("test.txt", O_RDWR);
    if (fd == -1) {
        perror("fail to open");
        exit(1);
    }
    int i = 0;
    while (i < 3) {
        sleep(5);
        printf("hello\n");
        if (write(fd, "hello\n", 6) == -1) {
            perror("fail to write");
            exit(1);
        }
        
        if (fsync(fd) == -1) {
            perror("fail to fsync");
            exit(1);
        }
        ++i;
    }
    close(fd);

    return 0;
}
