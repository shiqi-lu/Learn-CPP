// order.c - test
#include <stdio.h>
#include <arpa/inet.h>

int main()
{
    short a  = htons(0x102);
    short * p = &a;
    if (*((char *)p) == 0x01) {
        printf("big-endian\n");
    } else if (*((char *)p) == 0x02) {
        printf("litten-endian\n");
    } else {
        printf("unknown\n");
    }

    return 0;
}
