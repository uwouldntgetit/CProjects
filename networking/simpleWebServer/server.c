#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(int argc, char **argv){
    struct addrinfo hints, *res, *p;
    int status;
    char ipstr[INET6_ADDRSTRLEN];

    if(argc != 2){
        printf("Usage: program_name address\n");
        return 1;
    }

    memset(&hints, 0, sizeof(hints));
    // can be ipv4 and ipv6
    hints.ai_family = AF_UNSPEC;
    // TCP
    hints.ai_socktype = SOCK_STREAM;

    if((status = getaddrinfo(argv[1], NULL, &hints, &res)) != 0){
        fprintf(stderr, "ERROR: getaddrinfo -> %s\n", gai_strerror(status));
        return 2;
    }

    printf("IP addresses of %s:\n", argv[1]);

    for(p = res; p != NULL; p = p->ai_next){
        void *addr;
        char *ipver;

        if(p->ai_family == AF_INET){
            struct sockaddr_in *ipv4 = (struct sockaddr_in *) p->ai_addr;
            addr = &(ipv4->sin_addr);
            ipver = "IPv4";
        }
        else {
            struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *) p->ai_addr;
            addr = &(ipv6->sin6_addr);
            ipver = "IPv6";
        }

        inet_ntop(p->ai_family, addr, ipstr, sizeof(ipstr));
        printf("%s: %s\n", ipver, ipstr);
    }

    freeaddrinfo(res);

    return 0;
}
