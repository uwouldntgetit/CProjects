#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 101

int main(void){
    char string1[MAX_SIZE], string2[MAX_SIZE];
    int result, string1_value = 0, string2_value = 0;

    scanf(" %100[^\n]", string1);
    scanf(" %100[^\n]", string2);

    for(int i = 0; string1[i] != '\0'; i++){
        string1[i] = toupper(string1[i]);
        string1_value += string1[i];
    }

    for(int i = 0; string2[i] != '\0'; i++){
        string2[i] = toupper(string2[i]);
        string2_value += string2[i];
    }

    result = string1_value - string2_value;
    if(result > 0) result = 1;
    if(result < 0) result = -1;

    printf("%d", result);


    return 0;
}
