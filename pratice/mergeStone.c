#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 1000

int q[SIZE][SIZE];
int s[SIZE][SIZE];
int sum[SIZE];

int max(int a, int b) {
	return a > b ? a : b;
}

int min(int a, int b) {
	return a < b ? a : b;
}

// hou ji xing????
// why ??? 
int f(int i, int j) {
	if(i == j) { // only just one stone heap
		return q[i][j];
	}
	if(s[i][j]) {
		return s[i][j];
	}
	int res = 0, t = 0;
	for(int k=i; k<j; k++) {
		t = f(i, k) + f(k+1, j);
		printf("t is %d ", t);
		if(t > res) {
			printf("t is %d\n", t);
			res = t;
		}
	}
	printf("res is %d\n", res);
	s[i][j] = res;
	printf("s[%d][%d] is %d\n", i, i, s[i][j]);
	return s[i][j];
}

int main() {
	int aa[] = {4, 4, 5, 9};
	int n = 4;
	
	for(int i=1; i<=n; i++) {
		// q is the qustion space
		// s is the solve space
		q[i][i] = aa[i-1];
	}



	printf("%d\n", f(1, 2));

	// print the solve space
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			printf("%4d", s[i][j]);
		}
		printf("\n");
	}


	return  0;
}
