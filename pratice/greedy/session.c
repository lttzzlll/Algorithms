#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//test for case

#define SIZE 1000

typedef struct {
	int s;
	int f;
}Activity;

// how to generate the test data??
void generateTestData(Activity *ac, int n) {
	//srand((unsigned)time(NULL));
	int base = 100;
	int offset = 1;
	for(int i=1; i<=n; i++) {
		ac[i].s = rand() % base + offset;
		ac[i].f = rand() % base + offset + ac[i].s;
	}
}

int cmp(const void *a, const void *b) {
	Activity *c = (Activity*)a;
	Activity *d = (Activity*)b;
	if(c->f == d->f) {
		return c->s - d->s;
	}else {
		return c->f - d->f;
	}
}

void discompose(Activity *ac, int start, int end) {
	//printf("start | finished \n");
	for(int i=start; i<=end; i++) {
		printf("%4d, %4d\n", ac[i].s, ac[i].f);
	}
}


void disone(int *arr, int start, int end) {
	for(int i=start; i<=end; i++) {
		printf("%4d", arr[i]);
	}
	printf("\n");
}

int exist(int *mask, int start, int end) {
	for(int i=start; i<=end; i++) {
		if(!mask[i]) { return 1; }
	}
	return 0;
}

int getNext(int *mask, int start, int end) {
	int i;
	for(i=start; i<=end; i++) {
		if(!mask[i]) { return i; }
	}
	return -1;
}

int greedy(Activity *ac, int n) {
	int mask[SIZE];
	memset(mask, 0, sizeof(mask));
	int k, i;
	int res = 0;
	for(;;) {
		if(!exist(mask, 1, n)) { break; }

		k = getNext(mask, 1, n);
		if(k == -1) { break; }

		mask[k] = 1;
		res++;

		//printf("in each for::k==%d | res=%d\n", k, res);

		//printf("k==%d\n", k);
		for(i=k;;) {
			i = getNext(mask, i+1, n);
			if( i == -1) { break; }
			if(ac[i].s >= ac[k].f) {
				k = i;
				mask[k] = 1;
				//printf("in loop:k==%d | res=%d\n", k, res);
			}
		}
		//disone(mask, 1, n);
	}
	return res;
}


int main() {
	srand((unsigned)time(NULL));

	int n = 0;
	while(!n) {
		n = rand() % 10 + 1;
	}

	Activity ac[SIZE];
	memset(ac, 0, sizeof(ac));

	generateTestData(ac, n);
	/*
	ac[1].s = 1; ac[1].f = 23;
	ac[2].s = 12; ac[2].f = 28;
	ac[3].s = 25; ac[3].f = 35;
	ac[4].s = 27; ac[4].f = 80;
	ac[5].s = 36; ac[5].f = 50;
	*/
	printf("%d\n", n);
	discompose(ac, 1, n);

	qsort(ac+1, n, sizeof(ac[1]), cmp);

	//discompose(ac, 1, n);

	printf("%d\n", greedy(ac, n));

	return 0;
}
