//seekdir.c - locate a directory
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>

int main()
{
    DIR * dir;
    struct dirent * d_ptr;
    dir = opendir("/Users/liondev");
    if (dir == NULL) {
        perror("fail to open dir");
        exit(1);
    }
    seekdir(dir, 24);

    while ((d_ptr = readdir(dir)) != NULL) {
        printf("dir name is :%s \n", d_ptr->d_name);
    }
    closedir(dir);

    return 0;
}
