#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000
int a[SIZE];


const unsigned long maxshort = 65536L;
const unsigned long multiplier = 1194211693L;
const unsigned long adder = 12345L;

struct RandomNumber {
	unsigned long randSeed;

	RandomNumber(unsigned long s = 0) {
		if (s == 0) randSeed = time(0);
		else randSeed = s;
	}

	unsigned short Random(unsigned long n) {
		randSeed = multiplier * randSeed + adder;
		return (unsigned short) (randSeed >> 16) % n;
	}
	double fRandom(void) {
		return Random (maxshort) / (double)maxshort;
	}
};

void generateTestData(int *arr, int left, int right) {
	srand((unsigned)time(NULL));
	int base, offset;
	base = 100, offset = 1;
	for (int i=left; i<=right; i++) {
		arr[i] = rand() % base + offset;
	}
}

void show(int *arr, int left, int right) {
	for (int i=left; i<=right; i++) {
		printf("%4d", arr[i]);
	}
	printf("\n");
}

int cmpInt(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int randomSelect(int *arr, int left, int right, int k) {
	static RandomNumber rnd; // why is static ?
	for (;;) {
		if (left >= right) {
			return arr[left];
		}
		int i = left, j = left + rnd.Random(right - left + 1);
		swap(&arr[i], &arr[j]);
		j = right + 1;
		int pivot = arr[left];
		for (;;) {
			while (arr[++i] < pivot);
			while (arr[--j] > pivot);
			if (i >= j) {
				break;
			}
			swap(&arr[i], &arr[j]);
		}
		if (j - left + 1 == k) {
			return pivot;
		}
		arr[left] = arr[j];
		arr[j] = pivot;
		if (j - left + 1 < k) {
			k = k - (j - left + 1);
			left = j + 1;
		}else {
			right = j - 1;
		}
	}
}

int main(int argc, char *argv[]) {
	int n = 100, k;
	if (argc == 1) {
		k = 50;
	}else if (argc == 2) {
		sscanf(argv[1], "%d", &k);
	}else if (argc == 3) {
		sscanf(argv[1], "%d", &n);
		sscanf(argv[2], "%d", &k);
	}else {
		exit(-1);
	}
	generateTestData(a, 0, n-1);
	show(a, 0, n-1);
	printf("%dth element is %d\n", k, randomSelect(a, 0, n-1, k));
	qsort(a, n, sizeof(a[0]), cmpInt);
	show(a, 0, n-1);
	return 0;
}

