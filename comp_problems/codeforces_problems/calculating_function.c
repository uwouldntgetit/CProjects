#include <stdio.h>

int main(void){
    long int num, subtract = 0, result;

    scanf("%ld", &num);
    
    if(num % 2 == 0){
        subtract = num / 2;
        result = num - subtract;
    }else{
        result = -num / 2 - 1;
    }

    printf("%ld", result);
    return 0;
}
