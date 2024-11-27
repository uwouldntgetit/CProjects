#include <stdio.h>
#include <assert.h>

int compra(int n, int m, int a, int b) {
	int res = 0, check = 0;

	if((b / m) > a)
		res = n * a;
	else {
		res += (n / m) * b;
		check = n % m;
		res += a * check < b ? a * check : b;
	}

    return res;
}

int main() {
    FILE *fr, *fw;
    int N, M, A, B;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");

    assert(4 == fscanf(fr, "%d%d%d%d", &N, &M, &A, &B));

    fprintf(fw, "%d\n", compra(N, M, A, B));
    fclose(fr);
    fclose(fw);
    return 0;
}
