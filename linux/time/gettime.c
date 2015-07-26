// gettime.c - use time()
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t cur_time;
    if ((cur_time = time(NULL)) == -1) {
        perror("time");
        exit(1);
    }
    printf("the current time is : %d\n", (int)cur_time);

    return 0;
}
