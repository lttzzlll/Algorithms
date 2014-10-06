// just achieve the random function
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


// return a integer between down to up
int randomize(int down, int up) {
	srand((unsigned)time(NULL));
	return down + rand() % (up - down + 1);
}

int main() {
	for(int up, down, i=0;i<10;i++) {
		printf("enter two number(down, up): ");
		scanf("%d %d", &down, &up);
		printf("randomize the number is %d\n", randomize(down, up));
	}
}

