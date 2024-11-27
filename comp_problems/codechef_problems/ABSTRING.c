#include <stdio.h>
#include <stdlib.h>

int main(void){
    int times, length, counter, check;
    char* string;

    scanf("%d", &times);

    for(int i = 0; i < times; i++){
        scanf("%d", &length);
        string = malloc(sizeof(char) * length);
        scanf("%s", string);
        check = 0;

        if(length % 2 != 0){
            printf("NO\n");
            continue;
        }

        for(int k = 0; k < length; k++){
            counter = 0;
            for(int s = 0; s < length; s++){
                if(string[k] == string[s]) counter++;
            }
            if(counter % 2 != 0){
                printf("NO\n");
                check = 1;
                break;
            }
        }

        if(check == 0) printf("YES\n");


        free(string);
    }
}
