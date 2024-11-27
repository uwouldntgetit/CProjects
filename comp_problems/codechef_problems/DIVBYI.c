#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>

// a permutation of length N is an array where every integer from 1 to N occurs exactly once
// i'm almost there

int main(void){
    int t, num, *array;

    assert(1 == scanf("%d", &t));

    for(int k = 0; k < t; k++){
        assert(1 == scanf("%d", &num));
        if((array = malloc(sizeof(int) * num)) == NULL){
            perror("malloc malfunctioned\n");
            break;
        }
        array[0] = 1;

        for(int i = 1; i < num; i++){
            array[i] = array[i - 1] - i;
        }

        for(int i = 0; i < num; i++){
            printf("%d ", array[i]);
        }

        printf("\n");
    }
    free(array);

}
