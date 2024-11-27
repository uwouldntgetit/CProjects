#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void){
    int num_magnets, magnet = 0, swap = 0, result = 0;

    scanf("%d", &num_magnets);

    for(int i = 0; i < num_magnets; i++){
        scanf("%d", &magnet);
        if(magnet != swap) result++;
        swap = magnet;
    }

    printf("%d", result);

    return 0;
}
