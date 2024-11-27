#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LENGTH 100

void get_string(char *string);
int string_length(char *string);

int main(){
    char *string = malloc(LENGTH);
    printf("Input string: ");
    get_string(string);
    printf("The length of the string is: %d\n", string_length(string));

    return 0;
}

void get_string(char *string){
    if(fgets(string, LENGTH, stdin)){
        string[strcspn(string, "\n")] = '\0';
    }
}

int string_length(char *string){
    int counter = 0;
    for(int i = 0; string[i] != '\0'; i++){
        counter++;
    }
    return counter;
}
