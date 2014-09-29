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

int find_middle_element_return_index(int *arr, int left, int right) {
	if(left+2>right) {
		return left;
	}
	int middle = (right-left)/2 + left;
	if(arr[middle] >= arr[left] && arr[middle] <= arr[right]) {
		return middle;
	}else if( arr[left] >= arr[middle] && arr[left] <= arr[right]) {
		return left;
	}else {
		return right;
	}
}

// quick sort define 
void quick_sort(int *arr, int left, int right) {
	if(left>=right) {
		return ;
	}
	int i, j, v, pivot;
	/*
	v = arr[left];
	*/
	pivot = find_middle_element_return_index(arr, left, right);
	v = arr[pivot];
	swap(&arr[left], &arr[pivot]);
	
	i = left+1;
	j = right;

	for(;;) {
		while(arr[i]<v) {
			i++;
		}
		while(arr[j]>v) {
			j--;
		}
		if(i<j) {
			swap(&arr[i], &arr[j]);
			i++;
			j--;
		}else{
			break;
		}
	}
	swap(&arr[left], &arr[j]);
	quick_sort(arr, left, j-1);
	quick_sort(arr, j+1, right);
}

void random_unique(int *arr, int n) {
	srand((unsigned)time(NULL));
	for(int i=0; i<n; i++) {
		for(int j;j!=i;) {
			arr[i] = rand() % 10000;
			for(j=0; j<i; j++) {
				if(arr[i] == arr[j]) {
					break;
				}
			}
		}
	}
}

void random_range(int *arr, int n, int range) {
	srand((unsigned)time(NULL));
	for(int i=0; i<n; i++) {
		arr[i] = rand()  % range;
	}
}
// display a array
void show(int *arr, int end, int start) {
	for(int i=start; i<=end; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {
	int select = 0;
	if(select) {
		random_unique(input_data, 100);
	}else {
		random_range(input_data, 100, 100);
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
