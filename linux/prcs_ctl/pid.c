// pid.c - print current process id
#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("id of current process : %u\n", getpid());
    printf("parent id of current process : %u\n", getppid());
    printf("user id of current process : %u\n", getuid());
    printf("effective user id of current process : %u\n", geteuid());
    printf("group id of current process : %u\n", getgid());
    printf("effective group id of current process : %u\n", getegid());

    return 0;
}
