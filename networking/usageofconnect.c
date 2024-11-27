#include "header.h"

int main(void){
    struct addrinfo hints, *res;
    int sockfd;

    memset(&hints, 0, sizeof(hints));
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    hints.ai_family = AF_UNSPEC;


    if(getaddrinfo("www.example.com", "3490", &hints, &res) > 0){
        fprintf(stderr, "getaddrinfo() errorr: %s\n", strerror(errno));
        exit(1);
    }

    // it creates a socket to connect to www.example.com
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if(sockfd < 0){
        fprintf(stderr, "socket creation error: %s\n", strerror(errno));
        exit(2);
    }


    if(connect(sockfd, res->ai_addr, res->ai_addrlen) < 0){
        fprintf(stderr, "socket connection error: %s\n", strerror(errno));
        exit(3);
    }
    
}
