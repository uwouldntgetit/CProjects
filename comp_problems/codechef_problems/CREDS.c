#include <stdio.h>

int main(void){
    int num_lines, array[3];
    int result;

    scanf("%d", &num_lines);
    getchar();

    int array_results[num_lines];

    for(int i = 0; i < num_lines; i++){
        scanf(" %d%d%d", &array[0], &array[1], &array[2]);
        getchar();
        result += array[0] * 4;
        result += array[1] * 2;
        array_results[i] = result;
        result = 0;
    }

    for(int i = 0; i < num_lines; i++)
        printf("%d\n", array_results[i]);

    return 0;
}
