// server3.c
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#define MAX_LINE 100
void my_fun(char * p)
{
    if (p == NULL) {
        return;
    }
    for (; *p != '\0'; ++p) {
        if (*p >= 'A' && *p <= 'Z') {
            *p = *p - 'A' + 'a';
        }
    }
}

int main()
{
    struct sockaddr_in sin;
    struct sockaddr_in cin;
    int s_fd;
    int port = 8000;
    socklen_t addr_len;
    char buf[MAX_LINE];
    char addr_p[INET_ADDRSTRLEN];
    int n, flags;
    bzero(&sin, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(port);
    s_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (s_fd == -1) {
        perror("fail to create socket");
        exit(1);
    }
    if (bind(s_fd, (struct sockaddr *)&sin, sizeof(sin)) == -1) {
        perror("call to bind");
        exit(1);
    }
    flags = fcntl(s_fd, F_GETFL);
    flags |= O_NONBLOCK;
    if (fcntl(s_fd, F_SETFL, flags) == -1) {
        perror("fail to fcntl");
        exit(1);
    }
    while (1)
    {
        sleep(5);
        addr_len = sizeof(cin);
        n = recvfrom(s_fd, buf, MAX_LINE, 0, (struct sockaddr *)&cin, &addr_len);
        if (n == -1 && errno != EAGAIN) {
            perror("fail to receive\n");
            exit(1);
        } else if (errno == EAGAIN) {
            printf("socket are not ready now\n");
        }
        inet_ntop(AF_INET, &cin.sin_addr, addr_p, sizeof(addr_p));
        printf("client IP is %s, port is %d\n", addr_p, ntohs(cin.sin_port));
        printf("content is : %s\n", buf);
        my_fun(buf);
        n = sendto(s_fd, buf, n, 0, (struct sockaddr *)&cin, addr_len);
        if (n == -1 && errno !=EAGAIN) {
            perror("fail to send\n");
            exit(1);
        } else if (errno == EAGAIN) {
            printf("socket are not ready now\n");
        }
    }
    if (close(s_fd) == -1) {
        perror("fail to close");
        exit(1);
    }

    return 0;
}
