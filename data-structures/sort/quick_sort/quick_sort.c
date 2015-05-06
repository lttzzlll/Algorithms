#include "quick_sort.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h> // for log

// diaplay the array
void display(int *arr, int left, int right) {
	for (int i=left; i<=right; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void swap2Ints(int *num1, int *num2) {
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

// select the pivot element
// there may be better method to do it!
int pivotSelection(int *arr, int left, int right) {
	return random() % (right - left + 1) + left;
}

int partation(int *arr, int left, int right) {
	int i, j, v, pivot;

	v = pivotSelection(arr, left, right);
	pivot = arr[v];	
	swap2Ints(&arr[left], &arr[v]);

	i = left + 1;
	j = right;

	for (;;) {
		while (i <= right && arr[i] < pivot) {
			i++;
		}
		while (j >= left && arr[j] > pivot) {
			j--;
		}
		if (i < j) {
			swap2Ints(&arr[i], &arr[j]);
			i++;
			j--;
		}else {
			break;
		}
	}
	swap2Ints(&arr[left], &arr[j]);
	return j;
}

void Qsort(int *arr, int left, int right) {
	if (left >= right) {
		return ;
	}
	int pivot = partation(arr, left, right);
	Qsort(arr, left, pivot - 1);
	Qsort(arr, pivot + 1, right);
}

// so what's  the advantages of this version ?
// ++i, --j, in my opinion, just two different style, both are the same time-complexity
void qSort_bookVersion(int *arr, int left, int right) {
	int i, j, pivot, v;
	if (left >= right) {
		return ;
	}

	v = (random() % (right - left + 1)) + left;
	pivot = arr[v];
	swap2Ints(&arr[left], &arr[v]);
	i = left;
	j = right + 1;

	for (;;) {
		while (arr[++i] < pivot && i <= right) {}

		while (arr[--j] > pivot && j >= left) {}
		
		if (i < j) {
			swap2Ints(&arr[i], &arr[j]);
		}else {
			break;
		}
	}


//	printf("i==%d, j==%d i - j == %d pivot = %d [%d, %d]\n", i, j, i - j, pivot, left, right); // i - j == 1, or 0
	swap2Ints(&arr[left], &arr[j]);
	qSort_bookVersion(arr, left, j - 1);
	qSort_bookVersion(arr, j + 1, right);
}


// i - j == 1 [排序的元素互异]
// i - j == 0 [排序的元素中有相同的元素, 选取的枢纽元素与待排序的元素中有相等的]
// 在这种情况下, 快速排序是不稳定的, 因为他交换了两个相同的元素, 这两个相同的元素肯定是异位的
// :name: quick sort
// :expectation time-consuming: O(n * log(n))
// :best time-consuming: O(n * log(n))
// :worst time-consuming: O(n * 2)
// :extra space-consuming: O(1)
// :stability: unstability
// :apply: n is very big
// :description: the good sort method and used everywhere
void qSort(int *arr, int left, int right) {
	int i, j, pivot, v;
	if (left  >= right) {  // only just one element
		return ; 
	}
		
	v = (random() % (right - left + 1)) + left;
	pivot = arr[v];
	swap2Ints(&arr[left], &arr[v]);
	i = left + 1;
	j = right;

	for (;;) {
		while (i <= right && arr[i] < pivot) {
			i++;
		}
		while (j >= left && arr[j] > pivot) {
			j--;
		}
		if (i < j) {
			swap2Ints(&arr[i], &arr[j]);
			i++;
			j--;
		}else {
//			printf("i==%d, j==%d i - j == %d\n", i, j, i - j); // i - j == 1, or 0
			break;
		}
	}

//	printf("i==%d, j==%d i - j == %d pivot = %d [%d, %d]\n", i, j, i - j, pivot, left, right); // i - j == 1, or 0
//	display(arr, 0, 9);
	swap2Ints(&arr[left], &arr[j]);
	qSort(arr, left, j - 1);
	qSort(arr, j + 1, right);
}

/*
// the bad code sample!!
void qSort1(int *arr, int left, int right) {
	int i, j, v, pivot;
	if (left >= right) {
		return ;
	}
	v = (random() % (right - left + 1)) + left;
	pivot = arr[v];
	swap2Ints(&arr[left], &arr[v]);

	i = left + 1;
	j = right;

	for (;i <= j;) { // error in here: IndexOutoutRange
					// i > right ??
		while (arr[i] < pivot) {
			i++;
		}
		while (arr[j] > pivot) {
			j--;
		}
		if (i < j) {
			swap2Ints(&arr[i], &arr[j]);
			i++;
			j--;
		}else {
			// for log if i is equal to j i == j ?
			printf("i==%d, j==%d\n", i, j);
			break;
		}
	}
	swap2Ints(&arr[left], &arr[j]);
	qSort1(arr, left, j - 1);
	qSort1(arr, j + 1, right);
}
*/

void quick_sort(int *arr, int n) {
	Qsort(arr, 0, n - 1);	
}

void sort(int *arr, int n) {
	srand((unsigned)time(NULL));
	quick_sort(arr, n);
}

