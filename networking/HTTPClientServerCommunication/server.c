#include "header.h"

// this is an implementation of a server handling http/0.9 requests and responses

void *get_in_addr(struct sockaddr *s){
    if(s->sa_family == AF_INET){
        return &(((struct sockaddr_in*)s)->sin_addr);
    }
    return &(((struct sockaddr_in6*)s)->sin6_addr);
}

int main(int argc, char *argv){
    struct addrinfo hints, *server_info, *iterated;
    int sockfd, new_sockfd, gai_res;
    struct sockaddr_storage  client_addr;
    int yes = 1;
    socklen_t clientaddr_sz;
    char address_string[INET6_ADDRSTRLEN];

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_flags = AI_PASSIVE;
    hints.ai_socktype = SOCK_STREAM;

    // get network information about this device
    if((gai_res = getaddrinfo(NULL, COMM_PORT, &hints, &server_info)) != 0){
        fprintf(stderr, "getaddrinfo problem: %s", gai_strerror(gai_res));
        return 1;
    }

    for(iterated = server_info; iterated != NULL; iterated = iterated->ai_next){
        if((sockfd = socket(iterated->ai_family, iterated->ai_socktype, iterated->ai_protcol))!= 0){
            perror("error: socket creation");
            continue;
        }

        if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof yes) == -1){
            perror("error: setsockopt");
            continue;
        }

        if(bind(sockfd, (struct sockaddr *) iterated->ai_addr, sizeof iterated->ai_addr) != 0){
            perror("error: binding socket failed");
            continue;
        }
        // from here on out I was high
        break;
    }

    // I don't need it no more so I free it
    freeaddrinfo(server_info);

    if(iterated == NULL){
        perror("Server failed to bind");
        return 2;
    }

    if(listen(sockfd, BACKLOG) == -1){
        perror("Error when using listen()");
        return 3;
    }

    // now I add the part that listens to incoming connections, takes in http/0.9 requests and responds with the requested file
    while(1){
        clientaddr_sz = sizeof client_addr;
        new_sockfd = accept(sockfd, (struct sockaddr *) &client_addr, clientaddr_sz;
        if(new_sockfd == -1){
            perror("error while creating accept() socket");
            continue;
        }

        // client_addr isn't a pointer so since get_in_addr takes in a sockaddr pointer 
        // I had to cast its memory address as such, since that would be the value of one such
        // pointer
        inet_ntop(client_addr.ss_family, get_in_addr((struct sockaddr *)&client_addr, address_string, sizeof address_string);
        // %s takes in a char pointer
        printf("server: incoming connection from %s", address_string);

        if(fork() == 0){
        }

    }

}
