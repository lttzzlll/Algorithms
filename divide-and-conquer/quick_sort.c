// quick sort
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int input_data[100];

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

// find a proper pivot in array
int partition(int *arr, int left, int right) {
	int i = left;
	int j= right;
	int pos = rand() % (right+1-left) + left;

	while(i!=j) {
		while(i!=j && arr[i]<=arr[pos]) {
			i++;
		}
		if(i!=j) {
			swap(&arr[i], &arr[pos]);
			pos = i;
		}

		while(i!=j && arr[j]>=arr[pos]) {
			j--;
		}
		if(i!=j) {
			swap(&arr[j], &arr[pos]);
			pos = j;
		}
	}

	return i;
}

// quick sort define 
void quick_sort(int *arr, int left, int right) {
	if ( left == right) {
		return ;
	}

	int pivot = partition(arr, left, right);
	quick_sort(arr, left, pivot);
	quick_sort(arr, pivot+1, right);

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
	show(input_data, 99, 0);
	
	quick_sort(input_data, 0, 99);

	show(input_data, 99, 0);

	return 0;
}
