// using quick-sort to search kth element
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>

int input_data[100];

const int minimum_limit = 75;;

/* cnt global var define here for search count */
int cnt = 0;

void bubble_sort(int *arr, int left, int right);

int cmp(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

// use multiply sort methods
void sort(int *arr, int left, int right, int option) {
	if(option == 0) {
		qsort(arr, right-left+1, sizeof(arr[left]), cmp);
	}else {
		bubble_sort(arr, left, right);
	}
}

int randomize(int down, int up) {
	srand((unsigned)time(NULL));
	return down + rand() % (up - down + 1);
}

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

//	in a view , this is a good idea to find a item
int find_perpor_pivot_return_index(int *arr, int left, int right) {
	if(left+1>=right) {
		return left;
	}
	int middle = (right-left)/2 + left;
	if(arr[middle] >= arr[left] && arr[middle] <= arr[right]) {
		return middle;
	}else if(arr[left] >= arr[middle] && arr[left] <= arr[right]) {
		return left;
	}else {
		return right;
	}
}

// will modify
int search_k_element(int *arr, int left, int right, int k) {
	if(left==right) {
		if(k==1) {
			return arr[left];
		}else {
			printf("left is %d right is %d, k is %d ###error\n", left, right, k);
			exit(-1);
		}
	}

	int v, i, j, pivot;
	
	/* will be modify later */
	pivot = randomize(left, right);
	v = arr[pivot];
	swap(&arr[pivot], &arr[left]);

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

//
int partationing(int *arr, int left, int right, int partation) {
	if(left == right) {
		return left;
	}
	
	int i, j, pivot;

	// find the position of partation
	for(i=left; i<=right; i++) {
		if(arr[i] == partation) {
			pivot = i;
			break;
		}
	}


	i = left;
	j = right;

//	printf("in partationing before partate\n");
	for(;;) {
		while(arr[i] <= partation) {
			i++;
		}
		while(arr[j] > partation) {
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
//	printf(" in partationing after partation\n");
	swap(&arr[pivot], &arr[j]);	

	return j;
}

// quick sort
int quick_select(int *arr, int left, int right, int k) {
	// 小范围内 直接排序解决更便捷
	if(right - left < minimum_limit) {
		sort(arr, left, right, 1);
		return arr[left + k - 1];
	}
	
	int i, j, x;

	for(i=0; i<=(right-left-4)/5; i++) {
		// sort each 5-tuple
		sort(arr, left+5*i, left+5*i+4, 0);
		// set each median number in the front 
		swap(&arr[left+5*i+2], &arr[left+i]);
	}
	
	// the front (right - left - 4)/5 median elements  the median of median elements
	x = quick_select(arr, left, left+(right-left-4)/5, (right-left-4)/10);

//	printf("before partatioing\n");
	i = partationing(arr, left, right, x);
//	printf("after partatioing\n");
//	the left number of those elements lower than median of median elements
	j = i - left + 1;

	if(k <= j) {
		return quick_select(arr, left, i, k);
	}else {
		return quick_select(arr, i+1, right, k-j);
	}
}


int main() {

	int select, n, up_limit, min_limit, m;
	select = 0;
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
	if( m < 1 ||  m > n) {
		printf("enter error!\n");
		return -1;
	}

	// k is the result
//	int k = search_k_element(input_data, 0, n-1, m);
    int k = quick_select(input_data, 0, n-1, m);
	
	printf("%dth element is %d\n", m, k);

	// for check
	bubble_sort(input_data, 0, n-1);
	show(input_data, 0, n-1);
	printf("%dth element is %d\n", m, input_data[m-1]);


	return 0;
}
	

