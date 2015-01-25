#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>

const unsigned long maxshort = 65536L;
const unsigned long multiplier = 1194211693L;
const unsigned long adder = 12345L;

int runtimes = 0;

time_t start, end;

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

struct TestData {
	int n;
	int *arr;
	bool flag;

	TestData(int n=100) {
		this->n = n;
		arr = new int[n+1];
		flag = true;

		generate();
	}

	~TestData() {
		delete [] arr;
	}

	void swap(int *a, int *b) {
		int temp = *a;
		*a = *b;
		*b = temp;
	}

	void randomly() {
		RandomNumber rnd;
		for(int i=0; i<n; i++) {
			swap(arr+i, arr+rnd.Random(n));
		}
	}

	void generate() {
		if (flag) {
			RandomNumber rnd;
			int majority = rnd.Random(n);
			int count = rnd.Random(n / 2) + n / 2;
			for (int i=0; i<count; i++) {
				arr[i] = majority;
			}
			for(int i=count; i<n; i++) {
				arr[i] = rnd.Random(n);
			}
			randomly();
		}else {
			RandomNumber rnd;
			for (int i=0; i<n; i++) {
				arr[i] = rnd.Random(n);
			}
		}
	}

	void show() {
		for (int i=0; i<n; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
	}

};

int majority(int *arr, int n) {
	RandomNumber rnd;
	int i = rnd.Random(n) + 1;
	int x = arr[i];
	int k = 0;
	for (int j=0; j<n; j++) {
		runtimes++;
		if (arr[j] == x) {
			k++;
		}
	}
	if (k > (n / 2)) {
		return x;
	}
	return -1;
}

int majorityMC(int *arr, int n) {
	int k = 6;
	int res = -1;
	start = clock();
	for (int i=1; i<=k; i++) {
		runtimes++;
		res = majority(arr, n);
		if (res != -1) {
			end = clock();
			return res;
		}
	}
	end = clock();
	return -1;
}

int maj(int *arr, int n) {
	int cur = arr[0];
	int count = 0;
	for (int i=0; i<n; i++) {
		if (arr[i] == cur) {
			count++;
		}else {
			count--;
			if (count == 0) {
				cur = (i+1) > n ? -1 : arr[i+1];
			}
		}
	}
	return cur;
}


/*
int majorCount(int *arr, int left, int right, int major) {
	int cnt = 0;
	for (int i=left; i<=right; i++) {
		if (arr[i] == major) {
			cnt++;
		}
	}
	return cnt;
}


int checkAnthor(int *arr, int left, int right, int major, int num, int *count) {
	*count += majorCount(arr, left, right, major);
	if (*count > num / 2) {
		return major;
	}
	return -1;
}


int major(int *arr, int left, int right, int *count) {
	if (left == right) {
		*count += 1;
		return arr[left];
	}

	int mid, leftmaj, rightmaj;
	int leftcount = 0, rightcount = 0;

	mid = (right - left) / 2;
	leftmaj = major(arr, left, mid, &leftcount);
	rightmaj = major(arr, mid+1, right, &rightcount);

	if (leftmaj == -1 && rightmaj == -1) {
		return -1;
	}
	if (leftmaj == -1 && rightmaj != -1) {
		*count += rightcount;
		return checkAnthor(arr, left, mid, rightmaj, *count, &rightcount);
	}
	if (leftmaj != -1 && rightmaj == -1) {
		*count += leftcount;
		return checkAnthor(arr, mid+1, right, leftmaj, *count, &leftcount);
	}
	if (leftmaj !=- 1 && rightmaj != -1) {
		if (leftmaj == rightmaj) {
			*count += (leftcount + rightcount);
			return leftmaj;
		}else {
			int newmaj = checkAnthor(arr, left, mid, rightmaj, *count, &rightcount);
			if (newmaj != -1) {
				*count += (leftcount + rightcount);
				return newmaj;
			}else {
				newmaj = checkAnthor(arr, mid+1, right, leftmaj, *count, &leftcount);
				if (newmaj != -1) {
					*count += (leftcount + rightcount);
					return newmaj;
				}else {
					return -1;
				}
			}
		}
	}
}
*/

int main(int argc, char *argv[]) {
	int n = 100;
	if(argc == 2) {
		sscanf(argv[1], "%d", &n);
	}
	printf("%d\n", n);
	TestData *td = new TestData(n);
	td->show();
	int res;
	res = majorityMC(td->arr, td->n);
	if (res != -1) {
		printf("majority element %d\nruntimes %d  runtime %lf\n", res, runtimes, (float)(end - start) / CLOCKS_PER_SEC);
	}else {
		printf("not found majority element\n");
	}
	
	start = clock();
	res = maj(td->arr,  td->n);
	end = clock();
	if (res == -1) {
		printf("no majority element\n");
	}else {
		printf("majority element %d\nruntime %lf\n", res, (float)(end - start) / CLOCKS_PER_SEC);
	}

	/*
	int elementCount = 0;
	start = clock();
	res = major(td->arr, 0, td->n-1, &elementCount);
	if (res == -1) {
		printf("no majority element\n");
	}else {
		printf("majority element %d\nruntime %lf\n", res, (float)(end - start) / CLOCKS_PER_SEC);
	}
	*/

	delete td;
	return 0;
}

