#include <stdio.h>

void my_atoi(char *, long int *);

int main(){
    long int dollars, arr_numbers[4], total_cost = 0;
    char string[21];
    int cost_banana, number_bananas, counter = 1;

    scanf("%20[^\n]", string);
    my_atoi(string, arr_numbers);

    cost_banana = arr_numbers[0];
    dollars = arr_numbers[1];
    number_bananas = arr_numbers[2];

    while(number_bananas > 0){
        total_cost += cost_banana * counter;
        counter++;
        number_bananas--;
    }
    if(total_cost - dollars >= 0){
        printf("0");
    } else{
        printf("%lu", total_cost);
    }

    return 0;
}

void my_atoi(char *string, long int *final_result){
    int counter_array_position = 0;
    for(int i = 0; i < string[i]; i++){
        if(string[i] >= 48 && string[i] <= 57){
            // it check if the character is a number
            if(string[i - 1] >= 48 && string[i - 1] <= 57){
                final_result[counter_array_position - 1] = final_result[counter_array_position - 1] * 10 + (string[i] - 48);
                continue;
            }
            final_result[counter_array_position] = string[i] - 48;
            counter_array_position++;
        }
    }
}
