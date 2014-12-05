#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10000
#define MAX_INF 99999999

int m[SIZE][SIZE];
int s[SIZE][SIZE];

typedef struct {
	int order;
	int row;
	int col;
}Matrix;

Matrix p[SIZE];

int matrix_chain_order(Matrix *p, int n) {
	
	for(int l=2; l<=n; l++) {
		for(int i=1; i<=n-l+1; i++) {
			int j = i + l - 1;
			m[i][j] = MAX_INF;
			for(int k=i; k<=j-1; k++) {
				int each_multiply_times = p[i].col;
				int each_add_times = each_multiply_times - 1;
				int multiply_times = p[i].row * p[j].col;
				int total_times = (each_multiply_times + each_add_times) * multiply_times;
				int q = m[i][k] + m[k+1][j] + total_times;
				if(q < m[i][j]) {
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
	
	return m[1][n];
}


void print_optimal_parens(Matrix *p, int s[][SIZE], int i, int j) {
	if(i > j) { return ;}
	if(i == j) { 
		printf("A%d", p[i].order);
	}else {
		printf("%c", '(');
		print_optimal_parens(p, s, i, s[i][j]);
		print_optimal_parens(p, s, s[i][j]+1, j);
		printf("%c", ')');
	}
}



int main() {
	// init data
	//         0  1   2   3   4  5   6   7
	//int a[] = {0, 30, 35, 15, 5, 10, 20, 25};
	int a[SIZE];
	memset(a, 0, sizeof(a));

	int n = 6;
	int limit = 50;
	int offset = 10;

	srand((unsigned)time(NULL));
	for(int i=0; i<=n; i++) {
		a[i] = rand() % limit + offset;
	}
	// set
	for(int i=1; i<=6; i++) {
		p[i].order = i;
		p[i].row = a[i-1];
		p[i].col = a[i];
	}
	//display
	for(int i=0; i<=n; i++) {
		printf("order=>%2d, row=>%2d, col=>%2d\n", p[i].order, p[i].row, p[i].col);
	}
	
	int res = 0;
	res = matrix_chain_order(p, n);
	printf("%d\n", res);
	
	print_optimal_parens(p, s, 1, n);
	printf("\n");	

	return 0;
}
