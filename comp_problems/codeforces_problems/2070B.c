#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int t;
	long long int n, x, cnt;
	unsigned long long int k;
	char *str;

	scanf("%d", &t);

	while(t-- > 0){
		scanf("%lld%lld%llu", &n, &x, &k);
		str = malloc(sizeof(char) * (n + 1));
		str[n] = '\0';
		cnt = -1;

	    scanf("%*[^\n]");
	    scanf("%s[^\n]", str);

	    // x != 0
	    int pos = x;
	    int f = 0;
	    for(long long int i = 0; i < k && (i - f) < n; i++){
	    	if('R' == str[i - f])
	    		pos++;
	    	else
	    		pos--;

	    	if(0 == pos && 0 != f){
	    		cnt = (i - f) + 1;
	    		break;
	    	}
	    	else if(0 == pos){
	    		f = i + 1;
	    	}
	    }
	    long long int res = 1;
	    printf("%d %lld\n", f, cnt);

	    if(cnt != k)
	    	res = k / (cnt);
	    
	    // this is the actual problem
    	if((k % cnt) % (cnt - 1) == 0)
    		res++;

	    if(-1 == cnt && f != 0)
	    	res = 1;

	    // printf("%lld   ", cnt);
	    printf("%lld\n", res);
	}
	return 0;
}