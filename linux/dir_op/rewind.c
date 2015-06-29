// rewind.c
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>

int main()
{
    DIR * dir;
    struct dirent * d_ptr;
    dir = opendir("./");
    if (dir == NULL) {
        perror("fail to open dir");
        exit(1);
    }
    while ((d_ptr = readdir(dir)) != NULL) {
        printf("dir name is : %s \n", d_ptr->d_name);
    }
    printf("read again\n");
    rewinddir(dir);
    while ((d_ptr = readdir(dir)) != NULL) {
        printf("dir name is : %s \n", d_ptr->d_name);
    }
    closedir(dir);

    return 0;
}
