#include <stdio.h>

void my_atoi(char *, int, int *);

int main(void){
    char input_line[5];
    int arr[3], result;
    scanf(" %4[^\n]", input_line);
    my_atoi(input_line, 3, arr);

    int m = arr[0];
    int n = arr[1];
    if(m > n || m < 0 || n > 16) return 0;

    result = (m * n) / 2;
    printf("%d", result);

    return 0;
}

void my_atoi(char *string, int length, int *final_result){
    int counter_array_position = 0;
    for(int i = 0; i < length; i++){
        if(string[i] >= 48 && string[i] <= 57){
            // it check if the character is a number
            if(string[i - 1] >= 48 && string[i - 1] <= 57){
                final_result[counter_array_position - 1] = final_result[counter_array_position - 1] * 10 + (string[i] - 48); 
                continue;
                // it solves the problem of multiple-digit numbers
            }
            final_result[counter_array_position] = string[i] - 48;
            counter_array_position++;
        }
    }
}
