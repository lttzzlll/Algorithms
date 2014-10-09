// 循环赛日程表
#include<stdio.h>
#include<stdlib.h>

int a[65][65];

void cycle(int k, int a[][65]) {
	int n = 1;

	for(int i=1; i<=k; i++) { n *= 2; }
	for(int i=1; i<=n; i++) { a[1][i] = i; }
	
	int m = 1;
	for(int s=1; s<=k; s++) {
		n /= 2;
		for(int t=1; t<=n; t++) {
			for(int i=m+1; i<=2*m; i++) {
				for(int j=m+1; j<=2*m; j++) {
					// down  right       up    left
					a[i][j+(t-1)*m*2] = a[i-m][j+(t-1)*m*2-m];
					// down left         up    right
					a[i][j+(t-1)*m*2-m] = a[i-m][j+(t-1)*m*2];
				}
			}
		}
		m *= 2;
	}
}

// failed
void cycle2(int k, int a[][65]) {
	int n = 1;

	for(int i=1; i<=k; i++) { n *= 2; }
	for(int i=1; i<=n; i++) { a[i][1] = i; }

	int m = 1;
	for(int s=1; s<=k; s++) {
		n /= 2;
		for(int t=1; t<=n; t++) {
			for(int i=m+1; i<=2*m; i++) {
				for(int j=m+1; j<=2*m; j++) {
					// down right     =   up    left
					a[i][j+(t-1)*m*2] = a[i-m][j+(t-1)*m*2-m];
					// up   right     =   down  left
					a[i-m][j+(t-1)*m*2] = a[i][j+(t-1)*m*2-m];
				}
			}
		}
		m *= 2;
	}
}

void display(int arr[][65], int k) {
	int n = 1;
	for(int i=1; i<=k; i++) { n *= 2; }
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int k = 3;
	cycle(k, a);
	display(a, k);
	return 0;
}
