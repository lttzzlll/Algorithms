// 10 - 2 - 8 -16
#include<stdio.h>

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

void system_transction(int digit, int n) {
	if(digit==0) {
		return ;
	}
	system_transction(digit/n, n);
	printf("%c", s[digit % n]);
}

int main() {
	int digit, n;
	scanf("%d %d", &digit, &n);

	system_transction(digit, n);
	printf("\n");

	return 0;
}
