#include <stdio.h>
#include <stdlib.h>
// #include "basic_functions_header.h"
// program to find the reverse of a string

void reverse(char *string);
void input_string(char *string, int length);

int main(void){
    char *string;
    int length;
    printf("input length string: ");
    scanf(" %5d", &length);
	printf("string inputted\n");
    string = malloc(length);
	printf("Input string: ");
    input_string(string, length);
    // get_string(length, string);
	printf("get_string used\n");
    reverse(string);
	printf("reverse done\n");
    printf("%s\n", string);

    return 0;
}

// function to reverse a given string
void reverse(char *string){
    int counter = 0;
    // finding the real string legnth, since i dont trust the user to write a string as long as the given length
    while(string[counter] != '\0'){
        counter++;
    }
    //counter /= 2;
    // swapping the two opposite characters
    for(int i = 0; i < counter; i++){
        char swap = string[i];
        string[i] = string[counter];
        string[counter] = swap;
        counter--;
    }
}

void input_string(char *string, int length){
    for(int i = 0; i < length; i++){
        scanf(" %c", &string[i]);
    }
}
