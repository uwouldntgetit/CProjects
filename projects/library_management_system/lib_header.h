#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME_LENGTH 250
#define MAX_LENGTH 300
#define MAX_LINE_LENGTH 600

void main_function(void);
int choose_operation(int op_chosen, char *file_name);
int add_book(char *file_name);
char* get_string(int length);
FILE* open_file(char* file_name, char* mode);
int store_book(char *file_name, char *book_name);
char* get_file_line(FILE* file_ptr);
int check_storage(char *file_name, char *phrase_to_check);
int delete_book(char *file_name);
int delete_element(char *file_name, int file_line);
