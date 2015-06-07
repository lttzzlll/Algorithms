#ifndef __LINKLIST_H__
#define __LINKLIST_H__


#define OK 1
#define ERROR -1
#define OVERFLOW -2

typedef int ElemType_L;
typedef int Status_L;
typedef struct LNode {
    ElemType_L data;
    struct LNode *next;
}LNode, *LinkList;


// initialize a lined list
Status_L InitList_L(LinkList *L);

// insert an element into the linked list
Status_L ListInsert_L(LinkList *L, int i, ElemType_L e);

// delete an element from a eisiting list
Status_L ListDelete_L(LinkList *L, int i, ElemType_L *e);

// locate the position of an element in a existing linked list
int LocateElem_L(LinkList *L, ElemType_L e, Bool (*compare)(ElemType_L, ElemType_L));

// merge the two sorted list into  a new sorted[just] list
void MergeList_L(LinkList *La, LinkList *Lb, LinkList *Lc);

// destory a linked list
Status_L DestoryList_L(LinkList *L);

// clear a linked list
Status_L ClearList_L(LinkList *L);

// check if a linked list is empty
Bool ListEmpty_L(LinkList *L);

// get the lined list length
int ListLength_L(LinkList *L);

// get an element from a linked list if it existing
Status_L GetElem_L(LinkList *L, int i, ElemType_L *e);

// get the preview element of the current element in a linked sequence list
Status_L PriorElem_L(LinkList *L, ElemType_L cur_e, ElemType_L *pre_e, Bool (*compare)(ElemType_L, ElemType_L));

// get the next element of the current element in a exising linked list if exist
Status_L NextElem_L(LinkList *L, ElemType_L cur_e, ElemType_L *next_e, Bool (*compare)(ElemType_L, ElemType_L));

// visit each element in a existing linked list
Status_L ListTraverse_L(LinkList *L, Status_L (*visit)(ElemType_L e));



#endif