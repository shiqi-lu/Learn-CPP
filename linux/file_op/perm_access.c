//perm_access.c - test access()
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main()
{
    int fd;
    struct stat statbuf;;
    pid_t pid;
    uid_t ruid, euid;
    if (stat("test.txt", &statbuf) == -1) {
        perror("fail to stat");
        exit(1);
    }
    
    if ((ruid = getuid()) == -1) {
        perror("fail to get ruid");
        exit(1);
    }

    if ((euid = geteuid()) == -1) {
        perror("fail to get euid");
        exit(1);
    }

    printf("real id is : %u, effective id is : %u \n", (unsigned int)ruid, (unsigned int)euid);
    printf("file owner is : %u\n", statbuf.st_uid);
    if (access("test.txt", R_OK) == -1) {
        perror("fail to access");
        exit(1);
    }

    printf("access successfully!\n");
    if ((fd == open("test.txt", O_RDONLY)) == -1) {
        perror("fail to open");
        exit(1);
    }
    printf("ready to read\n");

    close(fd);

    return 0;
}
