
#include <stdio.h>
#include <stdlib.h>

int main(){
    int t, n, m;
    int *cd;

    scanf("%d", &t);

    while(t-- > 0){
        scanf("%d%d", &n, &m);
        cd = malloc(sizeof(int) * n * m);
        int arr[n][m];
        int check = 0;
        int c = 0;
        int res = 0;

        for(int i = 0; i < n * m; i++){
            cd = 0;
        }

        for (int i = 0; i < n; i++) {
            for (int k = 1; k < m; k++) {
                scanf("%d", &arr[i][k]);
                cd[arr[i][k]] = 1;
            }
        }


        // check for nearness of color
        for(int i = 0; i < n * m; i++){
            if(!cd[i]) continue;

            for(int k = 0; k < n; k++){
                for(int p = 0; p < m; p++){
                    if(0 == p) continue;
                    if(arr[k][p] == arr[k][p - 1]){
                        c = 1;
                        break;
                    }
                    if(0 == k) continue;
                    if(arr[k - 1][p] == arr[k][p]){
                        c = 1;
                        break;
                    }
                }
                if(1 == c) break;

            }
            // c is true only if two same colors are near each other
            if(c){
                res++;
                check = 1;
            }
            res++;
        }
        res -= 1 + check;

        printf("%d\n", res);

    }
}
