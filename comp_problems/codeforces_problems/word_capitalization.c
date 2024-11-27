#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 1001

int main(void){
    char string[MAX_LENGTH];

    scanf(" %1000[^\n]", string);
    
    if(isupper(string[0]) != 0){
        printf("%s", string);
        return 0;
    }

    for(int i = 0; string[i] != 0; i++){
        if(islower(string[i]) == 0) string[i] = tolower(string[i]);
    }

    if(islower(string[0]) != 0) string[0] = toupper(string[0]);

    printf("%s", string);

    return 0;
}
