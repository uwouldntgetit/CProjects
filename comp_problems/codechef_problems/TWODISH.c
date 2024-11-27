#include <stdio.h>
#include <assert.h>

int main(void){
    int t, guests, fruits, vegs, fish;

    assert(1 == scanf("%d", &t));

    for(int i = 0; i < t; i++){
        assert(4 == scanf("%d%d%d%d", &guests, &fruits, &vegs, &fish));

        if(vegs < guests)
            printf("NO\n");
        else if(fruits + fish < guests)
            printf("NO\n");
        else
            printf("YES\n");
    }
}
