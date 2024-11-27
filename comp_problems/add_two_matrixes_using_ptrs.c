#include <stdio.h>

#define LENGTH 3

void initialize_matrix(int size_rows, int size_columns, int matrix[][size_columns]);
void print_matrix(int size_rows, int size_columns, int matrix[][size_columns]);
void sum_matrix(int size_rows, int size_columns, int matrix1[][size_columns], int matrix2[][size_columns]);

int main (void){
    int size_rows, size_columns;
    printf("Input number of rows: ");
    scanf(" %5d", &size_rows);
    printf("Input number of columns: ");
    scanf(" %5d", &size_columns);
    int matrix1[size_rows][size_columns];
    int matrix2[size_rows][size_columns];
    printf("Initializing matrix1: ");
    initialize_matrix(size_rows, size_columns, matrix1);
    printf("Initializing matrix2: ");
    initialize_matrix(size_rows, size_columns, matrix2);
    sum_matrix(size_rows, size_columns, matrix1, matrix2);
    
    return 0;
}

void initialize_matrix(int size_rows, int size_columns, int matrix[][size_columns]){
    for(int i = 0; i < size_rows; i++){
        for(int j = 0; j < size_columns; j++){
            scanf("%d", &matrix[i][j] );
        }
    }
}

void print_matrix(int size_rows, int size_columns, int matrix[][size_columns]){
    for(int i = 0; i < size_rows; i ++){
        printf("\n");
        for(int j = 0; j < size_columns; j++){
                printf("%d ", *(*(matrix + i) + j) );
        }
    }
    printf("\n");
}

void sum_matrix(int size_rows, int size_columns, int matrix1[][size_columns], int matrix2[][size_columns]){
    int final_matrix[size_rows][size_columns];
    for(int i = 0; i < size_rows; i++){
        for(int j = 0; j < size_columns; j++){
            *(*(final_matrix + i) + j) = *(*(matrix1 + i) + j) + *(*(matrix2 + i) + j);
        }
    }
    printf("The sum of the matrixes is:");
    print_matrix(size_rows, size_columns, final_matrix);
}
