#include <stdio.h>
#include <stdlib.h>

int main(void){
    int times, num, *array, max, maxTemp;
    scanf("%d", &times);

    for(int i = 0; i < times; i++){
        scanf("%d", &num);
        array = malloc(num * sizeof(int));
        max = 0;

        for(int k = 0; k < num; k++){
            scanf("%d", array + k);
        }

        for(int k = 0; k < num; k++){
            for(int j = 0 ; j < num; j++){
                if(array[k] == array[j])
                    maxTemp++;
            }

            if(maxTemp > max){
                max = maxTemp;
            }
            maxTemp = 0;
        }
        printf("%d\n", num - max);


        free(array);
    }
    return 0;
}
