// counting sort 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define LIMIT 1000
#define SIZE 101

void random_range(int *arr, int l, int r, int limit) {
	srand((unsigned)time(NULL));
	for(int i=l; i<=r; i++) {
		arr[i] = rand() % limit;
	}
}

void display(int *arr, int l, int r) {
	printf("in display\n");
	for(int i=l; i<=r; i++) {
		printf("%d ", arr[i]);
	}
	printf("\nend display\n");
}

void counting_sort(int *a, int *b, int l, int r, int k) {
	int c[SIZE];

	for(int i=0; i<=k; i++) {
		c[i] = 0;
	}

	for(int j=1; j<=r; j++) {
		c[a[j]] = c[a[j]] + 1;
	}

	for(int i=1; i<=k; i++) {
		c[i] = c[i] + c[i-1];
	}

	for(int j=r; j>=1; j--) {
		b[c[a[j]]] = a[j];
		c[a[j]] = c[a[j]] - 1;
	}

}

int main() {
	// test block 
	int a[SIZE];
	int b[SIZE];
	int limit = 100;
	int n = 100;

	random_range(a, 1, n, limit);

	display(a, 1, n);

	counting_sort(a, b, 1, n, limit);

	display(b, 1, n);

	return 0;
}

