#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 1000
#define INF_MAX 99999999

// adjacent matrix a[i][j]  =  distance(point i, point j)
int a[SIZE][SIZE];

// distance to source node
int dist[SIZE];

// rounting node to node[k]
int prev[SIZE];

// if added int the known set
int known[SIZE];

int n;


void init() {
	// dist[1] = 0 distance point 1 to point 1
	for(int i=2; i<=n; i++) {
		dist[i] = INF_MAX;
	}
}

void generateTestData() {
	/* book provided test data */
	a[1][2] = 10;
	a[1][4] = 30;
	a[1][5] = 100;
	a[2][3] = 50;
	a[3][5] = 10;
	a[4][3] = 20;
	a[4][5] = 60;

	/*
	// randomly generate test data
	srand((unsigned)time(NULL));
	int base, offset, set;
	base = 100;
	offset = 1;
	set = 2;
	for(int i=1; i<=n; i++) {
		for(int j=i+1; j<=n; j++) { // half table used
			a[i][j] = (rand() % base + offset) * (rand() % set);
		}
	}
	*/
}
	

void disone(int *arr, int n) {
	for(int i=1; i<=n; i++) {
		printf("%d  ", arr[i]);
	}
	printf("\n");
}

void disOneIfExist(int *arr, int n) {
	for(int i=1; i<=n; i++) {
		if(arr[i] == INF_MAX) {
			printf("unreadched  ");
		}else{
			printf("%4d", arr[i]);
		}
	}
}

void distwo(int arr[][SIZE], int n) {
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			printf("%4d", arr[i][j]);
		}
		printf("\n");
	}
}


void dijkstra() {
	int v, w;
	int tmpMinValue;
	int i;
	for(;;) {
		tmpMinValue = INF_MAX;
		for(i=1; i<=n; i++) {
			if(!known[i] && dist[i] < tmpMinValue) {
				v = i;
				tmpMinValue = dist[i];
			}
		}
		if(known[v]) {
			break;
		}
		known[v] = 1;
		for(w=1; w<=n; w++) {
			if(a[v][w]) {
				if(!known[w]) {
					if(dist[v] + a[v][w] < dist[w]) {
						dist[w] = dist[v] + a[v][w];
					}
				}
			}
		}
	}
}

int main() {
	n = 5;

	generateTestData();

	printf("%d\n", n);

	distwo(a, n);

	init();

	dijkstra();
	
	disone(dist, n);	

	return 0;
}

