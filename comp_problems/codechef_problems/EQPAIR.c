#include <stdio.h>
#include <stdlib.h>

int lcm(int num1, int num2);

int main(void){
    int num_cases, arr_length, *array;

    scanf("%d", &num_cases);
    getchar();

    int result[num_cases];

    for(int i = 0; i < num_cases; i++){
        scanf("%d", &arr_length);
        getchar();
        result[i] = 0;

        array = malloc(arr_length * sizeof(int));
        for(int j = 0; j < arr_length; j++){
            scanf("%d", array + j);
        }
        for(int j = 0; j < arr_length; j++){
            for(int k = j + 1; k < arr_length; k++){
                if(array[j] == array[k]){
                    result[i]++;
                }
            }
        }
        getchar();
        free(array);
    }

    for(int i = 0; i < num_cases; i++)
        printf("%d\n", result[i]);
    
    return 0;
}

// found out i don't need to know the least common divisor or the GCD for this, i feel stupid

int lcm(int num1, int num2){
    int check = 0, i, counter = 0, result = 0;
    int arr1[200];
    while(num1 >= 0){
        check = 0;
        i = 2;
        while(check == 0){
            if((num1 % i) == 0){
                arr1[counter] = i;
                check++;
                counter++;
                num1 /= i;
            }
            i++;
        }
    }
    counter = 0;
    while(num2 >= 0){
        check = 0;
        i = 2;
        while(check == 0){
            if((num2 % i) == 0){
                arr1[counter] = i;
                check++;
                counter++;
                num2 /= i;
            }
            i++;
        }
    }
    for(int i = 0; arr1[i] != 0; i++)
        result *= arr1[i];

    return result;
}



