// setuid.c - modify current process uid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    FILE * fp;
    uid_t uid = getuid();
    uid_t euid = geteuid();

    printf("the uid is : %d\n", uid);
    printf("the euid is : %d\n", euid);
    if (setuid(8000) == -1) {
        perror("fail to set uid");
        exit(1);
    }
    printf("after changing\n");
    uid = getuid();
    euid = geteuid();
    printf("the uid is : %d\n", uid);
    printf("the euid is : %d\n", euid);

    return 0;
}
