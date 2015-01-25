#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 1024 //max rect size

int rect[SIZE][SIZE];
int MARK = 0;

void chessboard(int specialx, int specialy, int startx, int starty, int size) {
	if (size <= 1) { // must be the special position
		return ;
	}

	int t = MARK++;
	
	if ((specialx - startx) < size/2 && (specialy - starty) < size/2) {
		chessboard(specialx, specialy, startx, starty, size/2);
	}else {
		rect[startx + size/2 - 1][starty + size/2 - 1] = t;
		chessboard(startx + size/2 - 1, starty + size/2 - 1, startx, starty, size/2); 
	}
	if ((specialx - startx) < size/2 && (specialy - starty) >= size/2) {
		chessboard(specialx, specialy, startx, starty + size/2, size/2);
	}else {
		rect[startx + size/2 - 1][starty + size/2] = t;
		chessboard(startx + size/2 - 1, starty + size/2, startx, starty + size/2, size/2);
	}
	if ((specialx - startx) >= size/2 && (specialy - starty) < size/2) {
		chessboard(specialx, specialy, startx + size/2, starty, size/2);
	}else {
		rect[startx + size/2][starty + size/2 - 1] = t;
		chessboard(startx + size/2, starty + size/2 - 1, startx + size/2, starty, size/2);
	}
	if ((specialx - startx) >= size/2 && (specialy - starty) >= size/2) {
		chessboard(specialx, specialy, startx + size/2, starty + size/2, size/2);
	}else {
		rect[startx + size/2][starty + size/2] = t;
		chessboard(startx + size/2, starty + size/2, startx + size/2, starty + size/2, size/2);
	}
}

int main(int argc, char *argv[]) {
	int k;
	int x, y;

	// set 
	memset(rect, 0, sizeof(rect));

	scanf("%d", &k); //the rect size
	scanf("%d %d", &x, &y); // the specail position

	// startx        starty
	rect[x][y] = MARK++; // MAKR

	int size = 1; // the size
	for (int i=0; i<k; i++) { // multiply one more time
		size *= 2;
	}

	if (size > SIZE) { //fatal error
		printf("the size is too large\n");
		exit(-1);
	}else {
	//	printf("k=%d, x=%d, y=%d, size=%d\n", k, x, y, size);
	}

	// specail x, y, start x, y,  size 
	chessboard(x, y, 0, 0, size); //invoke

	// display
	for (int i=0; i<size; i++) {
		for (int j=0; j<size; j++) {
			printf("%4d", rect[i][j]);
		}
		printf("\n");
	}

	return 0;
}
