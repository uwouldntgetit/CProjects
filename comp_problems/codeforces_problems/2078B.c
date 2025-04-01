#include <stdio.h>
#include <stdlib.h>

int main(){
	int t;
	long long int n, k;

	scanf("%d", &t);

	while(t-- > 0){
		scanf("%lld%lld", &n, &k);
		int e = k % 2;

		for(int i = 0; i < n; i++){
			if(e && n - 1 == i){
				printf("%d ", n - 1);
				continue;
			}
			if(n - 2 == i){
				printf("%d ", n);
				continue;
			}
			printf("%d ", n - 1 + e);
		}

		printf("\n");
	}
	return 0;
}