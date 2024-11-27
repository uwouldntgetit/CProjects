#include <stdio.h>

#define LENGTH 5

int find_row(int (*)[LENGTH], int);
int find_column(int (*)[LENGTH], int);
void initialize_matrix(int (*)[LENGTH]);
void my_atoi(char *, int, int, int (*)[LENGTH]);

int main(){
    int matrix[LENGTH][LENGTH];
    unsigned moves = 0;
    int row, column;
    char string[11];
    for(int i = 0; i < LENGTH; i++){
        scanf(" %10[^\n]", string);
        my_atoi(string, 11, i, matrix);
    }
    printf("\nciao\n");

    row = find_row(matrix, 1);
    column = find_column(matrix, 1);

    moves += 2 - row;
    moves += 2 - column;
    printf("%u", moves);

    return 0;
}

int find_row(int (*matrix)[LENGTH], int element_to_find){
    for(unsigned i = 0; i < LENGTH; i++){
        for(unsigned j = 0; j < LENGTH; j++){
            if(matrix[i][j] == element_to_find){
                printf("row: %d\n", i);
                return i;
            }
        }
    }
    return -1;
}

int find_column(int (*matrix)[LENGTH], int element_to_find){
    for(unsigned i = 0; i < LENGTH; i++){
        for(unsigned j = 0; j < LENGTH; j++){
            if(matrix[i][j] == element_to_find){
                printf("column: %d\n", i);
                return j;
            }
        }
    }
    return -1;
}

void my_atoi(char *string, int length, int row, int (*final_result)[LENGTH]){
    int counter_array_position = 0;
    for(int i = 0; i < length; i++){
        if(string[i] >= 48 && string[i] <= 57){
            final_result[row][counter_array_position] = string[i] - 48;
            counter_array_position++;
        }
    }
}
