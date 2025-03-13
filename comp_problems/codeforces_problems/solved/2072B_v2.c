#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    long long int t, n, c, m;
    char k;

    scanf("%lld", &t);
    // scanf("%*[^\n]");
    
    while(t-- > 0){
        long long int sh = 0, ln = 0;
        scanf("%lld", &n);
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
        	c = s[i];
            if('_' == c) ln++;
            if('-' == c) sh++;
        }
        m = (ln * (sh / 2)) * (sh / 2 + (sh % 2 ? 1 : 0));
	    printf("%lld\n", m);
	}
	return 0;
}