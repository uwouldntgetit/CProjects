#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void my_atoi(char *, int *);
void get_string(char *string, int lenght);

int main(void){
    int number_people, fence_height, width = 0, temp_arr[3];
    char string[20];

    get_string(string, 20);
    my_atoi(string, temp_arr);

    number_people = temp_arr[0];
    fence_height = temp_arr[1];

    int *arr_people = malloc(number_people * sizeof(int));
    char string_2[(number_people * 2) + 1];

    get_string(string_2, (number_people * 2) + 1);
    my_atoi(string_2, arr_people);

    for(int i = 0; i < number_people; i++){
        printf("%d ", arr_people[i]);
        if(arr_people[i] > fence_height)
            width += 2;
        else{
            width++;
        }
    }

    printf("%d", width);

    free(arr_people);
    return 0;
}

void my_atoi(char *string, int *temp_arr){
    int position_counter = 0;
    for(int i = 0; string[i] != 0; i++){
        if(string[i] >= 48 && string[i] <= 57){
            if(string[i - 1] >= 48 && string[i] <= 57){
                temp_arr[position_counter - 1] *= 10;
                temp_arr[position_counter - 1] += string[i] - 48;
                continue;
            }
            temp_arr[position_counter] = string[i] - 48;
            position_counter++;
        }
    }
}

void get_string(char *string, int length){
    if(fgets(string, length, stdin)){
        string[strcspn(string, "\n")] = 0;
    }
}
