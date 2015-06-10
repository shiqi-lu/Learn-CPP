// cp.c - copy file
// usage: cp src dec
// src -- source (absolute path)
// dec -- destination (absolute path)
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX 1024

int main(int argc, char * argv[])
{
    char buf[MAX];
    int in, out;
    int n;
    if (argc != 3) {
        exit(1);
    }
    if ((in = open(argv[1], O_RDONLY)) == -1) {
        perror("fail to open");
        exit(1);
    }
    if ((out = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0755)) == -1) {
        perror("fail to open");
        exit(1);
    }
    while ((n = read(in, buf, MAX)) > 0) {
        if (write(out, buf, n) != n) {
            perror("fail to write");
            exit(1);
        }
    }
    if (n < 0) {
        perror("fail to read");
        exit(1);
    }
    printf("copy done\n");
    close(in);
    close(out);

    return 0;
}

