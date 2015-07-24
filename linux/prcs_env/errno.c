// errno.c - use errno to see error info
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main()
{
    int fd;
    errno = 0;
    fd = open("/taamp/asht.txt", O_RDWR);
    if (errno == 0) {
        printf("Successful\n");
    } else {
        printf("Fail to open, errno is : %d\n", errno);
        exit(1);
    }
    close(fd);

    return 0;
}
