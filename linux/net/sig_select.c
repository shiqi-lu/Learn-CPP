// sig_select.c - use select()
#include <stdio.h>
#include <sys/select.h>
#include <stdlib.h>
#include <signal.h>
void sigusr1_handler(int signo)
{
    printf("catch SIGUSR1\n");
}

int main()
{
    int rdy;
    if (signal(SIGUSR1, sigusr1_handler) == SIG_ERR) {
        perror("can't set handler, for SIGUSR1");
        exit(1);
    }
    rdy = select(1, NULL, NULL, NULL, NULL);
    printf("should never be here\n");

    return 0;
}
