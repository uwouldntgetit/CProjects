#include <stdio.h>
#include <math.h>

int main(void){
    int year, num_digits, arr_digits[4], counter = 1, result;
    short check_if_first = 0;

    scanf(" %4d", &year);
    num_digits = log10(year) + 1; // 4
        
    while(counter != 0){
        counter = 0;
        result = year;

        for(int i = 0; i < num_digits; i++){
            arr_digits[i] = year % 10;
            year /=10;
        }

        for(int i = 0; i < num_digits; i++){
            for(int j = 0; j < num_digits; j++){
                if(i != j && arr_digits[i] == arr_digits[j]){
                    counter++;
                    break;
                }
            }
            if(counter != 0)
                break;
        }
        if(check_if_first == 0)
            counter++;
        year = result + 1;
        check_if_first++;
    }

    if(counter == 0){
        printf("%d", result);
    } else{
    printf("There's a problem");
    }


    return 0;
}
