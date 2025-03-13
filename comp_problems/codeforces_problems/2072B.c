#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    int t, n, c, m;
    char k;

    scanf("%d", &t);
    // scanf("%*[^\n]");
    
    while(t-- > 0){
        c = 0;
        scanf("%d", &n);
        char s[n];
        int i = 0;

        while(i < n){
            scanf(" %c", &k);
            if('-' == k || '_' == k){
                s[i] = k;
                // printf("%c ", s[i]);
                i++;
            }
        }

        for(int i = 0; i < n; i++){
            if('_' == s[i]) continue;
            m = 0;
            for(int p = i + 1; p < n; p++){
                if('_' == s[p]){
                    m++;
                    continue;
                }
                c += m;
            }
        }
        if(strstr(s, "--_")) c++;
        if(strstr(s, "_--")) c++;
        printf("%d\n", c);
    }
    return 0;
}
