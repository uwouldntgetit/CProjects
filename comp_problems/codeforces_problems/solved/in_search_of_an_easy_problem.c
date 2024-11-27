#include <stdio.h>
#include <string.h>

void get_string(char *string, int length);
void my_atoi(char *string, int *array);

int main(void){
    int num_people, array[101];
    char string[202];

    get_string(string, 5);
    my_atoi(string, array);
    num_people = array[0];
    get_string(string, 201);
    my_atoi(string, array);

    for(int i = 0; i < num_people; i++){
        if(array[i] == 1){
            printf("HARD");
            return 0;
        }
    }
    printf("EASY");
    return 0;
    
    return 0;
}

void get_string(char *string, int length){
    if(fgets(string, length, stdin))
            string[strcspn(string, "\n")] = 0;
}

void my_atoi(char *string, int *array){
    int counter = 0;
    for(int i = 0; string[i] != 0; i++){
        if(string[i] >= 48 && string[i] <= 57){
            if(string[i - 1] >= 48 && string[i - 1] <= 57){
                array[counter - 1] *= 10;
                array[counter - 1] += string[i] - 48;
                continue;
            }
            array[counter] = string[i] - 48;
            counter++;
        }
    }
}
