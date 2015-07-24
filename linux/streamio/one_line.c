// one_line.c - read every line from a file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024

int main()
{
    char buf[MAX_LINE];
    FILE * fp;
    int len;
    if ((fp = fopen("test.txt", "r")) == NULL) {
        perror("fail to read");
        exit(1);
    }
    while (fgets(buf, MAX_LINE, fp) != NULL) {
        len = strlen(buf);
        buf[len - 1] = '\0';
        printf("%s %d\n", buf, len - 1);
    }

    return 0;
}
