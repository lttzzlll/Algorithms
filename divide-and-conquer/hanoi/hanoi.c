// hanoi

#include<stdio.h>

void move(int n, char pillarA, char pillarB) {
	printf("move %dth plate from  pillar %c to pillar %c\n", n, pillarA, pillarB);
}

// think before write if you want to write more, read more information in the general code 
// do not expect a expected chance to become so differ compare with before
// c is foutheen years old
void hanoi(int n, char pillarA, char pillarB, char pillarC) {
	if(n > 0) {
		hanoi(n-1, pillarA, pillarC, pillarB);
		move(n, pillarA, pillarB);
		hanoi(n-1, pillarC, pillarB, pillarA);
	}
}


int main() {
	int n, x;
	printf("enter hanoi(s) number: ");
	scanf("%d", &n);
	//x = hanoi(n, a, b, c);
	//printf("total move times is %d\n", x);
	// in fact none return is a better design
	hanoi(n, 'a', 'b', 'c');
	return 0;
}

