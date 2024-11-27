#include <stdio.h>

int main(void){
    int num_cases, start, pay, charge, num_months;

    scanf("%d", &num_cases);
    getchar();

    int result[num_cases];

    for(int i = 0; i < num_cases; i++){
        scanf(" %d%d%d%d", &start, &pay, &charge, &num_months);
        getchar();
        result[i] = start;

        for(int j = 0; j < num_months; j++){
            result[i] += pay - charge;
        }

    }

    for(int i = 0; i < num_cases; i++){
        printf("%d\n", result[i]);
    }
    
    return 0;
}
