// quick sort
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int input_data[100];

void show(int *arr, int end, int start);

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

// find a proper pivot in array
/*
int partition(int *arr, int left, int right) {
	int i = left;
	int j= right;
	int pos = rand() % (right+1-left) + left;

	while(i!=j) {
		while(i!=j && arr[i]<=arr[pos]) {
			i++;
		}
		if(i!=j) {
			swap(&arr[i], &arr[pos]);
			pos = i;
		}

		while(i!=j && arr[j]>=arr[pos]) {
			j--;
		}
		if(i!=j) {
			swap(&arr[j], &arr[pos]);
			pos = j;
		}
	}

	return i;
}
*/

/*
// divide the array and select a pivot
int partition(int *arr, int left, int right) {
	int *a1 = (int*)malloc(sizeof(int)*(right+1-left));
	int *a2 = (int*)malloc(sizeof(int)*(right+1-left));
	if (!a1 || !a2) {
		exit(-1);
	}

	int pos = rand() % (right+1-left) + left;
	printf(" pos is %d\n", pos);

	int p1 = 0;
	int p2 = 0;
	int i, j;

	for(i=left; i<=right; i++) {
		if(arr[i]<=arr[pos]) {
			a1[p1++] = arr[i];
		}else {
			a2[p2++] = arr[i];
		}
	}	
	for(i=left, j=0; j<p1; j++,i++) {
		arr[i] = a1[j];
	}
	for(j=0; j<p2; j++,i++) {
		arr[i] = a2[j];
	}
	if(i-1!=right) {
		printf(" index is not correct!\n");
		exit(-1);
	}

	free(a1);
	free(a2);

	return p1 - 1;
}
*/


/*
// return a perpor pivot
// note that this version select the first item as pivot
int partition(int *arr, int left, int right) {
	int sential = arr[left];
	//printf("povit is %d\n", sential);
	int i = left;
	int j = right;
	while(i!=j) {
		while(i!=j && arr[i]<=sential) {
			i++;
		}
		while(i!=j && arr[j]>=sential) {
			j--;
		}
		if(i!=j) {
			swap(&arr[i], &arr[j]);
		}
	}

	swap(&arr[i-1], &arr[left]);

	return i-1;

}
*/

// quick sort define 
void quick_sort(int *arr, int left, int right) {
	// element < 3 count 
	int i, j;
	if ( left + 2 >= right) {
		for(i=left; i<=right; i++) {
			for(j=i+1; j<=right; j++) {
				if(arr[i]>arr[j]) {
					swap(&arr[i], &arr[j]);
				}
			}
		}
		return ;
	}
	int pivot = arr[left];
	i = left+1;
	j = right;

	while(i!=j) {
		while(i!=j && arr[i] <= pivot) {
			i++;
		}
		while(i!=j && arr[j] > pivot) {
			j--;
		}
		if(i!=j) {
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[left], &arr[i-1]);

	quick_sort(arr, left, i-1);
	quick_sort(arr, i, right);
}

// display a array
void show(int *arr, int end, int start) {
	for(int i=start; i<=end; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {
	srand((unsigned)time(NULL));
	for(int i=0; i<100;i++) {
		input_data[i] =rand() % 100;
	}

	printf("origin array\n");
	show(input_data, 99, 0);

	// test
	//partition(input_data, 0, 99);
	//printf("after partition\n");
	//show(input_data, 99, 0);
	//return 0;
	
	quick_sort(input_data, 0, 99);

	printf("after sort\n");
	show(input_data, 99, 0);

	return 0;
}
