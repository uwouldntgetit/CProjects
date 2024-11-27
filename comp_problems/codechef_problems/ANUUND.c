#include <stdio.h>
#include <stdlib.h>

int main(void){
    int t, size, *array, temp;
    scanf("%d", &t);

    while(t--){
        scanf("%d", &size);
        array = malloc(sizeof(int) * size);

        for(int i = 0; i < size; i++){
            scanf("%d", &array[i]);
        }
        

        for(int i = 0; i < size; i++){
            for(int k = i + 1; k < size; k++){
                if(i % 2 == 0 && array[k] < array[i]){
                    temp = array[i];
                    array[i] = array[k];
                    array[k] = array[i];
                }
                else if(i % 2 == 1 && array[k] > array[i]){
                    temp = array[i];
                    array[i] = array[k];
                    array[k] = array[i];
                }
            }
            printf("%d ", array[i]);
        }
        printf("\n");
        free(array);
    }
    return 0;
}
