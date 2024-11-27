#include "header.h"

// in this progrram I setup a server that listen and accepts incoming communications on the port 3490

int main(int argc, char *argv){
    struct sockaddr_storage client_addr;
    socklen_t client_size;
    struct addrinfo hints, *res;
    int sockfd, secondary_sockfd;
    char *msg = "Hi, I'm Federico, a great guy, nice to meet you! I really have to say you have very good taste in terms of shirts, the quality is just unreal!";

    memset(&hints, 0, sizeof hints);
    hints.ai_flag = AI_PASSIVE;
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    getaddrinfo(NULL, "3490", &hints, &res);
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    bind(sockfd, res->ai_addr, sizeof res->ai_addr);
    listen(sockfd, 20);

    client_size = sizeof client_addr;
    // client_addr contains the address of the sender that is returned through accept() 
    secondary_sockfd = accept(sockfd, &client_addr, &client_size);

    // doesn't allow communications on this socket anymore
    close(secondary_sockfd);
}
