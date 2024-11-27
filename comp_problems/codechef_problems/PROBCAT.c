#include <stdio.h>

int main(void){
    int times, x;

    scanf("%d", &times);

    for(int i = 0; i < times; i++){
        scanf("%d", &x);

        if(x < 100)printf("Easy\n");
        else if(x < 200) printf("Medium\n");
        else printf("Hard\n");
    }
    return 0;
}
