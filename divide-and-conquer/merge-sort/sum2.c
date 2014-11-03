// select 2 elements in a set which sum them equals to n

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void randomRange(int *arr, int left, int right, int limitation, int offset) {
	srand((unsigned)time(NULL));
	for(int i=left; i<=right; i++) {
		arr[i] = rand() % limitation + offset;
	}
}

void display(int *arr, int left, int right) {
	for(int i=left; i<=right; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int checkForDisplay(int *arr, int left, int right, int n) {
	int counts=0;
	for(int i=left; i<=right; i++) {
		for(int j=i+1; j<=right; j++) {
			if(arr[i] + arr[j] == n) {
				printf("arr[%d] + arr[%d] == %d { %d + %d } == %d\n", i, j, n, arr[i], arr[j], n);
				counts++;
			}
		}
	}
	return counts;
}

int checkForDisplayAfterSort(int *arr, int left, int right, int n) {
	int counts = 0;
	for(int i=left; i<=right; i++) {
		if(arr[i] > n) {
			//return  counts;
			break;
		}
		for(int j=i+1; j<=right; j++) {
			if(arr[j] > n || arr[i] + arr[j] > n) {
				//return counts;
				break;
			}
			if(arr[i] + arr[j] == n) {
				printf("arr[%d] + arr[%d] == %d { %d + %d } == %d\n", i, j, n, arr[i], arr[j], n);
				counts++;
			}
		}
	}
	return counts;
}


void merge(int *arr, int left, int mid, int right) {
	int i=left, j=mid+1, pos=0, counts = right - left + 1;
	int *pArr = (int*)malloc(sizeof(int)*counts);
	if(pArr == NULL) {
		fprintf(stderr, "alloc memory error\n");
		exit(-1);
	}
	
	for(;;) {
		while(i<=mid && arr[i]<=arr[j]) {
			pArr[pos++] = arr[i++];
		}
		while(j<=right && arr[j]<=arr[i]) {
			pArr[pos++] = arr[j++];
		}
		if(i > mid) {
			while(j <= right) {
				pArr[pos++] = arr[j++];
			}
			break;
		}
		if(j>right) {
			while(i <= mid ) {
				pArr[pos++] = arr[i++];
			}
			break;
		}
	}

	for(i=0; i<counts; i++) {
		arr[i+left] = pArr[i];
	}

	free(pArr);
}

void mergeSort(int *arr, int left, int right) {
	if(left < right) {
		int mid = (right - left) / 2 + left;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid+1, right);
		merge(arr, left, mid, right);
	}
}


int search(int *arr, int left, int right, int n) {
	mergeSort(arr, left, right);
	int i=left, j=right;
	while(i<j) {
		if(arr[i] + arr[j] > n) {
			j--;
		}else if(arr[i] + arr[j] < n) {
			i++;
		}else {
			return 0;
		}
	}
	return -1;
}

int main() {
	int a[100], n, limitation, offset, number;
	n = 100;
	limitation = 100;
	offset = 0;

	randomRange(a, 0, n-1, limitation, offset);

	display(a, 0, n-1);
	
	//mergeSort(a, 0, n-1);

	//display(a, 0, n-1);

	printf("input a number: ");
	scanf("%d", &number);

	int num1 = checkForDisplay(a, 0, n-1, number);
	printf("total pair is %d\n", num1);

	if(search(a, 0, n-1, number) == 0) {
		printf("Success\n");
	}else {
		printf("Failed\n");
	}

	int num2 = checkForDisplayAfterSort(a, 0, n-1, number);
	printf("total pair is %d\n", num2);

	display(a, 0, n-1);
	
	return 0;
}


