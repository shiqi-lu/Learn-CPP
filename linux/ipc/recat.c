// recat.c - create pipe using popen() and pclose()
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <fcntl.h>
#define BUFSZ PIPE_BUF
int main()
{
    FILE * fp;
    char * cmd = "cat file1";
    char buf[BUFSZ];
    if ((fp = popen(cmd, "r")) == NULL) {
        perror("fail to popen");
        exit(1);
    }
    while ((fgets(buf, BUFSZ, fp)) != NULL) {
        printf("%s", buf);
    }
    pclose(fp);

    return 0;
}
