#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


/* Rules for output:
 * 1. obtain the highest score possible
 * 2. among the arrays that respect rule 1, take the smallest
*/
void main(){
    int *arr, *comp;
    int t, n, l, r, cnt;

    scanf("%d", &t);
    // cleans stdin
    scanf("%*[^\n]");
    
    // find the maximus contiguous subarray of distinct element
    while(t-- > 0){
        scanf("%d", &n);
        arr = malloc(sizeof(int) * n);
        /*comp = malloc(sizeof(int) * n);*/
        /*cnt = 0;*/
        int check;

        for(int i = 0; i < n; i++){
            scanf("%d", arr + i);
        }

        for(int i = 0; i < n; i++){
            check = 0;
            for(int k = 0; k < n; k++){
                if(arr[i] == arr[k] || arr[i] == -arr[k])
                    check++;
            }
            // there must be no other similar number in the array for it to be in comp
            // if check is a big number then the if has to fail
            if(1 >= check){
                /*comp[cnt] = arr[i];*/
                /*cnt++;*/
                arr[i] = -arr[i];
            }
        }
        // comp contains all the unique elements in arr

        l = r = -1;
        int res_l, res_r, m = -1;
        for(int i = 0; i < n; i++){
            // find l and r :)
            check = true;
            /*for(int k = 0; k < cnt; k++){*/
            /*    if(arr[i] == comp[k]){*/
            /*        check = false;*/
            /*        break;*/
            /*    }*/
            /*}*/

            if(arr[i] < 0)
                check = false;

            // se check e' false allora non e' un numero da eliminare
            if(check){
                l = r = -1;
                continue;
            }

            if(-1 == l){
                l = i;
                r = i;
            }
            else r++;

            if((r - l) > m){
                m = r - l;
                res_r = r;
                res_l = l;
            }
        }

        /*for(int i = 0; i < cnt; i++){*/
        /*    printf("%d ", comp[i]);*/
        /*}*/
        /*printf("\n");*/
        /*printf("%d\n", comp[0]);*/
        if(-1 == m)
            printf("0\n");
        else
            printf("%d %d\n", res_l + 1, res_r + 1);

        free(arr);
    }
}
