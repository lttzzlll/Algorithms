#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 1000

// real store
int rec[SIZE];
int recPos = 0;

// mask record
int mask[SIZE];

// record compare result
int flag = 0;

int cmpInt(const void *a, const void *b) {
	return *(int*)a - *(int*)b;
}

void displayArray(int *arr, int start, int end) {
	for(int i=start; i<=end; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int sumArray(int *arr, int start, int end) {
	int s = 0;
	for(int i=start; i<=end; i++) {
		s += arr[i];
	}
	return s;
}


//version 1
void f(int *arr, int n, int c) {
	if(flag) { return ; }
	if(n < 1) { return ; }
	if(c == 0) {
		flag = 1;
		displayArray(rec, 0, recPos-1);
		recPos = 0;
		return ; 
	}
	if(arr[n] <= c) {
		rec[recPos++] = arr[n];
		f(arr, n-1, c-arr[n]);
		recPos--;
	}
	f(arr, n-1, c);
}
//end

// after sort what will | had happend??
int logo[SIZE];
int logPos = 0;
int tag = 0;


int main() {

	int n = 5;
	int c = 10;
	int a[SIZE] = {0, 2, 2, 6, 5, 4};
	int sum = 0;

	printf("%d %d\n", n, c);

	displayArray(a, 1, n);

	sum = sumArray(a, 1, n);

	printf("total sum::%d\n", sum);
	
	f(a, n, c);	

	printf("***********************\n");

	qsort(a+1, n, sizeof(a[1]), cmpInt);

	displayArray(a, 1, n);

	//ff(a, 1, n, c);

	return 0;
}

