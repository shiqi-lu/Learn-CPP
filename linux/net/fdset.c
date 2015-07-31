// fdset.c 
#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>

int main()
{
    fd_set fdset;
    FD_ZERO(&fdset);
    FD_SET(STDOUT_FILENO, &fdset);
    if (FD_ISSET(STDOUT_FILENO, &fdset) != 0) {
        printf("stdout has been setted\n");
    } else {
        printf("stdout has not been setted\n");
    }
    FD_CLR(STDOUT_FILENO, &fdset);
    if (FD_ISSET(STDOUT_FILENO, &fdset) != 0) {
        printf("stdout has been setted\n");
    } else {
        printf("stdout has not been setted\n");
    }

    return 0;
}

