// strerror.c -  strerr to output errmsg
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main()
{
    int fd;
    errno = 0;
    fd = open("/tmp/test.txt", O_RDWR);
    if (errno == 0) {
        printf("Successful\n");
    } else {
        int err = errno;
        printf("Fail : the reason is : %s\n", strerror(err));
    }
    close(fd);

    return 0;
}
