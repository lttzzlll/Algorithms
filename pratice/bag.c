/*
 * note : this is a wrong dirction  all the things had been wrong||||
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 1000

int w[SIZE];
int v[SIZE];
int p[SIZE];

int s[SIZE];
int gPos = 0;
int gCnt = 0;
int rec[SIZE];

int m[SIZE];
int gValue = 0;

typedef struct {
	int v;
	int w;
}Pack;

Pack pack[SIZE];

void init(Pack *p) {
	p->w = 0;
	p->v = 0;
}

// suppose input weight
int c;


void display(int *arr, int start, int end) {
	for(int i=start; i<=end; i++) {
		printf("%4d", arr[i]);
	}
	printf("\n");
}

void displayIfExist(int *arr, int n) {
	printf("Dict{key => value} | total pair(s) is %d\n", n);
	printf("weight => value\n");
	for(int i=0; i<SIZE; i++) {
		if(n == 0) {
			break;
		}
		if(arr[i]) {
			printf("%5d  => %4d \n", i, arr[i]);
			n--;
		}
	}
	printf("\n");
}

void show(Pack *p, int start, int end) {
	for(int i=start; i<=end; i++) {
		printf("pack[%d] :: (w, v) => (%2d, %2d) |\n", i, p[i].w, p[i].v);
	}
	printf("\n");
}

void delete(Pack *p, int pos, int n) {
	for(int i=pos; i<n; i++) {
		p[i] = p[i+1];
	}
}

int cmp(const void *c, const void *d) {
	Pack *a = (Pack*)c;
	Pack *b = (Pack*)d;
	if(a->w < b->w) {
		return 0;
	}
	if(a->w > b->w) {
		return 1;
	}
	return a->v == b->v;
}

void sort(Pack *p, int n) {
	qsort(p, n, sizeof(*(p+0)), cmp);
}


void randomIncrease(int *arr, int start, int end, int limit) {
	//srand((unsigned)time(NULL)); bad timer random generator
	int t=0;
	arr[start] = 0;
	while(!arr[start]) {
		arr[start] = rand() % limit;
	}
	for(int i=start+1; i<=end; i++) {
		while(!t) {
			t = rand() % limit;
		}
		arr[i] = t + arr[i-1];
	}
}

void randomTimer() {
	srand((unsigned)time(NULL));
}

int sum(int *arr, int start, int end) {
	int s = 0;
	for(int i=start; i<=end; i++) {
		s += arr[i];
	}
	return s;
}

int sumPackWeight(Pack *p, int start, int end) {
	int weight = 0;
	for(int i=start; i<=end; i++) {
		weight = p[i].w;
	}
	return weight;
}

int sumPackValue(Pack *p, int start, int end) {
	int value = 0;
	for(int i=start; i<=end; i++) {
		value += p[i].v;
	}
	return value;
}

int max(int a, int b) {
	return a > b ?  a : b;
}

int randint(int low, int up) {
	int c = up - low + 1;
	return rand() % c + low;
}

void composeWV(int *p, int *w, int *v, int start, int end) {
	for(int i=start; i<=end; i++) {
		p[w[i]] = v[i];
	}
}

void composeWVToPack(Pack *p, int *w, int *v, int start, int end) {
	for(int i=start; i<=end; i++) {
		p[i].w = w[i];
		p[i].v = v[i];
	}
}





void process() {
	//displayIfExist(s, gPos);
	int curW = 0;
	int curV = 0;
	int curPos = 0;
	for(int i=1; i<SIZE; i++) {
		if(curPos == gPos) {
			break;
		}
		if(s[i]) {
			curPos++;
			curW += i;
			curV += s[i];
			if(curW > c) {
				return ;
			}
		}
	}
	if(curV > gValue) {
		gValue = curV;
		gCnt = gPos;
		memset(rec, 0, sizeof(rec)); // reset record list
		curPos = 0;
		for(int i=1; i<SIZE; i++) {
			if(curPos == gPos) {
				break;
			}
			if(s[i]) {
				curPos++;
				rec[i] = s[i];
			}
		}
	}
}

void randomlyGenerateSubSet(int *arr, int i, int pos, int n) {
	if(pos > n) {
		process();
		return ;
	}
	
	while(!arr[i]) { i++; } // value[pos] exist
	s[i] = arr[i]; // set
	gPos++;
	randomlyGenerateSubSet(arr, i+1, pos+1, n);
	s[i] = 0; // clear
	gPos--;
	randomlyGenerateSubSet(arr, i+1, pos+1, n);
}
	



// 在一个字典数据类型上进行动态规划 

// 问题规模递减的序列
// 访问问题空间的顺序
/*
    7  =>    1
   13  =>   10
   19  =>   19
   25  =>   28
   31  =>   37
*/
// 访问问题空间的方式
// 访问解空间的方式
// 钢条切割问题中 每一次访问问题空间都能保证在解空间中
// 子问题是可以被重复利用的  10 = 3 + 3 + 3 + 1
// 0 - 1 背包问题中     每个子问题都可以只能用一次 要么在问题空间中【1】 要么在解空间中 【0】 

// suppose p is sorted 

int dp1(Pack *p, int start, int end, int c) {
	if(c <= 0) { // c is 0
		return 0;
	}
	if(c < p[start].w) { // c < the smallest weight
		return 0;
	}
	if(start > end) { // no sub question
 		return 0;
	}
	// error :~
	return max(dp1(p, start+1, end, c-p[start].w) + p[start].v, dp1(p, start+1, end, c-p[start].w));
}

