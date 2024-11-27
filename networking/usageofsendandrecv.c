#include "header.h"

/*
   send() and recv() are for communication over stream sockets or unconnected datagram sockets. 
*/

int main(void){
    char *message = "hello!\n";
    char *buffer;
    // length of the message, variable to hold the return of send()
    int len, bytes_sent, sockfd, bytes_read;

    // initialize everything

    // send mesage, 0 are the flags
    // send als returns the number of bytes actually sent out
    bytes_sent = send(sockfd, message, len, 0);

    // buffer is where the informations are stored and len is the length of the buffer
    // if recv() returns 0 it means that the computer you were connect()ed to has closed the connection
    bytes_read = recv(sockfd, buffer, len, 0);
    
}
