#include <stdio.h>
#include <stdlib.h>

extern ** environ;

int main()
{
    if (clearenv() == -1) {
        perror("fail to clear env");
        exit(1);
    }

    if (environ == NULL) {
        printf("done\n");
    }

    return 0;
}
