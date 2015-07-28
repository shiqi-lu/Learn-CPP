// test_raise.c - quit process using raise()
#include <stdio.h>
#include <signal.h>

int main()
{
    printf("kill myself\n");
    raise(SIGKILL);
    printf("should not be here, never\n");

    return 0;
}

