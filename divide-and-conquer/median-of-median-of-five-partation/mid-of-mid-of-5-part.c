// median of median of five partationing
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int input_data[100];


void show(int *arr, int left, int right) {
	printf("in display\n");
	for(int i=left; i<=right; i++) {
		printf("%d ", arr[i]);
	}
	printf("\nend display\n");
}

void random_unique(int *arr, int n, limit) {
	srand((unsigned)time(NULL));
	for(int i=0; i<n; i++) {
		for(int j;;) {
			arr[i] = rand() % limit;
			for(j=0; j<i; j++) {
				if(arr[i] == arr[j]) {
					break;
				}
			}
			if(j==i) {
				break;
			}
		}
	}
}

void random_range(int *arr, int n, int limit) {
	srand((unsigned)time(NULL));
	for(int i=0; i<n; i++) {
		arr[i] = rand() % limit;
	}
}

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void bubble_sort(int *arr, int left, int right) {
	for(int i=left; i<=right; i++) {
		for(int j=i+1; j<=right; j++) {
			if(arr[j] < arr[i]) {
				swap(&arr[i], &arr[j]);
			}
		}
	}
}

// this function should be think carefully
int median_of_5_sort(int *arr, int left, int right) {
	// problem in here
	if(left + 4 != right) {
		printf("error occured\n");
		exit(-1);
	}
	if(arr[left+2] < arr[left] ) {
		swap(&arr[left+2], &arr[left]);
	}
	if(arr[left+2] < arr[left+1]) {
		swap(&arr[left+2], &arr[left+1]);
	}
	if(arr[left+2] > arr[right]) {
		swap(&arr[left+2], &arr[right]);
	}
	if(arr[left+2] > arr[right-1]) {
		swap(&arr[left+2], &arr[right-1]);
	}
	if(arr[left] > arr[right]) {
		swap(&arr[left], &arr[right]);
	}
	if(arr[left] > arr[right-1]) {
		swap(&arr[left], &arr[right-1]);
	}
	if(arr[left+1] > arr[right]) {
		swap(&arr[left+1], &arr[right]);
	}
	if(arr[left+1] > arr[right-1]) {
		swap(&arr[left+1], &arr[right-1]);
	}

	return arr[left+2];
}

int find_k_element(int *arr,int left, int right, int k) {
	if(left+4>right) {
		bubble_sort(arr, left, right);
		return arr[k-1];
	}
	if(left+
}

int main() {

	int select, int n, int k, uplimit, downlimit;
	select = 1;
	n = 100;
	uplimit = 1000;
	downlimit = n;

	if(select) {
		random_unique(input_data, n, uplimit);
	}else {
		random_range(input_data, n, downlimit);
	}

	show(input_data, 0, n-1);

	printf("enter a number between 0 - 100: ");
	scanf("%d", &k);


	return 0;
}
