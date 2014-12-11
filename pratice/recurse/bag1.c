#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000
#define MAX_INF -99999999

typedef struct {
	int w;
	int v;
}Bag;

// randomly generate the test data
void generateTestData(int *arr, int start, int end) {
	int base, offset;
	base = 10;
	offset = 1;
	for(int i=start; i<=end; i++) {
		arr[i] = rand() % base + offset;
	}
}
//end

// tools
int max(int a, int b) {
	return a > b ? a : b;
}
//end

// version 1 no ant skill and as a check for other version about correction
int f(int *w, int *v, int n, int c) {
	if(n < 1 || c <= 0) { return 0; }
	int a, b;
	if(c >= w[n]) {
		return max(f(w, v, n-1, c-w[n]) + v[n], f(w, v, n-1, c));
	}else {
		return f(w, v, n-1, c);
	}
}
// end

void setBags(Bag *p, int start, int end) {
	/* pre data provided */
	/* end 
	p[1].w = 3; p[1].v = 9;
	p[2].w = 5; p[2].v = 10;
	p[3].w = 2; p[3].v = 7;
	p[4].w = 1; p[4].v = 4;
	*/
	int base = 10, offset = 1;
	for(int i=start; i<=end; i++) {
		p[i].w = rand() % base + offset;
		p[i].v = rand() % base + offset + p[i].w;
	}
}


int cmpBag(const void *a, const void *b) {
	Bag *c = (Bag*)a;
	Bag *d = (Bag*)b;
	//printf("size::%lu %d, %d\n", sizeof(*c), c->w, c->v);
	//printf("size::%lu %d, %d\n", sizeof(*d), d->w, d->v);
	double res = (double)c->v / c->w - (double)d->v / d->w;
	if(res < 0) {
		return 1 - 0;
	}else if(res > 0) {
		return 0 - 1;
	}else {
		return c->w - d->w;
	}
}

int sumBagsWeight(Bag *p, int start, int end) {
	int s = 0;
	for(int i=start; i<=end; i++) {
		s += p[i].w;
	}
	return s;
}

void displayBags(Bag *p, int start, int end) {
	for(int i=start; i<=end; i++) {
		printf("%2d ::%4d | %4d ||   %.2lf\n", i, p[i].w, p[i].v, (double)p[i].v / p[i].w);
	}
	printf("end\n");
}

// start the code 

double expection(Bag *p, int pos, int n, int c, int curValue) {
	double s = curValue;
	int i = pos;
	while(i<=n && p[i].w <= c && c>0) {
		c -= p[i].w;
		s += (double)p[i].v;
		i++;
	}
	if(i <= n) {
		s += c * (double)p[i].v / p[i].w;
	}
	return s;
}


// record the things which put into the knap
int finalRec[SIZE];
int rec[SIZE];

int cnt = 0;
void fgs(Bag *p, int pos, int n, int c, int curValue) {
	if(pos > n) { 
		cnt = curValue;
		memcpy(finalRec+1, rec+1, n*sizeof(int));
		return ; 
	}
	if(c >= p[pos].w) {
		rec[pos] = 1;
		fgs(p, pos+1, n, c-p[pos].w, curValue+p[pos].v);
		rec[pos] = 0;
	}
	if(expection(p, pos+1, n, c, curValue) > (double)cnt) { // expection func error or code error !
		fgs(p, pos+1, n, c, curValue);
	}
}

int main(int argc, char *argv[]) {
	
	srand((unsigned)time(NULL));

	int n, c;
	int base, offset;

	base = 10, offset = 1;

	// num
	n = rand() % base + offset;
	if(argc == 2) {
		sscanf(argv[1], "%d", &n);
	}

	Bag bags[SIZE];

	memset(bags, 0, sizeof(bags));
	setBags(bags, 1, n);

	// weight
	c = rand() % sumBagsWeight(bags, 1, n) + offset;

	printf("%4d  %4d\n\n", n, c);
	//displayBags(bags, 1, n);
	for(int i=1; i<=n; i++) {
		printf("%4d  %4d\n", bags[i].w, bags[i].v);
	}
	printf("\n");	

	qsort(bags+1, n, sizeof(bags[1]), cmpBag);

	//displayBags(bags, 1, n);

	fgs(bags, 1, n, c, 0);
	printf("%d\n\n", cnt);

	for(int i=1; i<=n; i++) {
		if(finalRec[i]) {
			printf("%d ==> %d\n", bags[i].w, bags[i].v);
		}
	}
	
	return 0;
}

