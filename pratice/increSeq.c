#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//#include <string.h>
#define SIZE 1000

int a[SIZE];

int s[SIZE];
int p = 0;
int gCnt = 0;
int rec[SIZE];

int m[SIZE];



void display(int *arr, int start, int end) {
	for(int i=start; i<=end; i++) {
		printf("%d  ", arr[i]);
	}
	printf("\n");
}

void process() {
	if(p > gCnt) {
		int i;
		for(i=0; i<p-1; i++) {
			if(s[i] > s[i+1])  { break; }
		}
		if(i == p-1) { 
			gCnt = p;
			for(int i=0; i<p; i++) {
				rec[i] = s[i];
			}
		}
	}
}

void randomlyGenerateSubSet(int pos, int limit) {
	if(pos > limit) {
		process();
		return ;
	}
	s[p++] = a[pos];
	randomlyGenerateSubSet(pos+1, limit);
	p--;
	randomlyGenerateSubSet(pos+1, limit);
}

int max(int a, int b) {
	return a > b ? a : b;
}


// 问题的规模与存储顺序相同
/*
int d(int pos) {
	if(pos <= 0) {
		return 0;
	}
	int res = 0;
	int t = 0;
	for(int i=1; i<=pos; i++) {
		if(a[i] <= a[pos]) {
			t = d(pos-i) + 1;
			if(t > res) {
				res = t;
			}
		}
	}
	return res;
}
*/
		
// from buttom to top
int dp(int n) {
	int t, q;
	for(int i=1; i<=n; i++) {
		q = 0;
		//printf("a[%d]=%d: ", i, a[i]);
		for(int j=1; j<=i; j++) {
			if(a[j] <= a[i]) {
				//printf("a[%d]=%d  ", j, a[j]); 
				t = m[j] + 1;
				if(t > q) {
					q = t;
				}
			}
		}
		if(q > m[i]) {
			m[i] = q;
		}
		//printf("|%d\n", q);
	}
	/*
	t = n;
	for(int i=1; i<n; i++) {
		if(m[i] > m[t]) {
			t = i;
		}
	}
	return m[t];
	*/
	for(int i=1; i<=n; i++) {
		m[i] = max(m[i], m[i-1]);
	}
	return m[n];
}

int main() {

	int n; 
	n = 10;

	srand((unsigned)time(NULL));
	for(int i=1; i<=n; i++) {
		a[i] = rand() % 100;
	}

	printf("a random generate sequence below\n");
	display(a, 1, n);

	randomlyGenerateSubSet(1, n);

	printf("the longest increase sequence is below\n");
	display(rec, 0, gCnt-1);
	printf("the actual result below\n");
	printf("%d\n", gCnt);

	//int res = 0;
	//res = d(n);
	//printf("%d\n", res);
	
	printf("the dp.. result below\n");
	printf("%d\n", dp(n));
	return 0;
}

