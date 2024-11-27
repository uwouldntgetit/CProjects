#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_string(int length_string, char *string){
    fgets(string, length_string, stdin);
    string[strcspn(string, "\n")] = '\0';
}
