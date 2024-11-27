#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main(void){
    int numStrings, numSubstrings, check;
    char **substrings, **strings;

    assert(2 == scanf("%d%d", &numStrings, &numSubstrings));
    
    strings = malloc(numStrings * sizeof(char *));
    substrings = malloc(numSubstrings * sizeof(char *));

    for(int i = 0; i < numStrings; i++){
        strings[i] = malloc(sizeof(char) * 51);
        scanf("%s", strings[i]);
    }

    for(int i = 0; i < numSubstrings; i++){
        substrings[i] = malloc(sizeof(char) * 51);
        scanf("%s", substrings[i]);
    }

    for(int i = 0; i < numSubstrings; i++){
        check = 0;
        if(strlen(substrings[i]) >= 47){
            printf("Good\n");
            continue;
        }
        for(int k = 0; k < numStrings; k++){
            if(strstr(substrings[i], strings[k]) != NULL){
                check = 1;
                break;
            }
        }
        printf("%s\n", check == 1 ? "Good" : "Bad");
    }

    free(strings);
    free(substrings);

}
