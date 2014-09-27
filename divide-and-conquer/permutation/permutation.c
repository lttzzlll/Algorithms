// 1 2 3 4 permutation
#include<stdio.h>

int set[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int a[10];
int occu[10];

int cnt = 0;

void swap(int *a, int *b) {
	int t; 
	t = *a;
	*a = *b;
	*b = t;
}
void perm(int *list, int k, int m) {
	if(k > m) {
		cnt++;
		for(int i=0; i<=m; i++) {
			printf("%d ", list[i]);
		}
		printf("\n");
	}else {
		for(int i=k; i<=m; i++) {
			swap(&list[i], &list[k]);
			perm(list, k+1, m);
			swap(&list[i], &list[k]);
		}
	}
}

void permutate(int *t, int *s, int start, int end) {
	if (start > end ) {
		// break to check if is right
		//if( cnt == 100) {
		//		exit(1);
		//}
		cnt++;
		for(int i=0; i<=end; i++) {
			printf("%d ", t[i]);
		}
		printf("\n");
	}else {
		for(int i=0; i<=end; i++) {
			if(occu[i]) {
				continue;
			}
			occu[i] = 1;
			t[start] = s[i];
			permutate(t, s, start+1, end);
			occu[i] = 0;
		}
	}
}

int main() {
//	perm(set, 0, 9);
	permutate(a, set, 0, 9);
	printf("%d\n", cnt);
	return 0;
}
