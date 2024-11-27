#ifndef MATRIX_FUNCTIONS_H_
#define MATRIX_FUNCTIONS_H_



void assign_matrix_size(int* size_rows, int* size_columns);
void assing_matrix_values(int choice, int size_rows, int size_columns, int matrix[][size_columns]);
void initialize_matrix(int size_rows, int size_columns, int matrix[][size_columns]);
void choose_element(int *row_number, int *column_number);
void select_nr_rows_cols(int *nr_rows, int *nr_columns, int size_rows, int size_columns);
long int operation_maker(short selcted_operation, int size_rows, int size_columns, int matrix[][size_columns]);
long int operation_for_matrix(short selected_operation, short selected_target, int size_rows, int size_columns, int matrix[][size_columns]);
long int operation_for_elements(short selected_operation, int size_rows, int size_columns, int matrix[][size_columns]);
short select_target_operation(void);
short select_operation(void);


#endif // MATRIX_FUNCTIONS_H_
