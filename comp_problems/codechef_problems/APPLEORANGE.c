#include <stdio.h>
#include <assert.h>

int main(void){
    int t, apples, oranges, temp, result;

    assert(scanf("%d", &t) == 1);

    for(int i = 0; i < t; i++){
        // scanf returns the number of items it successfully read
        assert(scanf("%d%d", &apples, &oranges) == 2);
        result = 0;

        while(oranges != apples){
            if(oranges > apples)
                oranges -= apples;
            else if(oranges < apples)
                apples -= oranges;
        }

        printf("%d\n", apples);
    }
}
