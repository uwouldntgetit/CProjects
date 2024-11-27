#include "header.h"

// this program shows the ip address of an host given by the command line

int main(int argc, char **argv){
    struct addrinfo hints, *res, *p;
    int status;
    char ipstr[INET6_ADDRSTRLEN];

    if(argc != 2){
        perror("Usage: showip hostname\n");
        exit(1);
    }

    if(memset(&hints, 0, sizeof(hints)) == NULL){
        perror("memset error\n");
        exit(1);
    }
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if((status = getaddrinfo(argv[1], NULL, &hints, &res)) != 0){
        fprintf(stderr, "getaddrinfo() error: %s\n", gai_strerror(status));
        exit(2);
    }

    printf("IP addresses for %s:\n", argv[1]);

    // here i have to use a pointer to a struct because i can't make an element of a struct = to another since they aren't ints or floats
    // but i have to copy the address, otherwise i have to copy all the fields one by one
    for(p = res; p != NULL; p = p->ai_next){
        void *addr;
        char *ipver;

        if(p->ai_family == AF_INET){
            // ai_addr is of type struct sockaddr so it can be freely casted back and forth
            struct sockaddr_in *ipv4 = (struct sockaddr_in *) p->ai_addr;
            addr = &(ipv4->sin_addr);
            ipver = "IPv4";
        }
        else{
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
