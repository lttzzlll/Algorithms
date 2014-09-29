// using quick-sort to search kth element
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int input_data[100];

void show(int *arr, int left, int right) {
	printf("before display the array\n");
	for(int i=left; i<=right; i++) {
		printf("%d ", arr[i]);
	}
	printf("\nafter display\n");
}

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void bubble_sort(int *arr, int left, int right) {
	// bubble sort define here
	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {
			if(arr[j] > arr[i] ) {
				swap(&arr[j], &arr[i]);
			}
		}
	}
}

void random_unique(int *arr, int n, int up_limit) {
	srand((unsigned)time(NULL));
	for(int i=0; i<n; i++) {
		for(int k=0; k<i;) {
			arr[i] = rand() % up_limit;
			for(k=0; k<i; k++) {
				if(arr[i] == arr[k]) {
					break;
				}
			}
			if(k==i) {
				break;
			}
		}
	}
}

int search_k_element(int *arr, int left, int right, int k) {
	if(left+k>right) {
		bubble_sort(arr, left, right);
		return arr[k-1];
	}

}
void random_range(int *arr, int n, int min_limit) {
	srand((unsigned)time(NULL));
	for(int i=0; i<n; i++) {
		arr[i] = rand() % min_limit;
	}
}

int main() {

	int select, n, up_limit, min_limit, m, k;
	select = 0;
	n = 100;
	up_limit = n*100;
	min_limit = n; 
	if(select) {
		random_unique(input_data, n, up_limit);
	}else{ 
		random_range(input_data, n, min_limit);
	}
	
	m = 50;

	k = seach_k_element(input_data, 0, n-1, m);
	
	printf("%dth element is %d\n", m-1, k);

	bubble_sort(input_data, 0, n-1);
	printf("%dth element is %d\n", m-1, k);
	show(input_data, 0, n-1);

	return 0;
}
	

