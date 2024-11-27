#include <stdio.h>

int main(void){
    int times, numGroups, numX, result;

    scanf("%d", &times);

    for(int i = 0; i < times; i++){
        scanf("%d%d", &numGroups, &numX);
        
        result = (numGroups * 2 - numX) + 1;

        printf("%d\n", result);

    }
}
