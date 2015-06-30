// chdir.c - change the porcess' working directory
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main()
{
    int fd;
    char * p = "hello world\n";
    if (chdir("./tmp") == -1) {
        perror("fail to change dir");
        exit(1);
    }
    printf("change dir sucessfully\n");
    if ((fd = open("test.txt", O_CREAT | O_RDWR)) == -1) {
        perror("fail to open");
        exit(1);
    }
    if (write(fd, p, strlen(p)) == -1) {
        perror("fail to write");
        exit(1);
    }
    close(fd);

    return 0;
}
