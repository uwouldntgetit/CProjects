#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>

// this program was made to show how to use the socket() system call so i didn't do any error checking
// socket() return to you a socket descriptor,or -1 on error. this socket by itslef is useless, and you have to make more system calls for it to make sense
// after this read the file usageofbind.c

int main(void){
    int socket;
    struct addrinfo hints, *res;

    memset(hints, 0, sizeof(hints));
    hints.ai_family = AF_INET6;
    hints.ai_socktpe = SOCK_STREAM;

    getaddrinfo("www.google.com", "http", &hints, &res);

    // here i assumed the first result of res was valid
    // the socket created isn't specifically reserved for a connection with google.com, but with all the servers of the same type like
    // with the same ip version, the same socket type and the same protocol
    socket = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

    return 0;
}
