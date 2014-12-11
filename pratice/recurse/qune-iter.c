#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define SIZE 1000

int rec[SIZE];
int gCnt = 0;
int n;
//                  0  1  2  3  4  5   6   7  8    9    10  11    12
int solve[SIZE] = { 0, 1, 0, 0, 2, 10, 4, 40, 92, 352, 724, 2680, 14200};

int his[SIZE][SIZE];


void display(int *arr, int start, int end) {
	for(int i=start; i<=end; i++) {
		printf("%4d", arr[i]);
	}
	printf("\n");
}

int check(int pos) {
	for(int i=1; i<pos; i++) {
		if(rec[i] == rec[pos] || abs(i-pos) == abs(rec[i] - rec[pos])) {
			return 0;
		}
	}
	return 1;
}


void f() {
	int row, col;
	row = 1;
	for(;row>0;) {
		for(col=rec[row]+1; col<=n; col++) {
			rec[row] = col;
			if(check(row)) {
				row++;
				break;
			}
		}
		if(col == n+1) {
			rec[row] = 0;
			row--;
		}
		if(row == n+1) {
			//display(rec, 1, n);
			memcpy(his+gCnt, rec, sizeof(int)*(n+1));
			gCnt++;
			if(gCnt == solve[n] / 2) {
				break;
			}
			rec[row-1] = 0;
			row -= 2;
		}
	}
}

int main(int argc, char *argv[]) {
	n = 8;

	if(argc == 2) {
		sscanf(argv[1], "%d", &n);
	}

	clock_t t = clock();
	f();
	t = clock() - t;
	printf("%d\n", solve[n]);
	printf("total clicks:: %lu | total secs %lf\n", t, (double)t / CLOCKS_PER_SEC );
	for(int i=0; i<gCnt; i++) {
		for(int j=1; j<=n; j++) {
			printf("%4d", his[i][j]);
		}
		printf("\n");
	}
	for(int i=0; i<gCnt; i++) {
		for(int j=n; j>=1; j--) {
			printf("%4d", his[i][j]);
		}
		printf("\n");
	}
	return 0;
}
