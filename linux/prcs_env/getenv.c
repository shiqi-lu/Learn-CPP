// getenv.c - get an environment variable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char * p = getenv("HOME");
    if (p == NULL) {
        perror("fail to get env");
        exit(1);
    }
    printf("$HOME is %s\n", p);

    return 0;
}
