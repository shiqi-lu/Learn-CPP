// file_type.c -- test the file type
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char * argv[])
{
    char * str;
    int i;
    struct stat buf;
    for (i = 1; i < argc; ++i) {
        printf("%s is ", argv[i]);
        if (stat(argv[i], &buf) == -1) {
            perror("fail to stat");
            continue;
        }
        if (S_ISREG(buf.st_mode)) {
            printf("regular file\n");
        } else if (S_ISDIR(buf.st_mode)) {
            printf("directory file\n");
        } else if (S_ISCHR(buf.st_mode)) {
            printf("character special file\n");
        } else if (S_ISBLK(buf.st_mode)) {
            printf("block special file\n");
        } else if (S_ISFIFO(buf.st_mode)) {
            printf("FIFO file\n");
        } else if (S_ISSOCK(buf.st_mode)) {
            printf("socket file\n");
        } else {
            printf("unknow\n");
        }
    }

    return 0;
}
