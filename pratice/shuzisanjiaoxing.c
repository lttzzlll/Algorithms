#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

int a[SIZE][SIZE];
int s[SIZE][SIZE];

int n;

int max(int a, int b) {
	return a > b ? a : b;
}

int f(int i, int j) {
	if(i > n || j > n) {
		return 0;
	}
	return max(f(i+1, j+1), f(i+1, j)) + a[i][j];
}

int dp() {
	for(int i=n; i>=1; i--) {
		for(int j=n; j>=1; j--) {
			s[i][j] = max(s[i+1][j], s[i+1][j+1]) + a[i][j];
		}
	}
	return s[1][1];
}

int main() {
	n = 5;
	
	limit = 10;
	offset = 1;
	srand((unsigned)time(NULL));
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=i; j++) {
			a[i][j] = rand() % limit + offset;
		}
	}

	printf("%d\n", f(1, 1));
	printf("%d\n", dp());
	return 0;
}
