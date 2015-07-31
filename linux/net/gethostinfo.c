// gethostinfo.c
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#define NET_ADDR 16
int main()
{
    struct hostent * host;
    char addr_p[NET_ADDR];
    int i;
    if ((host = gethostent()) == NULL) {
        perror("fail to get host's information\n");
        exit(1);
    }
    printf("%s\n", host->h_name);
    for (i = 0; host->h_aliases[i] != NULL; ++i) {
        printf("%s\n", host->h_aliases[i]);
    }
    if (host->h_addrtype == AF_INET) {
        printf("af_inet\n");
    } else {
        printf("unix_inet\n");
    }
    printf("%d\n", host->h_length);
    for (i = 0; host->h_addr_list[i] != NULL; ++i) {
        printf("%s\n", inet_ntop(host->h_addrtype, host->h_addr_list[i], addr_p, NET_ADDR));
    }

    return 0;
}
