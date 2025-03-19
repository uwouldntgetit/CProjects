#include <stdio.h>

int main(){
	int n = 1;
	// little endian if true
	if(*(char *)&n == 1)
		printf("Yes\n");
	else
		printf("No\n");
}