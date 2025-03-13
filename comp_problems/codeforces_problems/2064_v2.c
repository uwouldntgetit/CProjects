#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct tree{
    struct tree * bigger;
    struct tree * smaller;
    long long int v;
}

void add(struct tree *t, long long int n){
    struct tree *a;
    a->v = n;
    while(true){
        if(n > t->v){
            if(NULL == t->bigger){
                t.bigger = a; 
                break;
            }
            t = t.bigger;
        }
        if(n < t->v){
            if(NULL == t->smaller){
                t.smaller = a; 
                break;
            }
            t = t.smaller;
        }
    }
}

int search(struct tree *t, long long int n){
    while(true){
        if(n > t->v){
            if(NULL == t->bigger){
                return 0;
            }
            t = t.bigger;
        }
        else if(n < t->v){
            if(NULL == t->smaller){
                return 0;
            }
            t = t.smaller;
        }
        else
            return 1;
    }
}

void main(){
    long long int *arr, *comp;
    long long int t, n, l, r, cnt, max_l, max_r;


    scanf("%d", &t);
    // cleans stdin
    scanf("%*[^\n]");
    
    while(t-- > 0){
        scanf("%d", &n);
        arr = malloc(sizeof(int) * n);
//        comp = malloc(sizeof(int) * n);
        cnt = 0;
        int check;

        for(int i = 0; i < n; i++){
            scanf("%d", arr + i);
        }
        
        for(int i = 0; i < n; i++){
            check = false;
            for(int k = 0; k < cont k++){
                if(arr[i] == arr[k]) 
                    check = true;
            }

            if(!check){
                comp[cnt] = arr[i];
// arr[k] could be repeated
                
            }
            
            if(l - r > max_l - max_r){
                max_l = l;
                max_r = r;    
            }
        }
    }

    free(arr);
    free(comp);
}
