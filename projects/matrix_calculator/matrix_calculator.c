// doing a calculator for square matrices
// the user can input a matrix size and its elements, and then he can choose an operation to do
// the user can also choose the specific elements to use
// the available operations are:
// - addition
// - subtraction
// - finding the average
//
// faccio che per le operazioni, l'user puo' scegliere se fare una colonna o piu', una riga o piu', degli elementi specifici e infine tutta la matrice.
// in questi casi complessi, per evitare di dover fare 4 diverse funzioni per ogni operazione, possso utilizzare un puntatore a funzione che punta a funzioni base che svolgono 
// le operazioni scelte.
// uso il puntatore a funzione come parametro in una funzione piu' generale che magari fa la somma di tutti gli elementi di un determinato numero di colonne

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix_functions.h"


int main()
{
    srand(time(NULL));
    int size_rows, size_columns;
    long int result;
    short continue_or_not;

    assign_matrix_size(&size_rows, &size_columns);
    int matrix[size_rows][size_columns];
    restart:;
    initialize_matrix(size_rows, size_columns, matrix);
    short operation = select_operation();
    short target_op = select_target_operation();
    if(target_op == 1 || target_op == 2){
        result = operation_for_matrix(operation, target_op, size_rows, size_columns, matrix);
    }else if(target_op == 3){
        result = operation_for_elements(operation, size_rows, size_columns, matrix);
    }else{
        printf("There's a problem with select_target_operation\n");
    }

    if(target_op == 4){
        result = operation_for_elements(operation, size_rows, size_columns, matrix);
    }else if(target_op > 0 && target_op < 4){

    }else{
        printf("Something's wrong the select_target_operation\n");
    }
    printf("The result of the operation is: %ld\n", result);
    printf("Do you want to continue?\n1. yes\n2. no\n");
    scanf(" %1hd", &continue_or_not);

    if(continue_or_not == 1){
    goto restart;
    }else{
        printf("Thanks for using Matrix Calculator!\n");
    }

    return 0;
}

