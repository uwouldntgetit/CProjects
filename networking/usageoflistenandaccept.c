#include "header.h"

/* listen() accepts two parameters, a socket file descriptor and an int that signifies the backlog, or the maximum number of allowed connections on the incoming queue
   we need to call bind() before we can use listen() so that the server is running on a specific port. you also have to be able to tell to the hosts that want to 
   connect() with you which port to use.

   accept() is a little bit more complicated, when some host will try to connect() to your machine on a port you are listening on,
   their connection will be put in the backlog queue where they'll be waiting to be accept()ed. 
   if you call accept() and tell it to get the pending connection, it will return a new socket filedescriptor to use for this single connection, with which you can send() and recv()
   */

#define PORT_TO_USE "3490"
#define BACKLOG 20

int main(void){
    struct sockaddr_storage user_addr;
    // this data type is used for socket related parameters and is portable
    socklen_t addr_size;
    struct addrinfo hints, *res;
    int sockfd, temp_fd;

    // first load up  address struct with getaddrinfo()
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if(getaddrinfo(NULL, PORT_TO_USE, &hints, &res) < 0){
        fprintf(stderr, "getaddrinfo() error: %s\n", strerror(errno));
        exit(1);
    }

    // make a socket, bind it and listen on it
    if((sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) < 0){
        fprintf(stderr, "socket() error: %s\n", strerror(errno));
        exit(2);
    }
    if(bind(sockfd, res->ai_addr, res->ai_addrlen) < 0){
        fprintf(stderr, "bind() error: %s\n", strerror(errno));
        exit(3);
    }
    if(listen(sockfd, BACKLOG) < 0){
        fprintf(stderr, "listen() error: %s\n", strerror(errno));
        exit(3);
    }

    // now accepting any incoming connection
    addr_size = sizeof(user_addr);
    // user_addr is casted so it is usable with both ipv4 and ipv6
    temp_fd = accept(sockfd, (struct sockaddr *) &user_addr, &addr_size);
    
    if(temp_fd < 0){
        fprintf(stderr, "accept() error: %s\n", strerror(errno));
        exit(4);
    }
    
    
}
