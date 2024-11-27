#include "header.h"

// once you have a socket you might have to associate it with a port on your machine. this port number is used by the kernel
// to match an incoming packet to a certain process' socket descriptor. This is used by server to differentiate packets

int main(void){
    struct addrinfo hints, *result;
    int sck_fd, status;

    memset(hints, 0, sizeof(hints));
    // to make it usable with both ipv4 and ipv6
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    // it automatically fills in my ip
    hints.flags = AI_PASSIVE;

    if((status = getaddrinfo(NULL, "3490", &hints, &result)) != 0){
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        exit(1);
    }

    sck_fd = socket(res->ai.family, res->ai_socktype, res->ai_protocol);
    if(sck_fd < 0){
        fprintf(stderr, "socket() error: %s\n", strerror(errno));
        exit(2);
    }

    // it binds the socket with the port passed in getaddrinfo()
    bind(sck_fd, res->ai_addr, res->ai_addrlen);
}
