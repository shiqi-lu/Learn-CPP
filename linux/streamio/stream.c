// stream.c - open and close stream
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
    FILE * fp;
    int fd;
    if ((fp = fopen("test.txt", "w+")) == NULL) {
        perror("fail to open");
        exit(1);
    }
    fprintf(fp, "hello world\n");
    fclose(fp);

    if ((fd = open("test.txt", O_RDWR)) == -1) {
        perror("fail to open");
        exit(1);
    }

    if ((fp= fdopen(fd, "a")) == NULL) {
        perror("fail to open stream");
        exit(1);
    }

    fprintf(fp, "hello world again\n");
    fclose(fp);

    return 0;
}
