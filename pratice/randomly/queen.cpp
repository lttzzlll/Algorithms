#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>

const unsigned long maxshort = 65536L;
const unsigned long multiplier = 1194211693L;
const unsigned long adder = 12345L;

#define SIZE 16
                  //0  1  2  3  4   5  6  7   8   9    10   11    12
int solve[SIZE] = { 0, 1, 0, 0, 2, 10, 4, 40, 92, 352, 724, 2680, 14200};

struct RandomNumber {
	unsigned long randSeed;

	RandomNumber(unsigned long s = 0) {
		if (s == 0) randSeed = time(0);
		else randSeed = s;
	}

	unsigned short Random(unsigned long n) {
		randSeed = multiplier * randSeed + adder;
		return (unsigned short) (randSeed >> 16) % n;
	}
	double fRandom(void) {
		return Random (maxshort) / (double)maxshort;
	}
};

class Queen {
	public:

	int n;
	int *x, *y;
	// new fields
	int runtimes;
	time_t start, end;
	float runtime;

	Queen(int n) {
		this->n = n;
		x = new int[n+1];
		y = new int[n+1];
		for (int i=0; i<=n; i++) {
			x[i] = y[i] = 0;
		}
		this->runtimes = 0;
		this->start = clock();
	}

	~Queen() {
		delete [] x;
		delete [] y;
	}

	bool place(int k) {
		for (int i=1; i<k; i++) {
			if (abs(k-i) == abs(x[k] - x[i]) || x[k] == x[i]) {
				return false;
			}
		}
		return true;
	}

	bool queenLV(void) {
		RandomNumber rnd;
		int k = 1;
		int count = 1;
		y = new int[n+1];
		while (k <= n && count > 0) {
			count = 0;
			for (int i=1; i<=n; i++) {
				runtimes++;
				x[k] = i;
				if (place(k)) {
					y[count++] = i;
				}
			}
			if (count > 0) {
				x[k++] = y[rnd.Random(count)];
			}
		}
		return count > 0;
	}

	void queen(int n) {
		while (!queenLV()) {
			runtimes++;
		}
		this->end = clock();
		this->runtime = (float)(end - start) / CLOCKS_PER_SEC;
	}

	void show() {
		for (int i=1; i<=n; i++) {
			printf("%d ", x[i]);
		}
		printf("\n");
		printf("%d | %f\n", this->runtimes, this->runtime);
	}

};


class QueenBT: public Queen {
	public:
	
	QueenBT(int n):Queen(n) {}

	bool backtrack(int t) {
		if (t > n) {
			//for (int i=1; i<=n; i++) { // do what??
			//	y[i] = x[i];
			//}
			return  true;
		}else {
			for (int i=1; i<=n; i++) {
				runtimes++;
				x[t] = i;
				if (place(t) && backtrack(t+1)) {
					return true;
				}
			}
			return false;
		}
	}

	virtual bool queenLV(int stopVegas) {
		RandomNumber rnd;
		int k = 1;
		int count = 1;
		while ( k <= stopVegas && count > 0) {
			count = 0;
			for (int i=1; i<=n; i++) {
				runtimes++;
				x[k] = i;
				if (place(k)) {
					y[count++] = i;
				}
			}
			if (count > 0) {
				x[k++] = y[rnd.Random(count)];
			}
		}
		return count > 0;
	}

		
	virtual bool queen(int stop= 5, int n=8) {
		if (n > 15) {
			stop = n - 15;
		}

		bool found = false;

		while (!queenLV(stop)) { 
			runtimes++;
		}

		if (backtrack(stop+1)) {
			found = true;
		}
		
		end = clock();
		runtime = (float)(end - start) / CLOCKS_PER_SEC;

		return found;
	}

};


int main(int argc, char *argv[]) {
	srand((unsigned)time(NULL));

	int n = 8, stopVegas = 5;
	if (argc > 1) {
		sscanf(argv[1], "%d", &n);
	}
	if (argc > 2) {
		sscanf(argv[2], "%d", &stopVegas);
	}

	printf("%d\n", n);

	Queen *que = new Queen(n);

	que->queen(n);
	que->show();

	QueenBT *queBT = new QueenBT(n);

	if (queBT->queen(stopVegas)) {
		queBT->show();
	}else {
		printf("no found\n");
	}

	delete que;
	delete queBT;
	return 0;
}

