// making a cheap clone of the ls command
// 

#include "header.h"

// function to eliminate a character in a string
void eliminateChar(char* string, int position){
    for(int i = position; string[i] != 0; i++){
        string [i] = string [i + 1];
    }
}

// this function prints all the files in the current directory with filenames not starting with a '.' character
void noArguments(DIR* directory){
    struct dirent* currFile;
    // this operation is like this because when there is an error or all the files have been listed, the function returns NULL
    while((currFile = readdir(directory)) != NULL){
        if(currFile->d_name[0] == '.')
            continue;
        else
            printf("%s\t", currFile->d_name);
    }
    printf("\n");
}

void useArguments(DIR* directory, char* args){
    // file statistics
    struct stat fs;
    struct dirent* currFile;

    // first thing to do is to checkif the -a option was enabled, so that then i can directly pass the set of files to analyze to the following functions
    if(strlen(args) > 3){
        fprintf(stderr, "The options inserted are invalid, read the info.txt file to know more about the available options\n");
        return;
    }

    if(args[0] != '-' || wrongOption(args)){
        fprintf(stderr, "Incorrect usage of options, read the info.txt for information about acceptable options\n");
        return;
    }
    
    while((currFile = readdir(directory)) != NULL){
        // if the option a isn't include and the file is hidden, it skips to the next one
        if(!inString(args, 'a') && currFile->d_name[0] == '.')
            continue;

        if(inString(args, 'l')){
            if(stat(currFile->d_name, &fs) != -1){
                // file_type, file_length, file_last_write, file_name
                printf("%s\t%ld\t%s\t%s\n", fileType(fs), fs.st_size, convertTime(&fs.st_mtime), currFile->d_name);
            }else{
                fprintf(stderr, "Impossible to obtain information about the file: %s\n", currFile->d_name);
                return;
            }
        }else printf("%s\t", currFile->d_name);
    }

}

// this function converts the long int given by st_mtime into a string. people on stackoverflow say that this implementation is thread safe, but the manual page says it isn't 
// and to simply use strftime(). i just checked and other sites also say that this is MT-unsafe (multi thread unsafe).
char *convertTime(time_t *x){
    static char timeString[MAX_TIME_LENGTH];
    struct tm *tmp;

    if((tmp = localtime(x)) == NULL){
        perror("ERROR");
        exit(EXIT_FAILURE);
    }

    if(strftime(timeString, MAX_TIME_LENGTH, "%x", tmp) == 0){
        fprintf(stderr, "ERROR: MAX_TIME_LENGTH exceeded, it is advised to change the value of the constant\n");
        exit(EXIT_FAILURE); 
    }

    return timeString;

}

// this function checks if a wrong option was inserted
_Bool wrongOption(char* string){
    for(int i = 1; string[i] != 0; i++){
        if(string[i] != 'a' && string[i] != 'l') return true;
    }
    return false;
}

_Bool inString(char* string, char check){
    for(int i = 0; string[i] != 0; i++){
        if(string[i] == check) return true;
    }
    return false;
}

// this functon determines the type of a file through the usage of some predicate macros
// even if this function isn't the most elegant, it still does its job, and pretty fast too, so until i find a better way, there's no need to lose too much time on it
char* fileType(struct stat fs){
    if(S_ISREG(fs.st_mode))
        return "regular";
    if(S_ISDIR(fs.st_mode))
        return "dir";
    if(S_ISLNK(fs.st_mode))
        return "link";
    if(S_ISCHR(fs.st_mode))
        return "chr_special";
    if(S_ISBLK(fs.st_mode))
        return "blk_special";
    if(S_ISFIFO(fs.st_mode))
        return "FIFO";
    if(S_ISSOCK(fs.st_mode))
        return "socket";
    return "unknown";
}

