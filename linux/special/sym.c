// sym.c - create a symlink
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    if (symlink("test.txt", "symbol_link") == -1) {
        perror("fail to create symbol link");
        exit(1);
    }
    printf("create a new symbol-link\n");

    return 0;
}
