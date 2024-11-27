#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n, k, *array, t, count, res;
    scanf("%d", &t);

    while(t--){
        scanf("%d%d", &n, &k);
        res = 0;
        array = malloc(sizeof(int) * n);

        for(int i = 0; i < n; i++){
            scanf("%d", array + i);
        }

        for(int i = 0; i < n; i++){
            if(array[i] == i + 1) continue;
            count = 0;
            for(int k = 0; k < n; k++){
                if(array[k] == i + 1) count++;
            }
            if(count >= k) res++;
        }

        printf("%d\n", res);

    }
}
