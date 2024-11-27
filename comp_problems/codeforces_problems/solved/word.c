#include <stdio.h>
#include <ctype.h>

int main(void){
    char string[101];
    int up_count = 0, low_count = 0;
    int (*ptr)(int);

    scanf(" %100[^\n]", string);

    for(int i = 0; string[i] != 0; i++){
        if(islower(string[i]) == 0){
            up_count++;
        } else{
            low_count++;
        }
    }
    if(up_count > low_count)
        ptr = toupper;
    else
        ptr = tolower;

    for(int i = 0; string[i] != 0; i++){
        string[i] = ptr(string[i]);
    }

    printf("%s", string);

    return 0;
}
