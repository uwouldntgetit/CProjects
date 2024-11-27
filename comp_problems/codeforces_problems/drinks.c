#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void my_atoi(char *string, int *array);

int main(void){
    int num_drinks, *array;
    long double result = 0;
    char *string;

    array = malloc(100 * sizeof(int));
    string = malloc(101 * sizeof(char));

    scanf("%d", &num_drinks);
    getchar();

    if(fgets(string, 100, stdin)){
        string[strcspn(string, "\n")] = 0;
    }else{
        free(array);
        free(string);
        return 1;
    }
    my_atoi(string, array);

    for(int i = 0; i < num_drinks; i++){
        result += array[i];
    }

    result = (long double)result / num_drinks;
    printf("%.12Lf", result);


    free(array);
    free(string);
    return 0;
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
 
