#include <stdio.h>

#define FEVER 98

int main(void){
    int num_lines, temperature;

    scanf("%d", &num_lines);
    getchar();
    
    int array[num_lines];

    for(int i = 0; i < num_lines; i++){
        scanf("%d", &temperature);
        getchar();

        if(temperature > FEVER) 
            array[i] = 1;
        else {
            array[i] = 0;
        }
    }

    for(int i = 0; i < num_lines; i++){
        if(array[i] == 1)
            printf("YES\n");
        else 
            printf("NO\n");
    }
    

    return 0;
}
