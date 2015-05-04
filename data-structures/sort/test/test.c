#include "test.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateData(int *arr, int n, int limitation) {
	srand((unsigned)time(NULL));
	for (int i=0; i<n; i++) {
		arr[i] = rand() % (limitation + 1);
	}
}

void displayArray(int *arr, int n) {
	for (int i=0; i<n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void copyFromArrayTo(int *des, int *src, int n) {
	for (int i=0; i<n; i++) {
		des[i] = src[i];
	}
}

int compare(int *lhs, int *rhs, int n) {
	for (int i=0; i<n; i++) {
		if (lhs[i] != rhs[i]) {
			return -1;
		}
	}
	return 0;
}

int cmp(const void *lhs, const void *rhs) {
	return *(int *)lhs - *(int *)rhs;
}

void test(int n, int limitation, void (*sort)(int *arr, int n)) {
	int *p = (int *)malloc(sizeof(int) * n * 2);
	if (p == NULL) {
		printf("malloc error\n");
		exit(-1);
	}

	generateData(p, n, limitation);

	copyFromArrayTo(p + n, p, n);

	printf("Input: \n");
	displayArray(p, n);
	
	sort(p, n);
	
	printf("Output: \n");
	displayArray(p, n);

	printf("Expection: \n");
	qsort(p + n, n, sizeof(int), cmp);
	displayArray(p + n, n);

	if (compare(p, p + n, n) == 0) {
		printf("Succeed!\n");
	}else {
		printf("Failed!\n");
	}
}

