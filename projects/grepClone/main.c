// since i got some problems due to the automatic word expansion and all of that shit, the program will simply search for the occurrences of a pattern in a file and print the lines that match it
#include "header.h"

int main(int argc, char **argv){
    FILE *file;
    char line[MAX_LINE_LENGTH], ret[MAX_LINE_LENGTH];
    
    FAIL_IF_MSG(argc < 3, ("Correct usage: %s <pattern> <filename>\n", argv[0]));
    
    FAIL_IF_PERROR((file = fopen(argv[2], "r")) == NULL);

    while(feof(file) != 0){
        fgets(line, MAX_LINE_LENGTH - 1, file);
        // i'm pretty sure that fgets can't fail with these conditions, but just in case i'll check it, maybe there was something like ctrl-d
        FAIL_IF_MSG(*line == NULL, "Error when reading from file\n");

        ret = strstr(line, argv[1]);
        if(*ret != NULL)
            printf("%s", line);
    }
    

    fclose(file);
    return 0;
}
