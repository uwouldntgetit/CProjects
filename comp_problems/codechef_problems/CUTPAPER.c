#include <stdio.h>

int main(void){
    int chartSide, squareSide, times, result;

    scanf("%d", &times);

    for(int i = 0; i < times; i++){
        scanf("%d%d", &chartSide, &squareSide);
        
        result = chartSide / squareSide;
        result *= result;
        printf("%d\n", result);
    }

    return 0;
}
