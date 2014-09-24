//  find maximum subarray

#include<stdio.h>
#include<stdlib.h>

#define INF -9999999
#define NUM 100


int in_set[NUM] = {
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


// find max crossing subarray
int * find_max_crossing_subarray(int *arr, int low, int mid,  int high) {
	int left_sum , right_sum, max_left, max_right, total_sum, i;

	left_sum = right_sum = INF;
	max_left = max_right = mid;

	int *p = (int*)malloc(sizeof(int)*3);

	total_sum = 0;
	i = mid;
	while(i >= low) {
		total_sum += arr[i];
		if(total_sum > left_sum) {
			left_sum = total_sum;
			max_left = i;
		}
		i--;
	}

	total_sum = 0;
	i = mid + 1;
	while(i <= high) {
		total_sum += arr[i];
		if(total_sum > right_sum) {
			right_sum = total_sum;
			max_right = i;
		}
		i++;
	}

	p[0] = max_left;
	p[1] = max_right;
	p[2] = left_sum + right_sum;
	
	return p;
}

// find maximum subarray
int * find_maximum_subarray(int *arr, int low, int high) {
	int mid;
	int left_low, left_high, left_sum;
	int right_low, right_high, right_sum;
	int cross_low, cross_high, cross_sum;

	int *p = (int*)malloc(sizeof(int)*3);
	int *l = (int*)malloc(sizeof(int)*3);
	int *r = (int*)malloc(sizeof(int)*3);
	int *c = (int*)malloc(sizeof(int)*3);

	if(high == low) {
		p[0] = low;
		p[1] = high;
		p[2] = arr[low];
		return p;
	}else {
		mid = (low + high)/2;
		l = find_maximum_subarray(arr, low, mid);
		r = find_maximum_subarray(arr, mid+1, high);
		c = find_max_crossing_subarray(arr, low, mid, high);

		if(l[2] >= r[2] && l[2] >= c[2]) {
			return l;
		}else if( r[2] >= l[2] && r[2] >= c[2]) {
			return r;
		}else {
			return c;
		}
	}
}

int main() {
	int *p;
	p = find_maximum_subarray(in_set, 0 , sizeof(in_set)/4-1);
	printf("%d   %d   %d\n", p[0], p[1], p[2]);
	return 0;
}

/*
void find_max_crossing_subarray(int *arr, int low, int mid, int high) {
	int left_sum ,right_sum, max_left, max_right, total_sum, i;

	left_sum = right_sum = INF;
	max_left = max_right = mid;

	total_sum = 0;
	i = mid;
	while(i >= low) {
		total_sum += arr[i];
		if(total_sum > left_sum) {
			left_sum = total_sum;
			max_left = i;
		}
		i--;
	}

	total_sum = 0;
	i = mid;
	while(i <= high) {
		total_sum += arr[i];
		if(total_sum > right_sum) {
			right_sum = total_sum;
			max_right = i;
		}
		i++;
	}
}

// find maximum subarray
void find_maximum_subarray(int *arr, int low, int high) {
	int mid;

	if(high == low) {
		left = low;
		right = high;
		max_sum = arr[low];
		return ;
	}
	
	mid = (low + high) / 2;
	find_maximum(
}	
*/

/*
int main() {
	return 0;
}
*/
