#include <stdio.h>

void my_atoi(char *, int *);

int main(void){
    int num_childs, time, array_atoi[3], children_to_swap[51], count = 0;
    char string_num[50], string_bg[50];
    scanf("%8[^\n]", string_num);
    my_atoi(string_num, array_atoi);
    scanf("%s", string_bg);

    num_childs = array_atoi[0];
    time = array_atoi[1];

    while(time > 0){
        for(int i = num_childs; i >= 0; i--){
            if(string_bg[i] == 'B' && string_bg[i + 1] == 'G'){
                children_to_swap[count] = i;
                count++;
            }
        }
        for(int j = 0; j <= count; j++){
            char swap = string_bg[children_to_swap[j]];
            string_bg[children_to_swap[j]] = string_bg[children_to_swap[j] + 1];
            string_bg[children_to_swap[j] + 1] = swap;
        }
        time--;
    }
    printf("%s", string_bg);

    return 0;
}

void my_atoi(char *string, int *final_result){
    int counter_array_position = 0;
    for(int i = 0; i < string[i]; i++){
        if(string[i] >= 48 && string[i] <= 57){
            // it check if the character is a number
            if(string[i - 1] >= 48 && string[i - 1] <= 57){
                final_result[counter_array_position - 1] = final_result[counter_array_position - 1] * 10 + (string[i] - 48);
                continue;
            }
            final_result[counter_array_position] = string[i] - 48;
            counter_array_position++;
        }
    }
}
