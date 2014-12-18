#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INT 99999999
//#define MIN_INT -99999999
#define SIZE 1000


void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void listInt(int *arr, int x) {
	int pos = 0;
	while(x) {
		arr[pos++] = x % 10;
		x /= 10;
	}
	for(int i=0; i<=(pos-1)/2; i++) {
		swap(arr+i, arr+pos-i-1);
	}
}

int getInt(int *arr, int *mask, int n) {
	int s = 0;
	for(int i=0; i<n; i++) {
		if(mask[i]) {
			s = s * 10 + arr[i];
		}
	}
	return s;
}

void listDisplay(int *arr, int n) {
	for(int i=0; i<n; i++) {
		printf("%d ", arr[i]);
	}
	printf("| %d\n", n);
}


// record the result
int minValue = MAX_INT;

/* data generate */
int generateAInt() {
	srand((unsigned)time(NULL));
	int res = 0, t;
	for(;;) {
		res = rand() % MAX_INT;
		t = res;
		while(res >= 10) {
			if(res % 10 == 0) {
				break;
			}
			res /= 10;
		}
		if(res < 10) {
			break;
		}
	}
	return t;
}

int getIntLen(int x) {
	int r = 0;
	while(x) {
		x /= 10;
		r++;
	}
	return r;
}

int randint(int low, int up) {
	int base = 1;
	return rand() % (up - low) + base;
}

int min(int a, int b) {
	return a < b ? a : b;
}

/* end */


int getMinPos(int *arr, int *mask, int n) {
	int minValue = MAX_INT;
	int minPos = 0;
	for(int i=0; i<n; i++) {
		if(!mask[i]) {
			if(arr[i] < minValue) {
				minValue = arr[i];
				minPos = i;
			}
		}
	}
	mask[minPos] = 1;
	return minPos;
}

int selectMinElement(int *arr, int *mask, int start, int n) {
	int minValue = MAX_INT;
	int minPos = 0;
	for(int i=start; i<n; i++) {
		if(!mask[i]) {
			if(arr[i] < minValue) {
				minValue = arr[i];
				minPos = i;
			}
		}
	}
	mask[minPos] = 1;

	return minPos;
}

int greedy(int x, int y, int z) {
	int q = y - z; 
	int lst[SIZE];
	int mask[SIZE];
	int rec[SIZE];
	
	for(int i=0; i<SIZE; i++) {
		lst[i] = MAX_INT;
	}
	memset(mask, 0, sizeof(mask));
	memset(rec, 0, sizeof(rec));

	listInt(lst, x);

	int minPos = -1;
	for(int i=1; i<=q; i++) { //select times counts
		minPos = selectMinElement(lst, mask, minPos+1, min(z+i, y));
	}

	return getInt(lst, mask, y);
}

int main() {
	int x, y, z;

	x = generateAInt();
	y = getIntLen(x);
	z = randint(0, y);

	printf("number: %d | bits: %d | delete bits: %d\n", x, y, z);
	
	if(y == z) {
		printf("the smallest number: 0\n");
	}else {
		printf("the smallest number: %d\n", greedy(x, y, z));
	}

	return 0;
}
