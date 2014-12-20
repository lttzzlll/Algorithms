#include "linklist.h"

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
int a[SIZE];

int match(const void *a, const void *b) {
	return *(int *)a == *(int *)b;
}

void destory(int *data) {
	printf("data [%d] will be deleted!\n", *(int *)data);
	//free(data);
}


int main() {
	LinkList ll;
	LinkListInit(&ll, match, (void *)destory);
	for (int i=0; i<SIZE; i++) {
		a[i] = i;
		LinkListInsertNext(&ll, NULL, (void *)&a[i]);
	}
	printf("%d\n", LinkListSize(&ll));

	void *tempData;

	LinkListNode *tempNode;
	

	int searchNumber  = 5;
	if ( (tempNode = LinkListSearchByData(&ll, (void *)&searchNumber)) != NULL) {
		printf("%d\n", *(int *)tempNode->data);
		if ( (LinkListSearch(&ll, tempNode)) == SUCCESS) {
			printf("data->reflecting %d node in the linklit\n", *(int *)tempNode->data);
			printf("node->data %d will be modified!\n", searchNumber);
			searchNumber = 111111;
			tempData = &searchNumber;
			if ( (LinkListModify(&ll, tempNode, tempData)) == SUCCESS) {
				printf("the tempNode had been modified  and i will get it by value\n");
				if ( (tempNode = LinkListSearchByData(&ll, &searchNumber)) != NULL) {
					printf("the get data is %d\n", *(int *)tempNode->data);
				}
			}else {
				printf("node not be modified!\n");
			}
		}else {
			printf("data->reflecting is not in the linklist\n");
		}
	}else {
		printf("%d is not found\n", searchNumber);
	}

	searchNumber = -1;

	if ( (tempNode = LinkListSearchByData(&ll, (void *)&searchNumber)) != NULL) {
		printf("%d\n", *(int *)tempNode->data);
		if( (LinkListSearch(&ll, tempNode)) == SUCCESS) {
			printf("data->reflecting %d node in the linklit\n", *(int *)tempNode->data);
		}else {
			printf("data->reflecting is not in the linklist\n");
		}
	}else {
		printf("%d is not found\n", searchNumber);
	}
	while (isLinkListEmpty(&ll) != SUCCESS) {
		LinkListRemoveNext(&ll, NULL, &tempData);
		printf("%d | ", *(int *)tempData);
	}
	printf("\n");

	printf("%d\n", LinkListSize(&ll));
	
	for(int i=0; i<SIZE; i++) {
		LinkListInsertNext(&ll, NULL, a+i);
	}
	printf("%d\n", LinkListSize(&ll));

	/*
	while (LinkListRemoveNext(&ll, NULL, &tempData) == SUCCESS) {
		printf("[%d]=>{%d} | ", LinkListSize(&ll), *(int *)tempData);
	}
	printf("\n");
	*/


	printf("destory linlist ll size::%d\n", LinkListSize(&ll));
	LinkListDestory(&ll);
	printf("linklist ll had destoied!\n");
	printf("%d\n", LinkListSize(&ll));

	return 0;
}
