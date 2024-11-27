#include "header.h"

int main(int argc, char **argv){
    struct sockaddr_in sa;
    // INET_ADDRSTRLEN is a constant that defines the length of an ipv4 address
    char ip4[INET_ADDRSTRLEN];

    if(inet_pton(AF_INET, "192.168.24.2", &(sa.sin_addr)) < 1)
        perror("problem with inet_pton\n");

    inet_ntop(AF_INET, &(sa.sin_addr), ip4, INET_ADDRSTRLEN);

    printf("Address: %s\n", ip4);
    
    return 0;
}
