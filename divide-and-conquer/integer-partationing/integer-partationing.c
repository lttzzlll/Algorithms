// integer partationing
#include<stdio.h>

// return the number of partations
int integer_partationing(int n, int m) {
	if(n<1 || m<1) return 0;
	if(n==1 || m==1) return 1;
	if(n < m) return integer_partationing(n, n);
	if(n == m) return integer_partationing(n, m-1) + 1;
	// n > m
	return integer_partationing(n-m, m) + integer_partationing(n, m-1);
}

int main() {
	int t = 6;
	int m = t;
	int n = integer_partationing(t, m);
	printf("%d\n", n);

	return 0;
}
