#include <stdio.h>

int main(void){
    int times, x, y, result;

    scanf("%d", &times);

    for(int i = 0; i < times; i++){
        result = 0;
        scanf("%d%d", &x, &y);
        
        if(x > y) result = x - y;
        else result = y - x;

        if(result % 2 != 0) result++;
        result /= 2;

        printf("%d\n", result);

    }
}
