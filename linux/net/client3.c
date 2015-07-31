// client3.c 
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <stdlib.h>
#define MAX_LINE 80
int main()
{
    struct sockaddr_in sin;
    struct sockaddr_in cin;
    int port = 8000;
    socklen_t addr_len;
    int s_fd;
    char buf[MAX_LINE];
    char addr_p[INET_ADDRSTRLEN];
    int n;
    bzero(&sin, sizeof(sin));
    sin.sin_family = AF_INET;
    inet_pton(AF_INET, "127.0.0.1", &sin.sin_addr);
    sin.sin_port = htons(port);
    s_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (s_fd == -1) {
        perror("fail to create socket");
        exit(1);
    }
    if (fgets(buf, MAX_LINE, stdin) == NULL) {
        perror("fail to get a line");
        exit(1);
    }
    n = sendto(s_fd, buf, strlen(buf) + 1, 0, (struct sockaddr *)&sin, sizeof(sin));
    if (n == -1) {
        perror("fail to send");
        exit(1);
    }
    addr_len = sizeof(cin);
    n = recvfrom(s_fd, buf, MAX_LINE, 0, (struct sockaddr *)&cin, &addr_len);
    if (n == -1) {
        perror("fail to receive");
        exit(1);
    } else {
        printf("receive from server: %s\n", buf);   
    }

    if (close(s_fd) == -1) {
        perror("fail to close");
        exit(1);
    }

    return 0;
}

