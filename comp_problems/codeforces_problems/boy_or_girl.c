#include <stdio.h>
#include <string.h>


int main(void){
    char string[101], letter_check[27], *ptr;
    int counter = 0, position_arr =0;
    scanf("%100s", string);

    for(int j = 0; string[j]  != 0; j++){
        ptr = strchr(letter_check, string[j]);
        if(ptr == NULL){
            counter += 1;
            letter_check[position_arr] = string[j];
            position_arr++;
        }
    }

    if(counter % 2 == 0)
        printf("CHAT WITH HER!");
    else
        printf("IGNORE HIM!");

    return 0;
}
