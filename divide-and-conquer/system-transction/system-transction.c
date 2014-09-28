// 10 - 2 10 - 8 10 - 16
#include<stdio.h>
#include<stdlib.h>
char s[] = {
	'0',
	'1',
	'2',
	'3',
	'4',
	'5',
	'6',
	'7',
	'8',
	'9',
	'A',
	'B',
	'C',
	'D',
	'E',
	'F'
};

void system_transcation(int n, int m) {
	char *p = (char*)malloc(sizeof(char)*1000);
	if(p==NULL) {
		printf("error\n");
		exit(-1);
	}
	int pos = 0;
	while(n) {
		int t = n % m;
		p[pos++] = s[t];
		n /= m;
	}
	for(int i=pos; i>=0; i--) {
		printf("%c", p[i]);
	}
	printf("\n");
}
int main() {
	int n, m;
	char *p;
	scanf("%d %d", &n, &m);
	system_transcation(n, m);
	return 0;
}

