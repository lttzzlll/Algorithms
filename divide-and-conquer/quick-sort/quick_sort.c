// quick sort
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int input_data[100];

void show(int *arr, int end, int start);

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

// quick sort define 
void quick_sort(int *arr, int left, int right) {
	// element < 3 count 
	int i, j;
	if ( left + 2 >= right) {
		for(i=left; i<=right; i++) {
			for(j=i+1; j<=right; j++) {
				if(arr[i]>arr[j]) {
					swap(&arr[i], &arr[j]);
				}
			}
		}
		return ;
	}
	int pivot = arr[left];
	i = left+1;
	j = right;

	while(i!=j) {
		while(i!=j && arr[i] <= pivot) {
			i++;
		}
		while(i!=j && arr[j] > pivot) {
			j--;
		}
		if(i!=j) {
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[left], &arr[i-1]);

	quick_sort(arr, left, i-1);
	quick_sort(arr, i, right);
}

// display a array
void show(int *arr, int end, int start) {
	for(int i=start; i<=end; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {
	srand((unsigned)time(NULL));
	for(int i=0; i<100;i++) {
		input_data[i] =rand() % 100;
	}

	printf("origin array\n");
	show(input_data, 99, 0);

	// test
	//partition(input_data, 0, 99);
	//printf("after partition\n");
	//show(input_data, 99, 0);
	//return 0;
	
	quick_sort(input_data, 0, 99);

	printf("after sort\n");
	show(input_data, 99, 0);

	return 0;
}
