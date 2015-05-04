#include "insertion_sort.h"

// :name: insertion sort
// :expection time-consuming: O(n*2)
// :worst time-consuming: O(n*2)
// :best time-consuming: O(n)
// :space-consuming: O(n)
// :stability: stabile
// :apply: n is small
void insertion_sort(int *arr, int n) {
	int temp, i, j;
	for (i=1; i<n; i++) {
		temp = arr[i];
		for (j=i; j>0 && arr[j-1] > temp; j--) {
			arr[j] = arr[j-1];
		}
		arr[j] = temp;
	}
}

void sort(int *arr, int n) {
	insertion_sort(arr, n);
}
