#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define SIZE 16 
#define MAX_INF 99999999
#define NODE_NUM 65536

struct Node {
	int path[SIZE];
	int pathIndex;
	int distance;
	int pos;
};

struct Comparator {
	bool operator()(Node *a, Node *b) {
		return a->distance <= b->distance;
	}
};

struct nodeSet {
	Node *allocPtr, *next;
	nodeSet() {
		allocPtr = (Node*)malloc(sizeof(Node) * NODE_NUM);
		if(allocPtr == NULL) {
			printf("alloc memory error!\n");
			exit(-1);
		}
		next = allocPtr;
	}

	Node *allocNextNode() {
		return next++;
	}
	~nodeSet() {
		delete []allocPtr;
	}
};

nodeSet nodes;

priority_queue<Node*, vector<Node*>, Comparator> qqq;



int rect[SIZE][SIZE];
int record[SIZE];
int permList[SIZE];
int best = MAX_INF;

// tools
void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void showArray(int *arr, int start, int end) {
	for(int i=start; i<=end; i++) {
		printf("%d  ", arr[i]);
	}
	printf("\n");
}

void showRect(int rect[SIZE][SIZE], int start, int end) {
	for(int i=start; i<=end; i++) {
		for(int j=start; j<=end; j++) {
			printf("%10d", rect[i][j]);
		}
		printf("\n");
	}
}
//end

// init data
void initData(int n) {
	for(int i=0; i<=n; i++) {
		for(int j=0; j<=n; j++) {
			rect[i][j] = MAX_INF;
		}
	}
	for(int i=0; i<=n; i++) {
		rect[i][i] = 0;
	}
}

// generate test data 

void generateTestData(int n) {
	srand((unsigned)time(NULL));
	int base, offset;
	base = 30;
	offset = 1;
	for(int i=1; i<=n; i++) {
		for(int j=i+1; j<=n; j++) {
			if(rand() % 2) {
				rect[i][j] = rand() % base + offset;
				rect[j][i] = rect[i][j];
			}
		}
	}
}

int flag = 0;
int checkList[SIZE];
void permutate(int pos, int n) {
	if(flag) {
		return ;
	}
	if(pos == n) {
		int i;
		for(i=1; i<n; i++) {
			if(rect[checkList[i]][checkList[i+1]] == MAX_INF) {
				break;
			}
		}
		if(i == n && rect[checkList[n]][1] != MAX_INF) {
			flag = 1;
			return ;
		}
	}
			
	for(int i=pos; i<=n; i++) {
		swap(checkList+pos, checkList+i);
		permutate(pos+1, n);
		swap(checkList+pos, checkList+i);
	}
}
int checkTestData(int n) {
	for(int i=0; i<=n; i++) {
		checkList[i] = i;
	}
	permutate(2, n);
	return flag == 1;
}		


Node *journey(priority_queue<Node*, vector<Node*>, Comparator> q, int n) {
	Node *curNode, *tempNode, *bestNode;
	curNode = nodes.allocNextNode();
	curNode->distance = 0;
	curNode->pos = 1;
	curNode->pathIndex = 1;
	memset(curNode->path, 0, sizeof(curNode->path));
	curNode->path[0] = 1;

	bestNode = nodes.allocNextNode();
	bestNode->distance = MAX_INF;

	q.push(curNode);

	while(!q.empty()) {
		tempNode = q.top();
		q.pop();

		if(tempNode->pathIndex == n) {
			if(bestNode->distance > tempNode->distance + rect[tempNode->path[tempNode->pathIndex-1]][1]) {
				bestNode = tempNode;
				bestNode->distance +=  rect[tempNode->path[tempNode->pathIndex-1]][1];
				bestNode->path[bestNode->pathIndex] = 1;
			}
		}
		int flag;
		for(int i=1; i<=n; i++) {
			flag = 0;
			for(int j=0; j<tempNode->pathIndex; j++) {
				if(tempNode->path[j] == i) {
					flag = 1;
					break;
				}
			}
			if(flag) {
				continue;
			}
			if(tempNode->distance + rect[tempNode->pos][i] >= bestNode->distance) {
				continue;
			}

			curNode = nodes.allocNextNode();
			curNode->pos = i;
			curNode->distance = tempNode->distance + rect[tempNode->pos][curNode->pos];
			memcpy(curNode->path, tempNode->path, sizeof(int) * tempNode->pathIndex);
			curNode->pathIndex = tempNode->pathIndex + 1;
			curNode->path[curNode->pathIndex-1] = curNode->pos;

			q.push(curNode);
		}
	}

	return bestNode;
}



int main(int argc, char *argv[]) {
	int n = 4;

	if(argc == 2) {
		sscanf(argv[1] ,"%d", &n);
	}
	
	for(int i=0; i<=n; i++) {
		permList[i] = i;
	}

	initData(n);

	rect[1][2] = 30; rect[2][1] = 30;	
	rect[1][3] = 6; rect[3][1] = 6;
	rect[1][4] = 4; rect[4][1] = 4;
	rect[2][3] = 5; rect[3][2] = 5;
	rect[2][4] = 10; rect[4][2] = 10;
	rect[3][4] = 20; rect[4][3] = 20;
	
	if(n != 4) {
		do {
			initData(n);
			generateTestData(n); 
		}while(!checkTestData(n)); // time waste!!
	}

	printf("%d\n", n);
	showRect(rect, 1, n);

	Node *final = journey(qqq, n);
	printf("%d\n", final->distance);
	showArray(final->path, 0, final->pathIndex);

	return 0;
}
