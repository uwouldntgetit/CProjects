#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


/* Rules for output:
 * 1. obtain the highest score possible
 * 2. among the arrays that respect rule 1, take the smallest
*/
void main(){
    long long int *arr, *comp;
    long long int t, n, l, r, cnt;

    scanf("%lld", &t);
    // cleans stdin
    scanf("%*[^\n]");
    
    while(t-- > 0){
        scanf("%lld", &n);
        arr = malloc(sizeof(int) * n);
        cnt = 0;
        int check;
        for(int i = 0; i < n; i++)

        for(int i = 0; i < n; i++){
            // scanf("%lld", arr + i);
            scanf("%lld", &cnt);
            if(arr[i] > cnt) cnt = arr[i];
        }
        comp = malloc(sizeof(int) * cnt + 1);

        for(int i = 0; i < n; i++){
            if(-5032 == comp[arr[i]] || -9209 == comp[arr[i]])
                comp[arr[i]] = -9209;
            else
                comp[arr[i]] = -5032;
        }

        l = r = -1;
        int res_l = -1, res_r, m = -1;

        for(int i = 0; i < n; i++){
            if(-5032 != comp[arr[i]]){
                l = -1;
                continue;
            }
            r = i;
            if(-1 == l) l = i;
            if(r - l > m){
                m = r - l;
                res_r = r;
                res_l = l;
            }
        }

        if(-1 == res_l)
            printf("0\n");
        else
            printf("%d %d\n", res_l + 1, res_r + 1);

        free(arr);
    }
}
