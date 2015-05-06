#include <stdio.h>


void swap2Ints(int *num1, int *num2) {
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

// :name: bubble sort
// :expection time-consuming: O(n*2)
// :worst time-consuming: O(n*2)
// :best time-consuming: O(n)
// :stability: stabile
// :extra space-consuming: O(1)
// :apply: n is samll
// :description: select a biggest element each time and put it at the 'last position'
void bubble_sort(int *arr, int n) {
    int flag = 0; // the swap flag
    for (int i=0; i<n-1; i++) { // loop times
        flag = 0; // always assume there have no swap
        for (int j=0; j<n-i-1; j++) { // swap positions
			if (arr[j] > arr[j+1]) {
				swap2Ints(&arr[j], &arr[j+1]);
                flag = 1; // swaped
            }
		}
        if (flag == 0) { // no swaped, the sequence is in order
            break;       // so break
        }
	}
}

// select a samllest element each time and put it a the 'first position'
void bubble_sort_anotherMethod(int *arr, int n) {
	for (int i=0; i<n-1; i++) { // loop times
		for (int j=n-1; j>i; j--) {
			if (arr[j-1] > arr[j]) { // swap positions
				swap2Ints(&arr[j], &arr[j-1]);
			}
		}
	}
}

// PROMOTION: each loop it can put the biggest to the right position and
// put the samllest to the left condition
void cocktail_sort(int *arr, int n) {
	int i, left = 0, right = n - 1;
	while (left  < right) {
		for (i=left; i<right; i++) {
			if (arr[i] > arr[i+1]) {
				swap2Ints(&arr[i], &arr[i+1]);
            }
		}
		right--;
        
		for (i=right; i>left; i--) {
			if (arr[i] < arr[i-1]) {
                swap2Ints(&arr[i], &arr[i-1]);
            }
		}
		left++;
	}
}

// PROMOTION: best time-consuming: O(n)
void bubble_sort_advanced(int *arr, int n) {
	int flag = 1;
	int i, len = n;
	while (flag) {
		flag = 0;
		for (i=0; i<len-1; i++) {
			if (arr[i] > arr[i+1]) {
				swap2Ints(&arr[i], &arr[i+1]);
				flag = 1;
			}
		}
		len--;
	}
}

void sort(int *arr, int n) {
	bubble_sort(arr, n);
}

