// discard recurs about merge sort
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int input_data[100];

// swap two integer value
void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

// merge sort :: no recursion
void merge_sort(int *arr, int left, int right) {
	int i, j, k;
	
}

// display an array
void show(int *arr, int l, int r) {
	for(int i=l; i<=r; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {

	srand((unsigned)time(NULL));

	for(int i=0; i<100; i++) {
		input_data[i] = rand() % 100;
	}

	printf("before sort\n");
	show(input_data, 0, 99);

	merge_sort(input_data, 0, 99);

	printf("after sort\n");
	show(input_data, 0, 99);

	return 0;
}


