#include <stdio.h>

#define MAX_LENGTH 101
#define ARR_LENGTH 51

int main(void){
    char string[MAX_LENGTH];
    int arr_nums[ARR_LENGTH] = {0};
    int counter = 0, nr_cycles = 1;
    scanf(" %100[^\n]", string);

    for(int i = 0; string[i] != 0; i++){
        if(string[i] > 48 && string[i] < 52){
            arr_nums[counter] = string[i] - 48;
            counter++;
        }
    }
    while(nr_cycles != 0){
        nr_cycles = 0;
        for(int i = 0; i < counter; i++){
            int x;
            if(i > 0 && arr_nums[i] < arr_nums[i - 1]){
                x = arr_nums[i];
                arr_nums[i] = arr_nums[i - 1];
                arr_nums[i - 1] = x;
                nr_cycles = 1;
            }
        }
    }

    for(int i = 0; i < counter; i++){
        printf("%d", arr_nums[i]);
        if(i < counter - 1) printf("+");
    }

    return 0;
}
