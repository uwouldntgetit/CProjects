#include <stdio.h>
#include <string.h>
#include <assert.h>

int main(void){
    int t;
    char string[100001];

    assert(1 == scanf("%d", &t));

    for(int i = 0; i < t; i++){
        assert(1 == scanf("%s", string));

        for(int k = 0; k < strlen(string); k++){
            if(string[k] == 'p' && string[k + 1] == 'a' && string[k + 2] == 'r' && string[k + 3] == 't' && string[k + 4] == 'y'){
                string[k + 2] = 'w';
                string[k + 3] = 'r';
                string[k + 4] = 'i';
            }
        }
        printf("%s\n", string);
    }
}
