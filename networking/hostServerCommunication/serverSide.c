#include "header.h"

// this is a rudimentary serverside backend of an exchange of information between server and host

#define PORT_USED 6969
#define BACKLOG 20
#define STD_LENGTH 1024

int main(void){
    int sockfd, newsockfd, byte_sent, byte_recvd;
    struct addrinfo hints, *servaddr;
    struct sockaddr_storage *user_addr;
    socklen_t addrlen;
    char message[1024], buffer[1024];

    if(memset(&hints, 0, sizeof(hints)) == NULL){
        fprintf(stderr, "memset error\n");
        exit(1);
    }
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if(getaddrinfo(NULL, PORT_USED, &hints, &servaddr) < 0){
        fprintf(sderr, "getaddrinfo() error: %s\n", sterror(errno));
        exit(2);
    }

    // make a socket, bind it and then listen on it
    if((sockfd = socket(servaddr->ai_family, servaddr->ai_socktype, servaddr->ai_protocol)) < 0){
        fprintf(stderr, "socket() error: %s\n", strerror(errno));
        exit(3);
    }
    if(bind(sockfd, servaddr->ai_addr, servaddr->ai_addrlen) < 0){
        fprintf(stderr, "bind() error: %s\n", strerror(errno));
        exit(4);
    }
    if(listen(sockfd, BACKLOG) < 0){
        fprintf(stderr, "listen() error: %s\n", strerror(errno));
        exit(5);
    }

    addrlen = sizeof(user_addr);
    newsockfd = accept(sockfd, (sockaddr *) &user_addr, &addrlen);

    if(newsockfd < 0){
        fprintf(stderr, "accept() error: %s\n", strerror(errno));
        exit(6);
    }

    byte_sent = send(newsockfd, "Connection initiated\n", STD_LENGTH, 0);
    byte_recvd = recv(newsockfd, buffer, STD_LENGTH, 0);

    while(byte_recvd != 0){
        byte_recvd = recv(newsockfd, buffer, STD_LENGTH, 0);
        printf("%s", buffer);

    }
    printf("Connection terminated\n");

    return 0;
}
