#include <stdio.h>
#include <stdlib.h>

int main(void){
    int t, n, *arr, res;
    scanf("%d", &t);

    while(t--){
        scanf("%d", &n);
        arr = malloc(sizeof(int) * n);
        res = 0;

        for(int i = 0; i < n; i++){
            scanf("%d", arr + i);
        }
        
        for(int i = 0; i < n; i++){
            if(i == 0 || i == n - 1) continue;

            if(arr[i] != arr[i - 1] || arr[i] != arr[i + 1]) res++;
        }

        if(arr[0] != arr[1]) res++;
        if(arr[n - 1] != arr[n - 2]) res++;
        
        printf("%d\n", res);
        free(arr);
    }
    return 0;
}
