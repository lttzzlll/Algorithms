#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 1000

int s[SIZE][SIZE];
int c[SIZE][SIZE];
int a[SIZE];

// states transfer function
// f[i, n] = max{ f[i,  k] + f[i+k, n-k]}
// i <= k <= j
// i == j  a[i][i] = {}
int fmax(int i, int j) {
	//printf("in fmax\n");
	if(i > j) {
		return 0;
	}
	if(i == j) {
		return a[i];
	}
	int res = 0, t = 0;
	for(int k=i; k<=j; k++) {
		t = fmax(i, k) + fmax(i+k, j-k);
		if(t > res) {
			res = t;
		}
		printf("i=%d, j=%d, t=%d, res=%d\n", i, j, t, res);
	}
	return res;
}

int fmin(int i, int j) {
	return 0;
}

//  4 4 5 9
void init() {
	a[1] = 4;
	a[2] = 4;
	a[3] = 5;
	a[4] = 9;
	c[1][1] = 4;
	c[2][2] = 4;
	c[3][3] = 5;
	c[4][4] = 9;
}

int main() {
	init();

	int n;

	n = 4;

	n = 2;
	printf("%d\n", fmax(1, n));
	printf("%d\n", fmin(1, n));

	return 0;
}

