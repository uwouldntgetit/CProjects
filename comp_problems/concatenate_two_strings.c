#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "basic_functions_header.h"
// program to concatenate two strings using pointers
// there's a bug for which if i input more letters than allowed, they are still concatenated in the final string, and the last letters of the second string
// are cancelled as many as teh letters in excess of the first string

void concatenate_strings(char *s1, char *s2, char *final_s);
void get_string(int length, char *string);

int main(void){
    char *string1, *string2, *final_string;
    int length;
    printf("Input the length of the strings: ");
    scanf(" %5d", &length);
    string1 = (char *) malloc(length);
    string2 = (char *) malloc(length);
    final_string = (char *) malloc(length * 2);

    printf("Insert the first string: ");
    get_string(length, string1);
    printf("Insert the second string: ");
    get_string(length, string2);
    concatenate_strings(string1, string2, final_string);
    printf("The concatenated string is: ");
    for(int i = 0; final_string[i] != '\0'; i++){
        printf("%c", final_string[i]);
    }
    printf("\n");

    free(string1);
    free(string2);
    free(final_string);

    return 0;
}

void concatenate_strings(char *string1, char *string2, char *final_string){
    int counter = 0, counter2 = 0;
    while(string1[counter] != '\0'){
        final_string[counter] = string1[counter];
        counter++;
    }

    final_string[strcspn(final_string, "\0")] = ' ';
    while(string2[counter2] != '\0'){
        final_string[counter] = string2[counter2];
        counter++;
        counter2++;
    }
}

void get_string(int length, char *string){
    for(int i = 0; i < length; i++){
        scanf(" %c", &string[i]);
    } 
}
