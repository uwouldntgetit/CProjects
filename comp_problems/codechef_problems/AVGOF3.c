#include <stdio.h>
#include <assert.h>


int main(void){
    int t, num, a1, a2 ,a3;

    assert(1 == scanf("%d", &t));

    for(int i = 0; i < t; i++){
        assert(1 == scanf("%d", &num));

        a1 = a2 = a3 = num;
        a1--;
        a3++;
        
        printf("%d %d %d\n", a1, a2, a3);
    }
}
