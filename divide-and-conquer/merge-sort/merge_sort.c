// merge sort
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int input_data[100];

// merge two array into one
int *  merge(int *arr, int left, int middle, int right) {
	int *t = (int*)malloc(sizeof(int) * (right + 1 - left));
	int i = left;
	int j = middle + 1;
	int pos = 0;
	if ( middle + 1 - left > right - middle ) {
		while(i <= middle) {
			if(j<=right && arr[j] < arr[i]) {
				t[pos++] = arr[j++];
				continue;
			}
			t[pos++] = arr[i++];
		}
		while(j<=right) {
			t[pos++] = arr[j++];
		}
	}else {
		while(j <= right) {
			if(i<=middle && arr[i] < arr[j]) {
				t[pos++] = arr[i++];
				continue;
			}
			t[pos++] = arr[j++];
		}
		while(i<=middle) {
			t[pos++] = arr[i++];
		}
	}
	
	for(i=0, j=left; i<pos; i++,j++) {
		arr[j] = t[i];
	}
	return t;
}

// merge sort
void merge_sort(int *arr, int left, int right) {
	if ( left == right) {
		return;
	}

	int middle = left + (right - left) / 2;

	merge_sort(arr, left, middle);
	merge_sort(arr, middle+1, right);
	int *tmp = merge(arr, left, middle, right);
	free(tmp);
}

// show a array
void show(int *arr, int left, int right) {
	for(int i=left; i<=right; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {
	
	srand((unsigned)time(NULL));
	for(int i=0; i<100; i++) {
		input_data[i] = rand() % 100;
	}
	show(input_data, 0, 99);
	merge_sort(input_data, 0, 99);
	show(input_data, 0, 99);
	return 0;
}
