#include <stdio.h>

int main(void){
    int cases, num1, num2;

    scanf("%d", &cases);
    getchar();

    for(int i = 0; i < cases; i++){
        scanf("%d%d", &num1, &num2);
        getchar();

        num1 = (num1 - 1) / 10;
        num2 = (num2 - 1) / 10;

        printf("%d\n", num1 > num2 ? num1 - num2 : num2 - num1);

    }
}

