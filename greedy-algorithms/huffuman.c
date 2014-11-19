#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 1000

typedef struct Node{
	char name[1000];
	struct Node *parent;
	struct Node *leftChild;
	struct Node *rightChild;
	int frequency;
	char code[100];
}Node;


void Ninit(Node *n) {
	n->leftChild = NULL;
	n->rightChild = NULL;
	n->parent = NULL;
	n->frequency = 0;
	memset(n->name, 0, sizeof(n->name));
	memset(n->code, 0, sizeof(n->code));
}

void Ncopy(Node *des, Node *src) {
	strcpy(des->name, src->name);
	strcpy(des->code, src->code);
	des->parent = src->parent;
	des->leftChild = src->leftChild;
	des->rightChild = src->rightChild;
	des->frequency = src->frequency;
}


void randomGenerateUniqueChar(char *s, int n) {
	srand((unsigned)time(NULL));
	for(int i = 0; i<n; i++) {
		for(;;) {
			s[i] = rand() % 26 + 'A';
			int j;
			for(j=0; j<i; j++) {
				if(s[i] == s[j]) {
					break;
				}
			}
			if(i == j) {
				break;
			}
		}
	}
}

Node *extractMin(Node *list, int n) {
	int pos = 0;
	for(int i=1; i<n; i++) {
		if(list[i].frequency < list[pos].frequency) {
			pos = i;
		}
	}
	Node *newNode = (Node*)malloc(sizeof(Node));
	Ninit(newNode);
	Ncopy(newNode, list+pos);
	for(int i=pos; i<n-1; i++) {
		list[i] = list[i+1];
	}

	return newNode;
}


void randomGenerateFrequency(Node *s, int n, int sum) {
	srand((unsigned)time(NULL));
	int rec = 0;
	for(int i=0; i<n-1; i++) {
		int t = 0;
		while(!t) {
			t = rand() % 10;
		}
		s[i].frequency = t;
		rec += s[i].frequency;
		//printf("frquency is %d\n", s[i].frequency);
	}
	s[n-1].frequency = sum - rec;
}

void display(const Node *n) {
	printf("name is [%s],", n->name);
	printf("code is [%s],", n->code);
	printf("frequency is [%d]\n", n->frequency);
	printf("leftChild is [%s],", n->leftChild->name);
	printf("rightChild is [%s],", n->rightChild->name);
	printf("parent is [%s]\n", n->parent->name);
}

void preorderVisit(Node *node) {
	if(node != NULL) {
		display(node);
		preorderVisit(node->leftChild);
		preorderVisit(node->rightChild);
	}
}

void postorderVisit(Node *node) {
	if(node != NULL) {
		postorderVisit(node->rightChild);
		postorderVisit(node->leftChild);
		display(node);
	}
}

void inorderVisit(Node *node) {
	if(node != NULL) {
		inorderVisit(node->leftChild);
		display(node);
		inorderVisit(node->rightChild);
	}
}

void CodeDisplay(const Node *node) {
	printf("node [%s] code is [%s]\n", node->name, node->code);
}

void codeShow(Node *node) {
	if(node->leftChild == NULL || node->rightChild == NULL) {
		//CodeDisplay(node);
		return ;
	}

	char c[10];
	c[0] = '0';
	c[1] = '\0';

	// touch
	strcat(node->leftChild->code, c);

	codeShow(node->leftChild);
	// strip
	//node->leftChild->code[strlen(node->leftChild->code) - strlen(node->code)] = '\0';

	//CodeDisplay(node);

	c[0] = '1';
	c[1] = '\0';

	//strcat(node->code, c);
	strcat(node->rightChild->code, c);

	codeShow(node->rightChild);

	//node->rightChild->code[strlen(node->rightChild->code) - strlen(node->code)] = '\0';
}

//int globalCnt = 0;
void CodeInOrderShow(const Node *node) {
	if(node != NULL) {
		//printf("global cnt is %d.", globalCnt++);
		CodeInOrderShow(node->leftChild);
		printf("[%s] ", node->code);
		CodeInOrderShow(node->rightChild);
	}
}

