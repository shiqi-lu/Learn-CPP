// proc_pause.c - do not response SIGTERM
#include <stdio.h>
#include <unistd.h>
int main()
{
    printf("start running\n");
    pause();
    return 0;
}
