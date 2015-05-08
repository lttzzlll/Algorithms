#include "merge_sort.h"
#include <stdlib.h>

// here the additional array is used for store the temproary array element
int *additionalArray = NULL;
int max_size = 0;

int * allocateAdditionalArray(int size) {
	if (additionalArray == NULL || max_size < size) {
		max_size = size;
		additionalArray = (int *)malloc(sizeof(int) * max_size);
		if (additionalArray == NULL) {
			exit(-1);
		}
	}

	return additionalArray;
}


// compare with qucik sort, the merge sort <conquer> [merge] procedure is complex
// while the quick sort <divide> procedure is complex
void merge(int *arr, int left, int mid, int right) {
	int i = left, j = mid + 1, pos = 0;
	// here is a function to obtain the additional array
	//int *pArr = (int *)malloc(sizeof(int) * (right - left + 1));
	int *pArr = allocateAdditionalArray(right - left + 1);
	
	for (;;) {
		// there is the complex place, but it is easy to comprehensioned
		while (i <= mid && arr[i] <= arr[j]) {
			pArr[pos++] = arr[i++];
		}

		if (i > mid) {
			while (j <= right) {
				pArr[pos++] = arr[j++];
			}
			break;
		}

		while (j <= right && arr[j] <= arr[i]) {
			pArr[pos++] = arr[j++];
		}

		if (j > right) {
			while (i <= mid) {
				pArr[pos++] = arr[i++];
			}
			break;
		}
	}

	// zero is a absolutely position while the [left] is a relative position
	for (i=0; i<pos; i++) {
		// here is the place that most bugs occured
		arr[left + i] = pArr[i];
	}

//	free(pArr);
}

// :name: merge sort
// :expectation time-consuming: O(n * log(n))
// :best time-consuming:  O(n * log(n))
// :worst time-consuming: O(n * log(n))
// :additional space-consuming: O(n)
// :stability: unstability
// :apply: n is big; but running slowly than quick sort
// :description: ...
void mergeSort(int *arr, int left, int right) {
	if (left < right) {
		int mid = (right - left) / 2 + left;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

// multiply implementation
void merge_sort(int *arr, int n) {
	mergeSort(arr, 0, n - 1);
}

void merge_sort_withSpace(int *arr, int n) {
	allocateAdditionalArray(n);
	mergeSort(arr, 0, n - 1);
	free(additionalArray);
}

void mergeSort_withoutRecursion(int *arr, int n) {
}

// top level invoke
void sort(int *arr, int n) {
//	merge_sort(arr, n);
    merge_sort_withSpace(arr, n);
//	merge_sort_withoutRecursion(arr, n);
}
