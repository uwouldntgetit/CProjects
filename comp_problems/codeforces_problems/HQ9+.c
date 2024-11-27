
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
    char *string;

    string = malloc(sizeof(char) * 101);
    scanf("%s", string);

    for(int i = 0; i < 100; i++){
        if(string[i] == 'H' || string[i] == 'Q' || string[i] == '9'){
            printf("YES\n");
            return 0;
        }
    }

    printf("NO\n");
    return 0;
}
