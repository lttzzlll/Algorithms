// cycle competation 
#include<stdio.h>

int a[129][129];

int power(int n, int k) {
	int r = 1;
	for(int i=0; i<k; i++) {
		r *= n;
	}
	return r;
}

// if there is another way to do it?
void cycle(int a[][129], int k) {
	int n = 1;
	for(int i=1; i<=k; i++) { n *= 2; }

	for(int i=1; i<=n; i++) { a[i][1] = i; }

	// two loop: one is for population, other is for copy
	for(int t=1; t<n; t*=2) { // 1 2 4 

		for(int p=1; p<=n/2/t; p++)  // looptimes: 1 2 3 4 || 1 2 || 1
		{

		// [right][down] = [left][up]
		// copy scope
		printf("<down, right> := <up, left>\n");
		for(int i=0; i<t; i++) {
			for(int j=0; j<t; j++) {
				int tmp = (p-1)*power(2, t);;
				// [right][down] = [left][up]
				a[i+t+1+tmp][j+t+1] = a[i+1+tmp][j+1];
				printf("[%d, %d](%d) := [%d, %d](%d)  ", i+t+1+tmp, j+t+1, a[i+t+1+tmp][j+t+1], i+1+tmp, j+1, a[i+1+tmp][j+1]);
			}
			printf("\n");
		}
		printf("\n");

		printf("<up, right> := <down, left>\n");
		for(int i=0; i<t; i++) {
			for(int j=0; j<t; j++) {
				int tmp = (p-1)*power(2, t);
				// [right][up] := [left][down]
				a[i+1+tmp][j+t+1] = a[i+t+1+tmp][j+1];
				printf("[%d, %d](%d) := [%d, %d](%d)  ", i+1+tmp, j+t+1, a[i+1+tmp][j+t+1], i+t+1+tmp, j+1, a[i+t+1+tmp][j+1]);
			}
			printf("\n");
		}
		printf("\n\n");
	}

	}
}

void display(int a[][129], int k) {
	int n = 1;
	for(int i=1; i<=k; i++) { n *= 2; }
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			printf("%2d ", a[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int k;
	printf("enter k==> n = 2**k: ");
	scanf("%d", &k);
	cycle(a, k);
	display(a, k);
	return 0;
}
