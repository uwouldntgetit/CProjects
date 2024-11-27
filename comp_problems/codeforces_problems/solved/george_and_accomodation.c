#include <stdio.h>
#include <string.h>

void my_atoi(char *string, int *array);
void get_string(char *string, int length);

int main(void){
    char string[11];
    int array[3], number_rooms, result = 0;

    get_string(string, 11);
    // gets the number of rooms
    my_atoi(string, array);

    number_rooms = array[0];
    if(number_rooms < 1 || number_rooms > 100)
        return 0;

    for(int i = 0; i < number_rooms; i++){
        get_string(string, 11);
        my_atoi(string, array);
        if(array[0] < array[1] && (array[1] - array[0]) > 1){
            result++;
        }
        else if(array [0] > array[1]){
            return 0;
        }
    }
    
    printf("%d", result);
    return 0;
}

void get_string(char *string, int length){
    if(fgets(string, length, stdin)){
        string[strcspn(string, "\n")] = 0;
    }
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
