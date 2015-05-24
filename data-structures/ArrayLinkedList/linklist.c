
#include <stdlib.h>
#include <string.h>
#include <stdio.h>// will be remove later just for print debug information

#include "linklist.h"

static void LinkListNodeInit(LinkListNode *curNode) {
	curNode->data = NULL;
	curNode->next = NULL;
}

void LinkListInit(LinkList *list, int (*match)(const void *key1, const void *key2), void (*destory)(void *data)) {
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	list->match = match;
	list->destory = destory;
}

int LinkListInsertNext(LinkList *list, LinkListNode *curNode, void *newData) {
	LinkListNode *newNode;
	if ((newNode = (LinkListNode *)malloc(sizeof(LinkListNode))) == NULL) {
		return FAILURE;
	}
	LinkListNodeInit(newNode);
	newNode->data = (void *)newData;
	if (curNode == NULL) { // insert into the head
		if(isLinkListEmpty(list) == SUCCESS) { // empty
			list->head = newNode;
			list->tail = newNode;
		}else { //not empty
			newNode->next = list->head;
			list->head = newNode;
		}
	}else {
		if (isLinkListTail(list, curNode) == SUCCESS) { //tail
			curNode->next = newNode;
			list->tail = newNode;
		}else { // no tail
			newNode->next = curNode->next;
			curNode->next = newNode;
		}
	}
	list->size++;
	return SUCCESS;
}

int LinkListRemoveNext(LinkList *list, LinkListNode *curNode, void **reserveData) {
	LinkListNode *tempNode;
	if (isLinkListEmpty(list) == SUCCESS) { // empty
		return FAILURE;
	}
	if (curNode == NULL) { // remove the head node
		*reserveData = list->head->data;
		tempNode = list->head;
		list->head = list->head->next;
		free(tempNode);
	}else {
		if (LinkListSize(list) == 1) { // just the curNode alive
			*reserveData = NULL;
		}else {
			*reserveData = curNode->next->data;
			tempNode = curNode->next;
			curNode->next = curNode->next->next;
			free(tempNode);
		}
	}
	list->size--;
	return SUCCESS;
}

void LinkListDestory(LinkList *list) {
	void *tempData;   //  from the head to delete
	if (list->destory != NULL) { // destory function is a destructure function
		while (LinkListRemoveNext(list, NULL, (void *)&tempData) == SUCCESS) {
			printf("in loop of linklistremovenext\n");
			list->destory(tempData);
		}
	}
	memset(list, 0, sizeof(*list));
}

LinkListNode *LinkListSearchByData(LinkList *list, void *searchData) {
	for (LinkListNode *curNode=list->head; curNode!=NULL; curNode=curNode->next) {
		if (list->match(curNode->data, searchData) == SUCCESS) { // curNode loaded the search data
			return curNode;
		}
	}
	return NULL;
}

// judge if a node is in linklist 
int LinkListSearch(LinkList *list, LinkListNode *searchNode) {
	for (LinkListNode *curNode=list->head; curNode!=NULL; curNode=curNode->next) {
		if (curNode == searchNode) {
			return SUCCESS;
		}
	}
	return FAILURE;
}

int LinkListModify(LinkList *list, LinkListNode *modifyNode, void *newData) {
	if (LinkListSearch(list, modifyNode) == SUCCESS) {
		modifyNode->data = newData;
		return SUCCESS;
	}
	return FAILURE;
}	

