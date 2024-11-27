#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void delete(int *, int, int);

int main(void){
    int t, total_earn, size, *array, result, max, pos;

    assert(1 == scanf("%d", &t));

    for(int i = 0; i < t; i++){
        assert(2 == scanf("%d%d", &size, &total_earn));
        array = malloc(sizeof(int) * size);
        result = size;

        for(int k = 0; k < size; k++){
            assert(1 == scanf("%d", array + k));
        }

        while(total_earn > 0 && size > 0){
            max = 0;
            pos = -1;
            for(int a = 0; a < size; a++){
                if(array[a]  > max){
                    max = array[a];
                    pos = a;
                }
            }
            total_earn -= max;
            delete(array, size, pos);
            size--;
        }
        
        result = size;

        printf("%d\n", result);
    }

}

void delete(int *array, int size, int pos){
    while(pos < size - 1){
        array[pos] = array[pos + 1];
        pos++;
    }
}
