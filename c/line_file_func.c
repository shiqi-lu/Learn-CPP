#include <stdio.h>

#define BLURT printf("This is line %d of file %s (function %s)\n", \
                     __LINE__, __FILE__, __func__)

void uuuu_fun()
{
    BLURT;
}

int main()
{
    uuuu_fun();
    printf("This is line %d of file %s (function %s)\n",
           __LINE__, __FILE__, __func__);
    return 0;
}
