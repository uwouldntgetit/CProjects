#include <stdio.h>

#define MAX 5

int main(void){
    int x, result = 0;

    scanf("%d", &x);
    if(x < 1 || x > 1000000) return 0;

    if(x % 5 != 0) result++;
    result += x / 5;

    printf("%d", result);

    return 0;
}
