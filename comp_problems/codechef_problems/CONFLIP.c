#include <stdio.h>

int main(void){
    int times, games, num, init, guess, result;
    // if init is 1 = start head, else if = 2 start tails, same thing for guess, only that it determines the type of coin to guess the number of
    scanf("%d", &times);

    for(int i = 0; i < times; i++){
        scanf("%d", &games);
        for(int g = 0; g < games; g++){
            scanf("%d%d%d", &init, &num, &guess);

            if(init == guess){
                result = num / 2;
            }
            else {
                if(num % 2 == 0)
                    result = num / 2;
                else
                    result = (num / 2) + 1;
            }

            printf("%d\n", result);
        }
    }



    return 0;
}
