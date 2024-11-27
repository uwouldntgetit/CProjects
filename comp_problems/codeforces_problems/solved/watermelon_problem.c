#include <stdio.h>

int main(void){
    int weight;
    // illegal:;
    // printf("Input weight in kg(between 1 and 100): ");
    scanf(" %3d", &weight);
    if(weight < 1 || weight > 100) return 0;
    printf("%s", weight % 2 == 0 && weight != 2? "YES" : "NO");
    return 0;
}
