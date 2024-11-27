#include <stdio.h>

int main(void){
    char string[21];
    int lucky_counter = 0;

    scanf(" %19[^\n]", string);

    for(int i = 0; string[i] != 0; i++){
        if(string[i] == '7' || string[i] == '4') lucky_counter++;
    }

    if(lucky_counter == 7 || lucky_counter == 4){
        printf("YES");
    } else{
        printf("NO");
    }

    return 0;
}
