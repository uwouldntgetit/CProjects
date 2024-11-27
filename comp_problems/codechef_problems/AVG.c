#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n, k, v, t, val, x;
    scanf("%d", &t);

    while(t--){
        scanf("%d%d%d", &n, &k, &v);
        val = 0;

        for(int i = 0; i < n; i++){
            scanf("%d", &x);
            val += x;
        }

        x = (n + k) * v - val;

        if(x < 1)
            val = -1;
        else if(x % k == 0)
            val = x / k;
        else
            val = -1;

        printf("%d\n", val);
    }
}
