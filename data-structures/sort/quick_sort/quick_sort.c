#include <stdlib.h>
#include <time.h>
#include <stdio.h> // for log

void swap2Ints(int *num1, int *num2) {
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

int partation(int *arr, int left, int right) {
	int i, j, pos, pivot;

	i = left;
	j = right;
	pos = (random() % (right - left + 1)) + left;		
	pivot = arr[pos];	

	swap2Ints(&arr[i], &arr[pos]);

	i += 1;
	for (;;) {
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
			break;
		}
	}
	swap2Ints(&arr[left], &arr[j]);
	return j;
}

void qSort(int *arr, int left, int right) {
	if (left  >= right) {  // only just one element
		return ; 
	}
		
	int pos = partation(arr, left, right);
	qSort(arr, left, pos - 1);
	qSort(arr, pos + 1, right);
}

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

	for (;i <= j;) {
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

void quick_sort(int *arr, int n) {
	qSort1(arr, 0, n - 1);	
}

void sort(int *arr, int n) {
	srand((unsigned)time(NULL));
	quick_sort(arr, n);
}

