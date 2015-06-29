// locate read/write in a directory
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    DIR * dir;
    struct dirent * d_ptr;
    off_t offset;
    dir = opendir("/Users/liondev");
    if (dir == NULL) {
        perror("fail to open dir");
        exit(1);
    }
    while ((d_ptr = readdir(dir)) != NULL) {
        offset = telldir(dir);
        if (offset == -1) {
            perror("fail to get offset");
            exit(1);
        }
        printf("dir name is : %s offset is :%d\n", d_ptr->d_name, (int)offset);
    }
    closedir(dir);

    return 0;
}
