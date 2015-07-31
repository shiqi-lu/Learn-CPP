// client.c
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <strings.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "iolib.h"
#define MAX_LINE 100
int main(int argc, char * argv[])
{
    struct sockaddr_in sin;
    char buf[MAX_LINE];
    int sfd;
    int port = 8000;
    char * str = "test sting";
    int n;
    if (argc > 1) {
        str = argv[1];
    }
    bzero(&sin, sizeof(sin));
    sin.sin_family = AF_INET;
    inet_pton(AF_INET, "127.0.0.1", &sin.sin_addr);
    sin.sin_port = htons(port);
    if ((sfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("fail to connect");
        exit(1);
    }
    if (connect(sfd, (const struct sockaddr *)&sin, sizeof(sin)) == -1) {
        perror("fail to connect");
        exit(1);
    }
    n = my_write(sfd, str, strlen(str) + 1);
    if (n == -1) {
        exit(1);
    }
    n = my_read(sfd, buf, MAX_LINE);
    if (n == -1) {
        exit(1);
    }

    printf("recive from server: %s\n", buf);
    if (close(sfd) == -1) {
        perror("fail to close");
        exit(1);
    }

    return 0;
}
