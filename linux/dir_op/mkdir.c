// mkdir.c - create a new directory
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

int main()
{
    if (mkdir("/tmp/aa", S_IRUSR | S_IWUSR | S_IXUSR) == -1) {
        perror("fail to mkdir");
        exit(1);
    }
    printf("successfully make a dir\n");

    return 0;
}
