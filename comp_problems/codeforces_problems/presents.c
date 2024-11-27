#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_string(char *string, int length);
void my_atoi(char *string, int *array);

int main(void){
    int num_people, *array_presents, *array_result;
    char *string_presents;

    scanf("%d", &num_people);
    getchar();

    array_presents = malloc(num_people * sizeof(int));
    array_result = malloc(num_people * sizeof(int));
    string_presents = malloc((num_people * sizeof(char) * 2) + 2);
    get_string(string_presents, num_people * 2);
    my_atoi(string_presents, array_presents);

    for(int i = 1; i <= num_people; i++){
        for(int j = 0; j < num_people; j++){
            if(array_presents[j] == i)
                array_result[i - 1] = j + 1;
        }
    }
    
    for(int i = 0; i < num_people; i++)
        printf("%d ", array_result[i]);
            

    free(array_presents);
    free(array_result);
    free(string_presents);
    return 0;
}

void get_string(char *string, int length){
    if(fgets(string, length, stdin))
        string[strcspn(string, "\n")] = 0;
}

void my_atoi(char *string, int *array){
    int counter = 0;
    for(int i = 0; string[i] != 0; i++){
        if(string[i] >= 48 && string [i] <= 57){
            if(string[i - 1] >= 48 && string [i - 1] <= 57){
                array[counter - 1] *= 10;
                array[counter - 1] += string [i] - 48;
                continue;
            }

            array[counter] = string[i] - 48;
            counter++;
        }
    }
}
            
