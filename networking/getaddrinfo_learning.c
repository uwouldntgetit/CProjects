#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// this function is used to set up the functions you'll need later on
// you give the function three input parameters and it gives you back a pointer to a linked list of results

// this is a sample call for a server to setup all the necessary structs to listen to your host's IP address, port 3490

int main(void){
    int status;
    struct addrinfo hints;
    // pointer for the linked list of results
    struct addrinfo *servinfo;

    // this makes sure the struct is empty
    memset(&hints, 0, sizeof hints);
    // ipv4 or ipv6 unspecified
    hints.ai_family = AF_UNSPEC;
    // TCP stream sockets
    hints.ai_socktype = SOCK_STREAM;
    // fills in my IP automatically
    hints.ai_flags = AI_PASSIVE;

    if((status = getaddrinfo(NULL, "3490", &hints, &servinfo)) != 0){
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        exit(1);
    }

    // servinfo now points to a linked list of 1 or more structs addrinfo

    freeaddrinfo(servinfo);
}
