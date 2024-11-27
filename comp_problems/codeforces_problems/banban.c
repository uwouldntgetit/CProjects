#include <stdio.h>
#include <stdlib.h>

int main(void){
    int times, length, odd;

    scanf("%d", &times);
    for(int i = 0; i < times; i++){
        scanf("%d", &length);
        odd = 1;
        if(length % 2 == 0) odd = 0;

        for(int k = 0; k < length - odd; k += 2){
            printf("%d %d ", (k * 3) + 1, (k * 3) + 5);
        }

        if(odd == 1)
            printf("%d %d", (length * 3) - 1, length * 3);

        printf("\n");

    }
}
