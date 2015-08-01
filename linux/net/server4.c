// server4.c 
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/stat.h>
#include <stddef.h>
#include <time.h>
#define PATH "/tmp/connect.socket"
#define STALE 30
#define MAX 1024
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

int init(int * lfd, char * path)
{
    int fd, len;
    struct sockaddr_un un_addr;
    if ((fd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
        perror("fail to create socket");
        return -1;
    }
    unlink(PATH);
    memset(&un_addr, 0, sizeof(un_addr));
    un_addr.sun_family = AF_UNIX;
    strcpy(un_addr.sun_path, path);
    len = offsetof(struct sockaddr_un, sun_path) + strlen(path);
    if (bind(fd, (struct sockaddr *)&un_addr, len) == -1) {
        perror("fail to bind");
        goto err;
    }
    if (listen(fd, 10) == -1) {
        perror("fail to listen");
        goto err;
    }
    *lfd = fd;
    return 0;
err:
    close(fd);
    return -1;
}

int main()
{
    int lfd, cfd;
    time_t staletime;
    struct sockaddr_un un_addr;
    struct stat statbuf;
    char buf[MAX];
    int len, n;
    if (init(&lfd, PATH) == -1) {
        exit(1);
    }
    while (1)
    {
        len = sizeof(struct sockaddr_un);
        if ((cfd = accept(lfd, (struct sockaddr *)&un_addr, &len)) == -1) {
            perror("fail to accept");
            exit(1);
        }
        len -= offsetof(struct sockaddr_un, sun_path);
        un_addr.sun_path[len] = '\0';
        if (stat(un_addr.sun_path, &statbuf) == -1) {
            perror("fail to get status");
            exit(1);
        }
        if ((statbuf.st_mode & (S_IRWXG | S_IRWXO)) || (statbuf.st_mode & S_IRWXU) != S_IRWXU) {
            printf("wrong permissions\n");
            exit(1);
        }
        staletime = time(NULL) - STALE;
        if (statbuf.st_atime < staletime || statbuf.st_ctime < staletime || statbuf.st_mtime < staletime) {
            printf("client is too old\n");
            close(cfd);
            break;
        }
        
        if (unlink(un_addr.sun_path) == -1) {
            perror("fail to unlink");
            exit(1);
        }
        if (read(cfd, buf, MAX) == -1) {
            perror("fail to read");
            exit(1);
        }
        my_fun(buf);
        if (write(cfd, buf, n) == -1) {
            perror("fail to write");
            exit(1);
        }
        close(cfd);
    }
    if (unlink(PATH) == -1) {
        perror("fail to unlink");
        exit(1);
    }
    close(lfd);
    return 0;
}
