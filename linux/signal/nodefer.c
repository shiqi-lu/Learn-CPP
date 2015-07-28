// nodefer.c -
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sigusr1_handler(int signo)
{
    printf("catch SIGUSR1\n");
    sleep(5);
    printf("back to main\n");
}

int main()
{
    struct sigaction act;
    act.sa_handler = sigusr1_handler;
    act.sa_flags = SA_NODEFER;
    sigemptyset(&act.sa_mask);
    if (sigaction(SIGUSR1, &act, NULL) == -1) {
        perror("fail to set handler for SIGUSR1");
        exit(1);
    }
    printf("precess begin\n");
    sleep(15);
    printf("done\n");

    return 0;
}
