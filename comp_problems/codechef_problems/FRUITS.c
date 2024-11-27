#include <stdio.h>
#include <assert.h>

int main(void){
    int t, oranges, apples, coins, result;

    assert(1 == scanf("%d", &t));

    for(int i = 0; i < t; i++){
        assert(3 == scanf("%d%d%d", &apples, &oranges, &coins));
        
        result = oranges - apples;
        result = result > 0 ? result : -(result);

        result -= coins;

        if(result > 0)
            printf("%d\n", result);
        else
            printf("0\n");

    }
}
