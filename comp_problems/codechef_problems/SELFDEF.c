#include <stdio.h>

int main(void){
    int num_cases, num_objects, x, result;

    scanf("%d", &num_cases);
    getchar();

    for(int i = 0; i < num_cases; i++){
        result = 0;
        scanf("%d", &num_objects);
        getchar();

        for(int k = 0; k < num_objects; k++){
            scanf("%d", &x);

            if(x > 9 && x < 61)
                result++;
        }
        getchar();
        printf("%d\n", result);
    }

    return 0;
}
