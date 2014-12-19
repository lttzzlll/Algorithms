
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 1000
#define MAX_INF 99999999
#define MIN_INF -99999999

int a[SIZE][SIZE];
int c[SIZE][SIZE];
int d[SIZE][SIZE];


int min(int a, int b) {
	return a < b ? a : b;
}

// recurse
int f(int i, int j) {
	if(i + 1 == j) { // directly acess the question space
		return a[i][j];
	}
	int res = MAX_INF, t = 0;
	for(int k=i+1; k<j; k++) {
		t = f(i, k) + f(k, j);
		if(t < res) {
			res =t;
		}
	}
	return res;
}

// from top to down
int dp(int i, int j) {
	if(i + 1 == j) {  // original question space
		return a[i][j];
	}
	if(c[i][j]) { // solve space
		return c[i][j];
	}

	int res = MAX_INF, t = 0;
	for(int k=i+1; k<j; k++) {
		t = dp(i, k) + dp(k, j);
		if(t < res) {
			res = t;
		}
	}
	c[i][j] = res;
	return c[i][j];
}


// from buttom to top
int DP(int n) {
	int t = MAX_INF;
	for(int l=1; l<=n-1; l++) {
		for(int i=1; i+l<=n; i++) {
			int j=i+l; 
			//printf("i=%d, j=%d\n", i, j);
			d[i][j] = MAX_INF;
			for(int k=i+1; k<j; k++) {
				t = MAX_INF;
				if(i + 1 == k && k + 1 == j) {
					t = a[i][k] + a[k][j];
				}else if(i + 1 == k) {
					t = a[i][k] + d[k][j];
				}else if(k + 1 == j) {
					t = d[i][k] + a[k][j];
				}else {
					t = d[i][k] + d[k][j];
				}
				if(t < d[i][j]) {
					d[i][j] = t;
				}
				//printf("t=%d\n", t);
			}
		}
	}
	return d[1][n];
}

// randomly generate the test data
void generate(int arr[][SIZE], int n, int base, int offset) {
	srand((unsigned)time(NULL));
	for(int i=1; i<=n-1; i++) {
		a[i][i+1] = rand() % base + offset;
		for(int j=i+2; j<=n; j++) {
			a[i][j] = rand() % base + a[i][j-1];
		}
	}
}

void display(int arr[][SIZE], int n) {
	for(int i=1; i<=n-1; i++) {
		for(int j=i+1; j<=n; j++) {
			printf("%4d", arr[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int n, base, offset;
	base = 10;
	offset = 1;
	n = 10;

	generate(a, n, base, offset);


	printf("%d\n", n);
	display(a, n);

	printf("%d\n", f(1, n));
	printf("%d\n", dp(1, n));
	printf("%d\n", DP(n));
	return 0;
}
