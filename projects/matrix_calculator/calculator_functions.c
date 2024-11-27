
#include <stdio.h>
#include <stdlib.h>

#define sum(result, x) ((result) += (x))
#define subtract(result, x) ((result) -= (x))
#define for_loop_with_op(macro, result, n, x) (for(int i = 0; i < n; i++){ macro(result, x++) })
// macro defines the operation to do, n is the number of iterations, don't know if the arr arithmetic is right



// function to assign the size of a VL matrix
void assign_matrix_size(int* size_rows, int* size_columns)
{
    printf("Welcome to the Matrix Calculator Version 1.0\n");
    printf("Input the number of rows of the matrix: ");
    scanf("%d", size_rows);
    printf("Input the number of columns of the matrix: ");
    scanf("%d", size_columns);
}

// ************************************************************************************
// ******************************START_INITIALIZATION**********************************
// ************************************************************************************

void assign_matrix_values(int choice, int size_rows, int size_columns, int matrix[][size_columns])
{
    for(int i = 0; i < size_rows; i++)
    {
        for(int j = 0; j < size_columns; j++)
        {
            if(choice == 1)
            {
                printf("matrix[%d][%d]: ", i, j);
                scanf("%d", &matrix[i][j]); // search for better alternatives
            }else
            {
                matrix[i][j] = rand() % 1000000;
                // it randomly initializes positive numbers till one million
            }
        }
    }
}


void initialize_matrix(int size_rows, int size_columns, int matrix[size_rows][size_columns]){
    int choice;
    printf("Now you have to choose how to initialize the matrix: \n");
    illegal_choice:;
    printf("1. Initialize the matrix yourself\n2. Randomly initialize the matrix\n");
    scanf(" %1d", &choice);
    switch(choice){
        case 1:
        case 2:
            assign_matrix_values(choice, size_rows, size_columns, matrix);
            break;
        default:
            printf("You inserted a non valid argument!!!\nChoose once more\n");
            goto illegal_choice;
    }
}


void choose_element(int *row_number, int *column_number){
    // here the user can input a number greater than what an int can store, and possibly do a stack overflow
    printf("Row number: ");
    scanf("%7d", row_number);
    printf("Column number: ");
    scanf("%7d", column_number);
}

// *******************************************************************************
// ****************************END_INITIALIZATION*********************************
// *****************************START_OPERATION***********************************
// *******************************************************************************

// used in operation for matrix
void select_nr_rows_cols(int *nr_rows, int *nr_columns, int size_rows, int size_columns){
    illegal:;
    printf("Insert the number of rows: ");
    scanf(" %7d", nr_rows);
    printf("Insert the number of columns: ");
    scanf(" %7d", nr_columns);
    if(*nr_rows > size_rows || *nr_columns > size_columns){
        printf("The numbers inserted are illegal!\nonly positive integers less than the size of the matrix are allowed\n");
        goto illegal;
    }
    if(*nr_rows < 0 || *nr_columns < 0){
        printf("The numbers inserted are illegal!\nonly positive integers allowed\n");
        goto illegal;
    }

}


// function that solves the operations, used in operation_matrix
long int operation_maker(short selected_operation, int size_rows, int size_columns, int matrix[][size_columns]){
    long int result = 0;
    // based on selected_op it chooses the op func that *operation has to point
    // it makes the calculations and then it returns the result
    switch(selected_operation){
        case 1:
            for(int i = 0; i < size_rows; i++){
                for(int j = 0; j < size_columns; j++){
                    result += matrix[i][j];
                }
            }
            break;
        case 2:
            for(int i = 0; i < size_rows; i++){
                for(int j = 0; j < size_columns; j++){
                    result -= matrix[i][j];
                }
            }
            break;
        case 3:
            for(int i = 0; i < size_rows; i++){
                for(int j = 0; j < size_columns; j++){
                    result += matrix[i][j];
                }
            }
            result /= size_rows * size_columns;
            break;
    }
    return result;
}

// main function for choices 1 and 2
long int operation_for_matrix(short selected_operation, short selected_target, int size_rows, int size_columns, int matrix[][size_columns]){
    int nr_columns, nr_rows;
    long int result = 0;

    if(selected_target == 1){
        select_nr_rows_cols(&nr_rows, &nr_columns, size_rows, size_columns);
    }

    switch(selected_target){
        case 1:
            result = operation_maker(selected_operation, nr_rows, nr_columns, matrix);
            break;
        case 2:
            result = operation_maker(selected_operation, size_rows, size_columns, matrix);
            break;
        default:
            printf("Ther is a problem with selected target of operation_for_mtrix\n");
    }
    return result;
}

long int operation_for_elements(short selected_operation, int size_rows, int size_columns, int matrix[][size_columns]){
    int nr_elements, row, column;
    printf("Insert the number of elements you want to use: \n");
    scanf(" %7d", &nr_elements);
    // the maximum number of elements is 9.999.999
    int array_elements[nr_elements];

    // here the user can selecte the specific elements in the matrix
    for(int i = 0; i < nr_elements; i++){
        choose_element(&row, &column);
        array_elements[i] = matrix[row][column];
    }

    long int result;

    switch(selected_operation){
        case 1:
            for(int i = 0; i < nr_elements; i++){
                sum(result, array_elements[i]);
            }
            break;

        case 2:
            for(int i = 0; i < nr_elements; i++){
                sum(result, array_elements[i]);
            }
            break;

        case 3:
            for(int i = 0; i < nr_elements; i++){
                sum(result, array_elements[i]);
            }
            result /= nr_elements;
            break;
    }
    return result;
}

short select_target_operation(void){
    short selected_target;
    printf("Select a target for the operation: \n");
    illegal_choice:;
    printf("1. You choose the specific rows and columns\n2. All the matrix\n3. Specify the elements\n");
    scanf(" %1hd", &selected_target);
    if(selected_target < 1 || selected_target > 3){
            printf("You inserted a non valid argument!!!\nChoose once more\n");
            goto illegal_choice;
    }
    return selected_target;

}

// it return the number of the selected operation
short select_operation(void){
    short selected_operation ;
    printf("Select the operation you want to do: \n");
    illegal_choice:;
    printf("1. Summation \n2. Subtraction\n3. Average\n");
    scanf(" %1hd", &selected_operation);
    if(selected_operation < 1 || selected_operation > 3){
            printf("You inserted a non valid argument!!!\nChoose once more\n");
            goto illegal_choice;
    }
    return selected_operation;
}





