// sigset.c - 
#include <stdio.h>
#include <signal.h>

int main()
{
    sigset_t sig_set;
    sigemptyset(&sig_set);
    sigaddset(&sig_set, SIGKILL);

    if ((sigismember(&sig_set, SIGKILL)) == 1) {
        printf("SIGKILL has been set\n");
    } else {
        printf("can't set signal set\n");
    }

    return 0;
}
