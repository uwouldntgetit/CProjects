#include <stdio.h>
#include <stdlib.h>

int main(){
    int t, n, m, k;
    int *d;
    char *cd;

    scanf("%d", &t);

    while(t-- > 0){
        scanf("%d%d", &n, &m);
        d = malloc(sizeof(int) * n * m);
        cd = malloc(sizeof(char) * n * m);

        for(int i = 0; i < n * m; i++){
            cd[i] = 0;
        }

        for(int i = 0; i < n * m; i++){
            scanf("%d", &k);
            d[i] = k;
            cd[k] = 1;
        }


    }
}
