#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SIZE 1000

int a[SIZE];
int b[SIZE];

int n;
int s;
int res = 0;
double half;
double avg;
double mini = 99999999;

int intsCmp(const void *a, const void *b) {
	return *(int*)a - *(int*)b;
}


void generateNumbers(int *arr, int start, int end) {
	//srand((unsigned)time(NULL));
	int base,  offset;
	base = 100; 
	offset = 1;
	for(int i=start; i<=end; i++) {
		arr[i] = rand() % base + offset;
	}
}

int sumInts(int *arr, int start, int end) {
	int s = 0;
	for(int i=start; i<=end; i++) {
		s += arr[i];
	}
	return s;
}

void display(int *arr, int start, int end) {
	for(int i=start; i<=end; i++) {
		printf("%4d", arr[i]);
	}
	printf("\n");
}

void intsCopy(int *des, int *src, int start, int end) {
	for(int i=start; i<=end; i++) {
		des[i] = src[i];
	}
}

double min(double a, double b) {
	return a < b ? a : b;
}

// subsets
int mask[SIZE];
int bestres[SIZE];
int gres = 0;
double mins = 999999;


void trace(int pos, int curs) {
	// cut off method?
	// did it have?
	// in which condition ?
	// curs == half
	if(fabs((double)curs - half) < 1e-6) {
		res = curs;
		mini = 0;
		return ;
	}
	if(pos > n) {
		if(fabs((double)curs - half) < mini) {
			mini = fabs((double)curs - half);
			res = curs;
		}
		return ;
	}
	if((double)curs > half) {
		if(fabs((double)curs - half) < mini) {
			mini = fabs((double)curs - half);
			res = curs;
		}
		return ;
	}
	// cutoff means that you have to cut the down to leap routes
	// so there will be a main elements for time used!
	// core step
	trace(pos+1, curs+a[pos]); // put in
	trace(pos+1, curs); // not put in
}


int main(int argc, char *argv[]) {
	srand((unsigned)time(NULL));	

	n = rand() % 30 + 1;
	if(argc == 2) {
		sscanf(argv[1], "%d", &n);
	}

	generateNumbers(a, 1, n);

	//printf("n= %d\n", n);
	//printf("original data\n");
	printf("%d\n", n);
	display(a, 1, n);

	qsort(a+1, n, sizeof(a[1]), intsCmp);

	//printf("after sort\n");
	//display(a, 1, n);

	s = sumInts(a, 1, n);

	intsCopy(b, a, 1, n);

	for(int i=1; i<=n; i++) {
		b[i] += b[i-1];
	}
	//printf("list sum\n");
	//display(b, 1, n);

	half = (double)s / 2;
	avg = (double)s / n;
	//printf("total weight:: %d\n", s);
	//printf("halg weight:: %.2lf\n", half);
	//printf("avg weight:: %.2lf\n", avg);


	clock_t t;
	t = clock();
	trace(1, 0);
	t = clock() - t;

	printf("%lu clicks (%f secs)\n", t, (float)t / CLOCKS_PER_SEC);
	printf("%d %d\n", res, s - res);

	return 0;
}

