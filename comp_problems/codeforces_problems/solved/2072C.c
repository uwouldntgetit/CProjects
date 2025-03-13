#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// MEX is literally the minimum positive integer not in a sequence
// if I have to maximize it I musst get the highest amount of small subsequent positive integers
// if the number iseven then it doesn't matter

// QUANTO SONO FORTE, SONO SUN PROGRAMMATORE FANTASTICO

int log2_mine(long long int x){
    int v = 0;
    
    while(pow(2, v) < x){
        v++;
    }
    if(0 != v) v--;
    return v;
}

int main(){
    long long t, n, x;
    long long int k, cn, odd;
    
    scanf("%lld", &t);
    while(t-- > 0){
        scanf("%lld", &n);
        scanf("%lld", &x);
        cn = 0;
        k = 0;


        while(cn < n - 1){
            if((k | x) != x){
                break;
            }
            printf("%lld ", k);
            k++;
            cn++;

        }

        if(0 != k && (x / k) == 1)
            printf("%d", k);
        else
            printf("%lld ", x);

        cn++;

        while(cn < n){
            printf("0 ");
            cn++;
        }
        printf("\n");
    }
    return 0;
}

