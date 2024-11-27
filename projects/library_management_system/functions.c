#include "lib_header.h"

void main_function(void){
    char *file_name;
    int operation_to_do, result;
    printf("Insert the file name: ");
    while(file_name =  get_string(FILE_NAME_LENGTH)){
        file_name[0] != 0;
    }

    printf("Choose an operation to do:\n");
    printf("1. Add a book\n2. delete a book\n3. Borrow a book\n4. Return a book\n5. Search for a book\n");
    scanf("%d", &operation_to_do);
    // i'll leave it like this until i find a better alternative
    result = choose_operation(operation_to_do, file_name);
    
    if(result == 0)
        printf("Something's gone wrong\n");
    else
        printf("Operation executed with success\n");

    free(file_name);
}

int choose_operation(int op_chosen, char *file_name){
	int result_op;
    switch(op_chosen){
        case 1:
        	result_op = add_book(file_name);
        	break;
        case 2:
        	result_op = delete_book(file_name);
        	break; 

    }

    return result_op;
}

int add_book(char *file_name){
	char *book_name;
	// then it must be reopened in "a" mode
	printf("Insert the book name: ");
	book_name = get_string(MAX_LENGTH);
	if(store_book(file_name, book_name)){
        free(book_name);
		return 1;
    }else{
        free(book_name);
		return 0;
    }
}

int delete_book(char *file_name){
    char *book_name;
    int result;

    printf("Insert the book name: ");
    book_name = get_string(MAX_LENGTH);
    result = check_storage(file_name, book_name);
    // result now has, if the operation was a success,
    // the line number where the book is stored
    if(result > 0){
        result = delete_element(file_name, result);
        free(book_name);
        return result;
        // 1 if okay, 0 if not
    }else{
        free(book_name);
        return 0;
    }
}

char* get_string(int length){
    static char *string;
    string = malloc(length * sizeof(char));

    if(fgets(string, length, stdin)){
        string[strcspn(string, "\n")] = 0;
    }
    return string;
}


// function to store books in a file
int store_book(char *file_name, char *book_name){
	if(check_storage(file_name, book_name) > 0){
		FILE *storage = fopen(file_name, "a");
		if(storage != NULL){
			fprintf(storage, "%s\tavailable\n", book_name);
		} else{
			printf("The storage file can't be opened\n");
                fclose(storage);
				return 0;
		}
        fclose(storage);
	}
    return 1;
}

// it delete a line from a file
int delete_element(char *file_name, int file_line){
    char temp_file_name[FILE_NAME_LENGTH];
    char buffer[MAX_LINE_LENGTH];
    FILE *storage = fopen(file_name, "r");
    FILE *temp_storage = fopen(temp_file_name, "w");
    
    strcpy(temp_file_name, "temp____");
    strcat(temp_file_name, file_name);

    if(storage == NULL || temp_storage == NULL){
        printf("Error opening files\n");
        fclose(storage);
        fclose(temp_storage);
        return 0;
    }

    
    for(int i = 1; feof(storage) == 0; i++){
        // maybe the feof return value for not at eof isn't 0
        if(i == file_line) continue;
        // it skips the line to delete
        if(fgets(buffer, MAX_LINE_LENGTH - 1, storage)){
            fputs(buffer, temp_storage);
        }
        else{
            fclose(storage);
            fclose(temp_storage);
            return 0;
        }
    }

    fclose(storage);
    fclose(temp_storage);

    remove(file_name);
    rename(temp_file_name, file_name);

    return 1;
}

int borrow_book(void){

}

// remember to deallocate string
char* get_file_line(FILE* file_ptr){
    static char *string;
    string = malloc(MAX_LENGTH);
    if(fgets(string, MAX_LENGTH - 1, file_ptr) == NULL){
        fclose(file_ptr);
        return 0;
    }

    return string;
}

// function to check if the book is present in the library storage
// it returns the line number if it finds the phrase_to_check in storage, it returns 0 if temp_arr
// can't be initialized and it returns -1 if the phrase_to_check isn't present in storage
int check_storage(char *file_name, char *phrase_to_check){
    char *temp_arr;
    char *ptr_to_phrase;
    int line_number = 1;
    FILE *storage = fopen(file_name, "r");
    while(!feof(storage)){
		temp_arr = get_file_line(storage);
        /*if(strspn(temp_arr, EOF) > 0){
            printf("Book not present\n");
            fclose(storage);
            return 0;
        }
        dont know how it should check if the book is not present, there's already feof that does that
        keeping this here to celebrate my faultiness, and to remind myself to not do this absolutely
        useless shit anymore
        */

        if(temp_arr == NULL){
			printf("temp_arr in check_storage pointed to NULL\n");
            fclose(storage);
            free(temp_arr);
			return 0;
		}

        else if(*temp_arr == 0){
            printf("There was an error reading a line of the file\n");
            fclose(storage);
            free(temp_arr);
            return 0;
        }

		ptr_to_phrase = strstr(temp_arr, phrase_to_check);
		if(ptr_to_phrase != NULL){
            fclose(storage);
            free(temp_arr);
			return line_number;
		}
		line_number++;
    }
    fclose(storage);
    free(temp_arr);
    printf("book not present\n");
    // to delete later
    return -1;
}

// this functions checks if the book is available or not, and
// returns a nonzero value if it is
int check_if_available(char *word){
    char *check_ptr = strstr(word, "available");
    if(check_ptr != NULL)
        return 1;
    else
        return 0;
}

