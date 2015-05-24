#ifndef __LINKLIST__H__
#define __LINKLIST__H__

// node 
typedef struct LinkListNode {
	void *data;
	struct LinkListNode *next;
}LinkListNode;

// linklist info 
typedef struct LinkList {
	int size;
	int (*match)(const void *key1, const void *key2);
	void (*destory)(void *data);
	LinkListNode *head;
	LinkListNode *tail;
}LinkList;

// public interface
void LinkListInit(LinkList *list, int (*match)(const void *key1, const void *key2), void (*destory)(void *data));
void LinkListDestory(LinkList *list);
int LinkListInsertNext(LinkList *list, LinkListNode *curNode, void *data);
int LinkListRemoveNext(LinkList *list, LinkListNode *curNode, void **data);	
int LinkListSearch(LinkList *list, LinkListNode *searchNode);
int LinkListModify(LinkList *list, LinkListNode *modifyNode, void *newData);
LinkListNode *LinkListSearchByData(LinkList *list, void *searchData);

#define SUCCESS 1
#define FAILURE 0
#define ERROR -1
// private
#define LinkListSize(list) ((list)->size)
#define LinkListHead(list) ((list)->head)
#define LinkListTail(list) ((list)->tail)
#define isLinkListEmpty(list) ((list)->size == 0 ? SUCCESS : FAILURE)
#define isLinkListHead(list, curNode) ((curNode) == ((list)->head) ? SUCCESS : FAILURE)
#define isLinkListTail(list, curNode) ((curNode) == ((list)->tail) ? SUCCESS : FAILURE)
#define LinkListData(curNode) ((curNode)->data)
#define LinkListNodeNext(curNode) ((curNode)->next)

#endif
