#include <stdio.h>
#include <stdlib.h>

int main(){
    int t, n, m;
    int *d1, *d2;
    int *cd1, *cd2;

    scanf("%d", &t);

    while(t-- > 0){
        scanf("%d%d", &n, &m);
        d1 = malloc(sizeof(int) * n * m / 2 + 1);
        d2 = malloc(sizeof(int) * n * m / 2 + 1);
        cd1 = malloc(sizeof(int) * n * m);
        cd2 = malloc(sizeof(int) * n * m);
        int check = 1;
        int c = 0;
        int res = 0;

        for(int i = 0; i < n * m; i++){
            cd1[i] = 0;
            cd2[i] = 0;
        }

        for(int i = 0; i < n; i++){
            for(int k = 0; k < m; k++){
                if(check){
                    scanf("%d", d1 + c);
                    cd1[d1[c] - 1] = 1;
                    check = 0;
                } else {
                    scanf("%d", d2 + c);
                    cd2[d2[c] - 1] = 1;
                    c++;
                    check = 1;
                }
            }
        }
        for(int i = 0; i < n * m; i++){
            if(1 == cd1[i]){
                res++;
                printf("cd1:%d ", i + 1);
            }
            if(1 == cd2[i]){
                res++;
                printf("cd2:%d ", i + 1);
            }
        }
        res -= 2;
        printf("\n");
        printf("%d\n", res);
    }
}
