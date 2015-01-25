#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
	srand((unsigned)time(NULL));

	int k = 2;
	if (argc == 2) {
		k = atoi(argv[1]);
	}

	int size = 1;
	for (int i=0; i<k; i++) {
		size *= 2;
	}

	int x = 0, y = 0;
	x = rand() % size;
	y = rand() % size;

	//printf("%d %d\n", k, size);
	printf("%d %d %d\n",k, x, y);

	return 0;
}
