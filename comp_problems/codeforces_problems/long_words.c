#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOO_LONG 10

void abbreviate_word(char *);
int check_position(char *, char);
void get_string(char *);

int main(){
    int num_words;
    char word[100];
    scanf(" %d", &num_words);

    if(num_words == 0) return 0;
    
    while(num_words > 0){
        abbreviate_word(word);
        num_words--;
        printf("\n");
    }
    return 0;
}

void abbreviate_word(char *word){
    // get_string(word);
    scanf("%s", word);
    int length = strlen(word);
    if(length - 1 <= TOO_LONG){ 
        printf("%s", word);
        return;
    }

    word[1] = ((length - 3) / 10) + 48;
    word[2] = ((length - 3) % 10) + 48;
    word[3] = word[length - 2];
    word[4] = 0;
    
    printf("%s", word);
}

int check_position(char *string, char to_check){
    for(int i = 0; string[i] != 0; i++){
        if(string[i] == to_check) return i;
    }
    return 100;
}

void get_string(char *string){
    if(fgets(string, 100, stdin)){
        string[check_position(string, '\0')] = 0;
    }
}
