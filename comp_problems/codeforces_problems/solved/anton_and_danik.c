#include <stdio.h>

int main(void){
    int number_games, counter_d = 0, counter_a = 0;
    scanf(" %d", &number_games);
    if(number_games < 1 || number_games > 100000) return 0;
    char string[number_games + 1];
    scanf(" %s", string);

    for(int i = 0; string[i] != 0; i++){
        string[i] == 'A'? counter_a++: counter_d++;
    }

    if(counter_a > counter_d)
        printf("Anton");
    else if(counter_d > counter_a)
        printf("Danik");
    else
        printf("Friendship");

    return 0;
}
