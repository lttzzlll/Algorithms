// find k th element without sort
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int input_data[100];

void show(int *arr, int n) {
	for(int i=0; i<n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void random_unique(int *arr, int n, int up_limit) {
	srand((unsigned)time(NULL));
		
	for(int i=0; i<n; i++) {
		arr[i] = rand() % up_limit;
		while(1) {
			int j;
			for(j=0; j<i; j++) {
				if(arr[j] == arr[i]) {
					break;
				}
			}
			if(j==i) {
				break;
			}
		}
	}
}

int cmp(const void *a, const void *b) {
	return *(int*)a > *(int*)b;
}

void sort(int *arr, int n) {
	//qsort(arr, sizeof(int), n, cmp);

	// generic sort
	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {
			if(arr[i]>arr[j]) {
				int t = arr[i];
				arr[i] = arr[j];
				arr[j] = t;
			}
		}
	}
}

void bubble_sort_large_to_small(int *arr, int n) {
	for(int i=0; i<n; i++) {
		int maxi = i;
		for(int j=i+1; j<n; j++) {
			if(arr[j]>arr[maxi]) {
				maxi = j;
			}
		} { // swap two integer
			int t = arr[i];
			arr[i] = arr[maxi];
			arr[maxi] = t;
		}
	}
}

int find_k_element(int *arr, int n, int k) {
	int *p = (int*)malloc(sizeof(int)*k);
	if(p==NULL) {
		printf("no free space\n");
		exit(-1);
	}

	// copy to new array
	for(int i=0; i<k; i++) {
		p[i] = arr[i];
	}

	// sort it
	sort(p, k);
	/*
	printf("in find\n");
	show(p, k);
	printf("end find\b");
	*/

	// core 
	for(int i=k; i<n; i++) {
		int j;
		for(j=k-1; j>=0; j--) {
			if(arr[i]>p[j]) {
				j++;
				break;
			}
		}
		for(int l=k-1; l>j; l--) {
			p[l] = p[l-1];
		}
		p[j] = arr[i];
	}

	// k element
	return p[k-1];
}

int main() {
	
	int up_limit = 10000;
	int n = 100;
	int m = 50;

	random_unique(input_data, n, 10000);

	printf("before sort\n");
	show(input_data, n);

	if(m>n) {
		printf("error\n");
		exit(-1);
	}

	int k = find_k_element(input_data, n, m);

	printf("%dth element is %d\n", m, k);
	
	sort(input_data, n);

	//bubble_sort_large_to_small(input_data, 100);
	printf("after sort\n");
	show(input_data, n);
	printf("%dth element is %d\n", m, input_data[m-1]);

	return 0;
}
