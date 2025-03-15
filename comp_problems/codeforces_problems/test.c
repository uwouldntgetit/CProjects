#include <stdio.h>

int main(){
	int x = 5;
	unsigned long long int k = 0;
	while(x-- > 0){
		printf("%llu\n", k - 1);
	}
	return 0;
}