#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    if (rmdir("./dir") == -1) {
        perror("fail to mkdir");
        exit(1);
    }
    printf("successfully remove a dir");

    return 0;
}
