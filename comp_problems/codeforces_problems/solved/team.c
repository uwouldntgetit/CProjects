#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_string(char *);
int my_atoi(char *);

int main(void){
    char problem_solution[10];
    int num_problems, solutions;
    int counter = 0;
    scanf("%8d", &num_problems);
    if(num_problems < 1 || num_problems > 1000) return 0;

    while(num_problems > 0){
        scanf(" %7[^\n]", problem_solution);

        //get_string(problem_solution);
        solutions = my_atoi(problem_solution);
        if(solutions == 111 || solutions == 110 || solutions == 101 || solutions == 11) counter++;
        num_problems--;
    }
    printf("%d\n", counter);
    
    return 0;
}

int my_atoi(char *string){
    int digit_position = 100, number = 0;
    for(int i = 0; string[i] != 0; i++){
        if(string[i] >= 48 && string[i] <= 57){
            number += (string[i] - 48) * digit_position;
            digit_position /= 10;
        }
    }
    
    return number;
}

/*void get_string(char *string){
    if(fgets(string, sizeof(string), stdin))
        if(sscanf(string, "%d", &i) == 1)

}*/
