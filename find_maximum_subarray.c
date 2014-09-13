// this file is find maximum subarray
// use two loop
#include<stdio.h>
#include<stdlib.h>

// input data
int input_data[]= {
	13,
	-3,
	-25,
	20,
	-3,
	-16,
	-23,
	18,
	20,
	-7,
	12,
	-5,
	-22,
	15,
	-4,
	7
};

// find maximum subarry , return triple tuple
// it cause momery dispose but not to much
// how to collect the momery ? ? ?
int * find_maximum_subarray(int *arr, int length) {
	int * triple_tuple = (int *)malloc(sizeof(int) * 3);
	int i, j, l, r, max_sum, total_sum;
	max_sum = -9999999;
	total_sum = 0;
	for (i=0; i < length; i++) {
		total_sum = 0;
		for (j=i; j < length; j++) {
			total_sum += arr[j];
			if ( total_sum > max_sum ) {
				max_sum = total_sum;
				l = i;
				r = j;
			}
		}
	}
	triple_tuple[0] = l;
	triple_tuple[1] = r;
	triple_tuple[2] = max_sum;
	return triple_tuple;
}

int main() {

	int *p, i, length, l, r, max_value;
	length = sizeof(input_data) / sizeof(int);

// original value
	printf(" sample input data is below\n");
	for(i=0; i<length; i++) {
		printf("%d ", input_data[i]);
	}
	printf("\n");

	p = find_maximum_subarray(input_data, length);
	l = p[0];
	r = p[1];

	max_value = p[2];

	printf("l==%d, r==%d, max_value==%d\n", l, r, max_value);

	for(i=l; i<=r; i++) {
		printf("%d ", input_data[i]);
	}
	printf("\n");

// each value in input data is negetive
	for(i=0; i < length; i++) {
		if( input_data[i] > 0 ) {
			input_data[i] *= -1;
		}
	}

	printf(" smaple negative input data is below\n");
	for(i=0; i<length; i++) {
		printf("%d ", input_data[i]);
	}
	printf("\n");

	p = find_maximum_subarray(input_data, length);
	l = p[0];
	r = p[1];
	max_value = p[2];

	printf("l==%d, r==%d max_value==%d\n", l, r, max_value);

	for(i=l; i<=r; i++) {
		printf("%d ", input_data[i]);
	}
	printf("\n");

	return 0;
}

