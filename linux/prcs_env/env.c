// env.c - print env variables
#include <stdio.h>

extern ** environ;

int main()
{
    int i;
    for (i = 0; environ[i] != NULL; ++i) {
        printf("each : %s\n", environ[i]);
    }

    return 0;
}
