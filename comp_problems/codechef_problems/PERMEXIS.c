#include <stdio.h>
#include <stdlib.h>

int main(void){
    int t, n, *arr, min, pos, x;
    scanf("%d", &t);

    while(t--){
        scanf("%d", &n);
        arr = malloc(sizeof(int) * n);

        for(int i = 0; i < n; i++){
            scanf("%d", arr + i);
        }

        for(int k = 0; k < n; k++){
            min = arr[k];
            pos = k;
            for(int i = k; i < n; i++){
                if(arr[i] < min){
                    min = arr[i];
                    pos = i;
                }
            }
            x = arr[k];
            arr[k] = min;
            arr[pos] = x;
        }
        x = 1;

        for(int i = 0; i < n - 1; i++){
            if((arr[i + 1] - arr[i]) > 1) x = 0;
        }

        if(x)
            printf("YES\n");
        else
            printf("NO\n");

    }
    return 0;
}
