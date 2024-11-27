#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define FILE_NAME_LENGTH 250
#define MAX_LENGTH 300
#define MAX_LINE_LENGTH 600

int delete_line(char *file_name, int line_number);

int main(void){
    int num;
    char file_name[FILE_NAME_LENGTH];

    printf("Input the number of the line to delete: ");
    scanf("%d", &num);
    printf("input the file name: ");
    if(fgets(file_name, 200, stdin))
        file_name[strcspn(file_name, "\n")] = 0;

    if(delete_line(file_name, num))
        return 0;
    else
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
        printf("error opening files\n");
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
    // add part where you delete storage and change temp_storage name to the original file name
    fclose(storage);
    fclose(temp_storage);
    return 1;
}
