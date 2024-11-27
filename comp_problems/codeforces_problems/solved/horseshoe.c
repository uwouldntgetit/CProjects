#include <stdio.h>
#include <stdlib.h>

int main(void){
    int *array = malloc(sizeof(int) * 4);
    int result = 0;
    
    for(int i = 0; i < 4; i++){
        scanf("%d", array + i);
    }

    for(int i = 0; i < 4; i++){
        if(array[i] == '*') 
            continue;
        for(int k = i + 1; k < 4; k++){
            if(array[k] == '*')
                continue;
            else if(array[i] == array[k]){
                array[k] = '*';
                result ++;
            }
        }
    }
    printf("%d\n", result);

    free(array);
}
