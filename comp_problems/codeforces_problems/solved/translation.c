#include <stdio.h>
#include <string.h>

int main(){
    char first_word[101], second_word[101], counter = 0;

    scanf(" %100[^\n]", first_word);
    scanf(" %100[^\n]", second_word);

    int length = strlen(second_word);
    int j = length - 1;

    for(int i = 0; i < length; i++){
        if(first_word[i] != second_word[j]){
            counter++;
        }
        
        j--;
    }

    if(counter == 0){
        printf("YES");
    }else{
        printf("NO");
    }

    return 0;
}
