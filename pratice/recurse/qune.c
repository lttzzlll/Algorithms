#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define SIZE 1000
                  //0  1  2  3  4   5  6  7   8   9    10   11    12
int solve[SIZE] = { 0, 1, 0, 0, 2, 10, 4, 40, 92, 352, 724, 2680, 14200};

int his[SIZE][SIZE];

int rec[SIZE];
int n;
int gCnt = 0;

void dis(int *arr, int start, int end) {
	for(int i=start; i<=end; i++) {
		printf("%4d", arr[i]);
	}
	printf("\n");
}


int check(int pos) {
	for(int i=1; i<pos; i++) {
		if(rec[i] == rec[pos] || abs(i-pos) == abs(rec[i]-rec[pos])) {
			return 0;
		}
	}
	return 1;
}

void f(int pos) {
	if(gCnt == solve[n] / 2 ) { return ; }
	if(pos > n) {
		gCnt++;
		memcpy(his+gCnt, rec+1, sizeof(int) * n);
		//dis(rec, 1, n);
		return ;
	}
	for(int i=1; i<=n; i++) {
		rec[pos] = i;
		if(check(pos)) {
			f(pos+1);
		}
	}
}


int main(int argc, char *argv[]) {
	n = 8;

	if(argc == 2) {
		sscanf(argv[1], "%d", &n);
	}

	clock_t t = clock();
	f(1);
	t = clock() - t;

	printf("%d\n", solve[n]);
	printf("total clicks:: %lu | total secs: %lf\n", t, (double)t / CLOCKS_PER_SEC);

	for(int i=1; i<=gCnt; i++) {
		for(int j=0; j<n; j++) {
			printf("%4d", his[i][j]);
		}
		printf("\n");
	}
	for(int i=1; i<=gCnt; i++) {
		for(int j=n-1; j>=0; j--) {
			printf("%4d", his[i][j]);
		}
		printf("\n");
	}
	return 0;
}

