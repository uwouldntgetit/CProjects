#include "header.h"

int main(int argc, char** argv){
    DIR* directory;
    struct dirent* currFile;
    // here i made sure that the path inserted is absolute using the realpath() function for safety reason with the opendir() function
    // char* dirname = realpath(argv[1], NULL);
    // this piece of code is unsafe because if the path doesn't exist, the function returns NULL and then the program goes in segfalut

    // this is how it should be done
    char* dirname;

    if((dirname = realpath(argv[1], NULL)) ==  NULL){
        perror("ERROR");
        return -1;
    }

    if(argc < 2){
        fprintf(stderr, "ERROR: correct use of the program is: %s <path> <options>\n", argv[0]);
        return -1;
    }

    if((directory = opendir(dirname)) == NULL){
        perror("ERROR");
        return -1;
    }

    if(argc == 2){
        noArguments(directory);
    }else
        useArguments(directory, argv[2]);

    closedir(directory);

    return 0;
}
