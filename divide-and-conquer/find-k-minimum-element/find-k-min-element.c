// suppose no repeated elements
// this file is a primary version
// did not real patch
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int input_data[100];


void show(int *arr, int n) {
	printf("*************************\n");
	for(int i=0; i<n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("*************************\n");
}

void generic_sort(int *arr, int n) {
	for(int i=0; i<n; i++) {
		for(int j=i; j<n; j++) {
			if(arr[i]>arr[j]) {
				int t = arr[i];
				arr[i] = arr[j];
				arr[j] = t;
			}
		}
	}
}

int find_k_element(int *arr, int n,int k) {
	generic_sort(arr, n);
	return arr[k];
}

int main(int argc, char *argv[]) {

	int m = 10;

	srand((unsigned)time(NULL));

	for(int i=0; i<100; i++) {
		while(1) {
			input_data[i] = rand() % 10000;
			int j;
			for(j=0; j<i; j++) {
				if(input_data[i] == input_data[j]) {
					break;
				}
			}
			if(j==i) {
				break;
			}
		}
	}
		
	show(input_data, 100);

	int n = 100;
	if(m>n) {
		printf("input data is out of range\n");
		exit(-2);
	}
	int k = find_k_element(input_data, 100, m);

	printf("%d\n", k);

	show(input_data, 100);
	return 0;
}