// need the adapte data to store the result
Pack ppt[SIZE];
int ppPos = 0;
Pack reppt[SIZE];
int rePos = 0;
// failed
void ccs() {
	int a = sumPackValue(ppt, 0, ppPos-1);
	int b = sumPackValue(reppt, 0, rePos-1);
	if(a > b) {
		for(int i=0; i<ppPos; i++) {
			reppt[i] = ppt[i];
		}
		rePos = ppPos;
		ppPos = 0;
	}
}

/*
int ccc[SIZE];
int dp2(Pack *p, int start, int end, int c) {
	if(c <= 0 || end <  start) {
		ccs();
		return 0;
	}
	//if(ccc[c]) { return ccc[c]; }
	int a = 0;
	int b = 0;
	if(c >= p[end].w) {
		a = dp2(p, start, end-1, c-p[end].w) + p[end].v;
	}
	b = dp2(p, start, end-1, c);
	if(a >= b) {
		ppt[ppPos++] = p[end];
		return a;
	}else{
		return b;
	}
}
*/

/* when record table indeed error occured !!!
// memoized top down method
int mm[SIZE];
int dp3(Pack *p, int start, int end, int c) {
	if(c <= 0 || end < start) {
		return 0;
	}
	if(mm[c]) {
		return mm[c];
	}
	int a = 0;
	int b = 0;
	if(c >= p[end].w) {
		a = dp3(p, start, end-1, c-p[end].w) + p[end].v;
	}
	b = dp3(p, start, end-1, c);
	mm[c] = max(mm[c], max(a, b));
	return mm[c];
}
*/

/*
// 一张二维的表 因为一位向量无法表达问题空间与解空间之间的关系
// 钢条切割问题中 因为问题空间与解空间在表达上是一致的  所以只用一维向量即可
// 0-1背包问题中 需要考虑问题的01性 即要么在问题空间中 要么在解问题空间中
// 用二维表的含义: 从行坐标来看: 每一个解空间的子问题都对应全部的问题空间中的问题  
// 实际中有的解空间重点子问题不可能对应所有的问题空间中的问题 因为[ i < p[i].w]
// 所以应该是只用了半张表  而且不是严格的一半  是有锯齿形状的一半表格 边界通常存在问题
// from buttom to top
// note : suppose wigth is sorted from low to high
// note : suppose c is < [the biggset weight(p[end].w)]
int memo[SIZE];
int dp4(Pack *p, int start, int end, int c) {
	if(c <= 0 || end < start) { return 0; }
	int t = 0, q = 0;
	for(int i=p[start].w; i<=c; i++) {
		for(int j=p[start].w; j<=i; j++) {
		}
	}
	return 0;
}
*/

// top to down
int memo[SIZE][SIZE];
int dp(int i, int c) {
	if(i < 1 || c <= 0) { return  0; }
	if(memo[i][c]) { return memo[i][c]; }
	int res = 0;
	if(c >= w[i] ) {
		res = max(dp(i-1, c-w[i]) + v[i], dp(i-1, c));
	}else {
		res = dp(i-1, c);
	}
	if(res > memo[i][c]) { 
		memo[i][c] = res;
	}
	return memo[i][c];
}

// from buttom to top
//   weight number
int M[SIZE][SIZE]; // M is 0 set!
int DP(int n, int c) {
	for(int i=1; i<=n; i++) { // be sure of 0 1 
		for(int j=1; j<=c; j++) {
			if(j >= w[i]) {
				M[i][j] = max(M[i-1][j-w[i]] + v[i], M[i-1][j]);
			}else{ // j < w[i]
				M[i][j] = M[i-1][j];
			}
		}
	}
	return M[n][c];
}

void outShow(int n, int c) {
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=c; j++) {
			printf("%d ", M[i][j]);
		}
		printf("\n");
	}
}


int main() {
	
	int n;
	n = 5;
	int limit;
	limit = 10;

	randomTimer();

	randomIncrease(w, 1, n, limit);
	randomIncrease(v, 1, n, limit);

	composeWV(p, w, v, 1, n);

	display(w, 1, n);
	display(v, 1, n);
	displayIfExist(p, n);

	composeWVToPack(pack, w, v, 1, n);

	sort(pack+1, n);

	//show(pack, 1, n);
	
	int s = 0;
	s = sum(w, 1, n);

	// c is the input weight | a global variable
	c = randint(s/2, s);

	printf("input weight is(randomly generate): %d\n", c);

	randomlyGenerateSubSet(p, 1, 1, n);
	
	printf("the biggset things compose list is below\n");
	displayIfExist(rec, gCnt);
	printf("the biggset value is: %d\n", gValue);
	
	// the actual part 	
	int V = 0; // the total value
	V = sum(v, 1, n);
	if(c >= s) { // the input weight >= the total weight
		printf("%d\n", V);
	}else{ // the real test part 
		   // each input weight(s) < the total weight
		//printf("%d\n", dp());
		//printf("%d\n", dp1(pack, 1, n, c));
		//printf("%d\n", dp2(pack, 1, n, c));
		//printf("record pos: %d\n", ppPos);
		//for(int i=0; i<rePos; i++) {
		//	printf("%d => %d\n", reppt[i].w, reppt[i].v);
		//}
		//printf("the dp result: %d\n", dp3(pack, 1, n, c));
		printf("the dp result is(top to down): %d\n", dp(n, c));
		printf("the dp result is(buttom to top): %d\n", DP(n, c));
		//outShow(n, c);
	}
	return 0;
}
