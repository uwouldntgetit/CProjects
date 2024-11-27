#include <stdio.h>

int main(void){
    int num_cases, alice[2], bob[2];
    float a_result, b_result;

    scanf("%d", &num_cases);
    getchar();

    int result[num_cases];

    for(int i = 0; i < num_cases; i++){
        scanf(" %d%d%d%d", &alice[0], &alice[1], &bob[0], &bob[1]);
        getchar();

        a_result = (float)alice[0] / alice[1];
        b_result = (float)bob[0] / bob[1];

        if(a_result > b_result)
            result[i] = 1;
        else if(a_result < b_result)
            result[i] = 2;
        else
            result[i] = 0;
    }

    for(int i = 0; i < num_cases; i++){
        if(result[i] == 1)
            printf("Alice\n");
        else if(result[i] == 2)
            printf("Bob\n");
        else
            printf("Equal\n");
    }
    return 0;
}
