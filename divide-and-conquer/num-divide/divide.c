#include <stdio.h>

int div(int n, int m) {
	// how to solve it ??
	printf("n==%d, m==%d\n", n, m);
	if (n == 1) {
		return 1;
	}
	if (m == 1) {
		return 0;
	}
	if (n == m) {
		printf("+ | n==%d, m==%d\n", n, m);
		return div(n, m-1) + 1;
	}
	if (n < m) {
		return div(n, n);
	}
	if (n > m) {
		return (n % m == 0 ? div(m, m) : 0) + div(n, m-1);
	}
	
	return 0; // default port?? 
}


int main(int argc, char *argv[]) {
	int n;
	int res = 0;

	scanf("%d", &n);
	
	res = div(n, n);

	printf("%d\n", res);

	return 0;
}
