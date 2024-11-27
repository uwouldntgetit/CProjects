#include <stdio.h>

void my_atoi(char *, long int *);

int main(void){
    long int number, array[3];
    int subtractions;
    char string[15];

    scanf("%14[^\n]", string);
    my_atoi(string, array);

    number = array[0];
    subtractions = array[1];

    for(int i = 0; i < subtractions; i++){
        if(number % 10 == 0){
            number /= 10;
            continue;
        }

        number--;
    }

    printf("%ld", number);

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
