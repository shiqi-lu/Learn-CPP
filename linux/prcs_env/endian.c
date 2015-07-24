#include <stdio.h>

int main()
{
    int a = 0x1234578;
    char * p;
    p = (char *) (&a);
    if (*p == 0x78) {
        printf("The litte endian\n");
    } else {
        printf("The big endian\n");
    }

    return 0;
}
