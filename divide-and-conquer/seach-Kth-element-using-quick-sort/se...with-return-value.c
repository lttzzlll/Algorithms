// using quick-sort to search kth element
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>

int input_data[100];

/* cnt global var define here for search count */
int cnt = 0;


void show(int *arr, int left, int right) {
	printf("before display the array\n");
	for(int i=left; i<=right; i++) {
		printf("%d ", arr[i]);
	}
	printf("\nafter display\n");
}

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void bubble_sort(int *arr, int left, int right) {
	// bubble sort define here
	for(int i=left; i<=right; i++) {
		for(int j=i+1; j<=right; j++) {
			if(arr[i] > arr[j] ) {
				swap(&arr[j], &arr[i]);
			}
		}
	}
}

void random_unique(int *arr, int n, int limit) {
	srand((unsigned)time(NULL));
	for(int i=0; i<n; i++) {
		for(int k=0; k<i;) {
			arr[i] = rand() % limit;
			for(k=0; k<i; k++) {
				if(arr[i] == arr[k]) {
					break;
				}
			}
			if(k==i) {
				break;
			}
		}
	}
}

int find_perpor_pivot_return_index(int *arr, int left, int right) {
	if(left+1>=right) {
		return left;
	}
	int middle = (right-left)/2 + left;
	if(arr[middle] >= arr[left] && arr[middle] <= arr[right]) {
		return middle;
	}else if(arr[left] >= arr[middle] && arr[left] <= arr[right]) {
		return right;
	}else {
		return right;
	}
}

int search_k_element(int *arr, int left, int right, int k) {
	if(left==right) {
		if(left==right) {
			return arr[left];
		}else {
			printf("error\n");
			exit(-1);
		}
	}

	int v, i, j;
	
	/* will be modify later */
	v = arr[left];

	i = left + 1;
	j = right;

	for(;;) {
		while(arr[i]<v) {
			i++;
		}
		while(arr[j]>v) {
			j--;
		}
		if(i<j) {
			swap(&arr[i], &arr[j]);
			i++;
			j--;
		}else {
			break;
		}
	}
	swap(&arr[j], &arr[left]);
	printf("in search %d times\n", cnt++);
	if(k <= j-left) {
		return search_k_element(arr, left, j-1, k);
	}else if(k==j-left+1) {
		// problem occurs here
		return arr[left+k-1];
	}else {
		return search_k_element(arr, j+1, right, k-(j-left)-1);
	}
}

void random_range(int *arr, int n, int min_limit) {
	srand((unsigned)time(NULL));
	for(int i=0; i<n; i++) {
		arr[i] = rand() % min_limit;
	}
}

int main() {

	int select, n, up_limit, min_limit, m;
	select = 1;
	n = 100;
	up_limit = n*100;
	min_limit = n; 
	if(select) {
		random_unique(input_data, n, up_limit);
	}else{ 
		random_range(input_data, n, min_limit);
	}

	show(input_data, 0, n-1);

	printf("enter a number between %d to %d: ", 1, n);
	scanf("%d", &m);
	if( m < 0 ||  m > n) {
		printf("enter error!\n");
		return -1;
	}

	// k is the result
	int k = search_k_element(input_data, 0, n-1, m);
	
	printf("%dth element is %d\n", m, k);

	// for check
	bubble_sort(input_data, 0, n-1);
	show(input_data, 0, n-1);
	printf("%dth element is %d\n", m, input_data[m-1]);


	return 0;
}
	

