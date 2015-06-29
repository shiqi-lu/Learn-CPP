// my_ls.c - list all the file in a directory
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#define MAX 1024
void my_ls(char * root)
{
    DIR * dir;
    struct dirent * ptr;
    int count;
    dir = opendir(root);
    if (dir == NULL) {
        perror("fail to open dir");
        exit(1);
    }
    errno = 0;
    while ((ptr = readdir(dir)) != NULL) {
        if (strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0) {
            continue;
        }
        printf("%s\t", ptr->d_name);
        ++count;
        if (count % 5 == 0) {
            printf("\n");
        }
 
    }
    if (errno != 0) {
        perror("fail to read dir");
        exit(1);
    }
    closedir(dir);
}

int main(int argc, char * argv[])
{
    if (argc != 2) {
        printf("usage: ./my_ls DIR");
        exit(1);
    }
    my_ls(argv[1]);

    return 0;
}
