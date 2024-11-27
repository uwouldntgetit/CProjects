#include <stdio.h>

void my_atoi(char *, int *weights);

int main(void){
    int bob, limak, result = 0;
    int weights[2];
    char string[6];

    scanf(" %5[^\n]", string);
    my_atoi(string, weights);

    limak = weights[0];
    bob = weights[1];

    while(limak <= bob){
        limak *= 3;
        bob *= 2;
        result++;
    }

    printf("%d", result);

    return 0;
}

void my_atoi(char *string, int *weights){
    int counter = 0;
    for(int i = 0; string[i] != 0; i++){
        if(string[i] >= 48 && string[i] <= 57){
            if(string[i - 1] >= 48 && string[i - 1] <= 57){
                weights[counter - 1] *= 10;
                weights[counter - 1] += string[i] - 48;
                continue;
            }
            weights[counter] = string[i] - 48;
            counter++;
        }
    }
}
