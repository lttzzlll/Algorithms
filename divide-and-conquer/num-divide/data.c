#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
	srand((unsigned)time(NULL));
	int limit = 100;
	int res = 0;

	while (!res) {
		res = rand() % limit;
	}
	printf("%d\n", res);
	return 0;
}

