// inorder visit
// turn left
// print
// turn right 
// code is beautiful
void InorderVisit(Node *node) {
	if(node->leftChild == NULL || node->rightChild == NULL) {
		CodeDisplay(node);
		return ;
	}

	char c[10];
	
	c[0] = '0';
	c[1] = '\0';

	// logic relationship 
	//strcat(node->code, c);
	//cut and paste
	strcat(node->leftChild->code, node->code);
	strcat(node->leftChild->code, c);

	InorderVisit(node->leftChild);

	//node->name[strlen(node->code) - strlen(c)] = '\0';

	c[0] = '1';
	c[1] = '\0';

	//strcat(node->code, c);
	strcat(node->rightChild->code, node->code);
	strcat(node->rightChild->code, c);

	InorderVisit(node->rightChild);

	//node->code[strlen(node->code) - strlen(c)] = '\0';

}

void proccess(Node *node) {
	InorderVisit(node);
	
	//codeShow(node);
	//printf("code inorder show\n");
	//CodeInOrderShow(node);
	//printf("end code inorder show\n");
}

int main() {

	int n;
	n = 10;
	int sum;
	sum = 100;
	char set[100];

	randomGenerateUniqueChar(set, n);

	Node nq[100];

	// init
	for(int i=0; i<n; i++) {
		Ninit(nq+i);
	}

	randomGenerateFrequency(nq, n, sum);

	char t[10];
	for(int i=0; i<n; i++) {
		t[0] = set[i];
		t[1] = '\0';
		strcpy(nq[i].name, t);
	}

	// test
	for(int i=0; i<n; i++) {
		printf("%s %d  ", nq[i].name, nq[i].frequency);
	}
	printf("\n");

	// selected code char
	Node h[10];

	int cc = 6;

	for(int i=0; i<cc; i++) {
		Ninit(h+i);
	}

	strcpy(h[0].name, "a");
	h[0].frequency = 45;

	strcpy(h[1].name, "b");
	h[1].frequency = 13;

	strcpy(h[2].name, "c");
	h[2].frequency = 12;

	strcpy(h[3].name, "d");
	h[3].frequency = 16;

	strcpy(h[4].name, "e");
	h[4].frequency = 9;

	strcpy(h[5].name, "f");
	h[5].frequency = 5;
	int cnt = cc;
	for(int i=0; i<cc-1; i++) {
		Node *newNode = (Node*)malloc(sizeof(Node));
		if(!newNode) { printf("alloc error!\n"); exit(-1); }
		Ninit(newNode);
		Node *t1, *t2;

		t1 = extractMin(h, cnt);
		--cnt;

		t2 =extractMin(h, cnt);
		--cnt;
		
		newNode->frequency = t1->frequency + t2->frequency;
		newNode->leftChild = t1;
		newNode->rightChild = t2;
		t1->parent = newNode;
		t2->parent = newNode;
		strcat(newNode->name, t1->name);
		strcat(newNode->name, t2->name);

		Ncopy(h+cnt, newNode);
			
		++cnt;
	
		//display(h+cnt-1);

	}
	proccess(h+cnt-1);
	// end manually 


	// huffman code procedure 
	
	/*
	int cnt = n;
	for(int i=0; i<n-1; i++) {
		Node *newnode = (Node*)malloc(sizeof(Node));
		if(newnode == NULL) { printf("alloc error!\n"); exit(-1); }
		Ninit(newnode);
		Node *t1, *t2;
		t1 = extractMin(nq, cnt);

		//printf("t1 is show: ");
		//display(t1);

		--cnt;
		t2 = extractMin(nq, cnt);

		//printf("t2 is show: ");
		//display(t2);

		--cnt;
		newnode->frequency = t1->frequency + t2->frequency;
		newnode->leftChild = t1;
		newnode->rightChild = t2;
		t1->parent = newnode;
		t2->parent = newnode;
		strcat(newnode->name, t1->name);
		strcat(newnode->name, t2->name);
		
		Ncopy(nq+cnt, newnode);
		//free(newnode);
		//free(t1);
		//free(t2);
		//printf("cnt is %d| ", cnt);
		//display(nq+cnt);
		++cnt;
	}
	*/
	//printf("%d\n",cnt);
	//display(nq+cnt-1-1);
	//Node *tnode = extractMin(nq, cnt);
	//--cnt;
	//display(tnode);
	//free(tnode);
	//proccess(nq+cnt-1);
	return 0;
}
