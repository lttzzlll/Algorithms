#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 1000

int c[SIZE][SIZE];

int lcs_length(const char *x, const char *y, int m, int n)  {
	
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=n; j++) {
			if(x[i] == y[j]) {
				c[i][j] = c[i-1][j-1] + 1;
			}else if(c[i-1][j] >= c[i][j-1]) {
				c[i][j] = c[i-1][j];
			}else {
				c[i][j] = c[i][j-1];
			}
		}
	}
	return c[m][n];
}

int main() {
	char s1[SIZE]={'@'};
	char s2[SIZE]={'@'};

	//strcpy(s1, "@helloworld");
	//strcpy(s2, "@hoowld");
	int n1, n2;

	/*
	printf("input string 1 length(1 <= length <= %d: ", SIZE);
	scanf("%d", &n1);
	printf("input string 2 length(1 <= length <= %d: ", SIZE);
	scanf("%d", &n2);
	if(n1 < 1 || n2 < 1 || n1 >= SIZE || n2 >= SIZE) {
		printf("input string length is too long (too short)\n");
		exit(-1);
	}
	*/

	n1 = 15;
	n2 = 17;
	
	srand((unsigned)time(NULL));
	for(int i=1; i<=n1; i++) {
		s1[i] = rand() % 26 + 'A';
	}
	for(int i=1; i<=n2; i++) {
		s2[i] = rand() % 26 + 'A';
	}

	int len1 = strlen(s1);
	int len2 = strlen(s2);

	printf("%s | %d\n", s1, len1);
	printf("%s | %d\n", s2, len2);


	int res = 0;
	res = lcs_length(s1, s2, len1-1, len2-1);
	printf("%d\n", res);

	//check
	//for(int i=1; i<=len1-1; i++) {
	//	for(int j=1; j<=len2-1; j++) {
	//		printf("%d ", c[i][j]);
	//	}
	//	printf("\n");
	//}
	
	return 0;
}
