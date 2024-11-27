#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 101
// a
void my_atoi(char *, int, int *);

int main(){
    int *first_line, *second_line;
    int num_contestant_passed = 0;
    char *string_to_take;
    string_to_take = malloc(sizeof(char) * MAX_LENGTH);
    first_line = malloc(sizeof(int) * 2);
    
    // input first line
    scanf(" %4[^\n]", string_to_take);
    my_atoi(string_to_take, 4, first_line);

    int n = first_line[0]; // number of participants
    int k = first_line[1]; // contestant with the lowest acceptable score
    if(k > n || k == 0) return 0;
    second_line = malloc(sizeof(int) * n);

    scanf(" %101[^\n]", string_to_take);
    my_atoi(string_to_take, MAX_LENGTH, second_line);

    for(int i = 0; i < n; i++){
        if(second_line[i] == 0 || second_line[i] > 100) continue;
        if(second_line[i] >= second_line[k - 1]) num_contestant_passed++;
    }

    printf("%d", num_contestant_passed);

    free(first_line);
    free(second_line);
    free(string_to_take);
    return 0;
}

void my_atoi(char *string, int length, int *final_result){
    int counter_array_position = 0;
    for(int i = 0; i < length; i++){
        if(string[i] >= 48 && string[i] <= 57){
            // it check if the character is a number
            if(string[i - 1] >= 48 && string[i - 1] <= 57){
                final_result[counter_array_position - 1] = final_result[counter_array_position - 1] * 10 + (string[i] - 48); // 0 * 10 == 0, la cifra davanti deve essere moltipliicata per 10
                continue;
                // it solves the problem of multiple-digit numbers
            }
            final_result[counter_array_position] = string[i] - 48;
            counter_array_position++;
        }
    }
}
