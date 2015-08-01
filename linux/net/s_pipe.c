// s_pipe.c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#define MAX 100
int main()
{
    int sockfd[2];
    pid_t pid;
    char buf[MAX];
    int n;
    if (socketpair(AF_UNIX, SOCK_STREAM, 0, sockfd) == -1) {
        perror("fail to create socket");
        exit(1);
    }
    pid = fork();
    if (pid < 0) {
        perror("fail to fork");
        exit(1);
    } else if (pid == 0) {
        close(sockfd[0]);
        strcpy(buf, "hello parent");
        n = strlen(buf);
        if (write(sockfd[1], buf, n) == -1) {
            perror("fail to write");
            exit(1);
        }
        printf("the child done\n");
    } else {
        close(sockfd[1]);
        if (read(sockfd[0], buf, MAX) == -1) {
            perror("fail to read");
            exit(1);
        }
        n = strlen(buf);
        buf[n] = '\0';
        printf("recive from child : %s\n", buf);
        if (wait(NULL) == -1) {
            perror("fail to wait");
            exit(1);
        }
        printf("the parent done\n");
    }

    return 0;
}
