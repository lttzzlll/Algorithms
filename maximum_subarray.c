//  find maximum subarray

#include<stdio.h>
#define INF -9999999
#define NUM 100

int left, right, max_sum;
int left_low, left_high, left_sum;
int right_low, right_high, right_sum;
int cross_low ,cross_high, cross_sum;


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

int main() {
	return 0;
}
