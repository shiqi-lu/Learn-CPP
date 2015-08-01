// client4.c
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/un.h>
#define PATH "/tmp/connect.socket"
#define C_PATH "/tmp/"
#define MAX 1024
int main()
{
    int cfd, len;
    struct sockaddr_un un_addr;
    char buf[MAX];
    if ((cfd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
        perror("fail to create socket");
        exit(1);
    }
    memset(&un_addr, 0, sizeof(struct sockaddr_un));
    un_addr.sun_family = AF_UNIX;
    sprintf(un_addr.sun_path, "%s%d", C_PATH, getpid());
    len = offsetof(struct sockaddr_un, sun_path) + strlen(un_addr.sun_path);
    unlink(un_addr.sun_path);
    if (bind(cfd, (struct sockaddr *)&un_addr, len) == -1) {
        perror("fail to bind");
        exit(1);
    }
    if (chmod(un_addr.sun_path, S_IRWXU) < 0) {
        perror("fail to change model");
        exit(1);
    }
    memset(&un_addr, 0, sizeof(struct sockaddr_un));
    un_addr.sun_family = AF_UNIX;
    strcpy(un_addr.sun_path, PATH);
    len = offsetof(struct sockaddr_un, sun_path) + strlen(un_addr.sun_path);
    if (connect(cfd, (struct sockaddr *)&un_addr, len) < 0) {
        perror("fail to connect");
        exit(1);
    }
    strcpy(buf, "China");
    if (write(cfd, buf, strlen(buf) + 1) == -1) {
        perror("fail to write");
        exit(1);
    }
    if (read(cfd, buf, MAX) == -1) {
        perror("fail to read");
        exit(1);
    }
    printf("receive from server: %s\n", buf);
    close(cfd);

    return 0;
}
