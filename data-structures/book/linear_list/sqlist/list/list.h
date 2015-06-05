#ifndef __LIST_H__
#define __LIST_H__

#define OK 1
#define ERROR -1
#define OVERFLOW -2

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef int Status; //so, how to change this protocol?
typedef int ElemType; // in fact, it is a int type

typedef struct List {
    ElemType *elem;
    int length;
    int listsize;
}List;

// initialize a  list
Status InitList(List *L);

// insert an element into the  list
Status ListInsert(List *L, int i, ElemType e);

// delete an element from a eisiting list
Status ListDelete(List *L, int i, ElemType *e);

// locate the position of an element in a existing list
int LocateElem(List *L, ElemType e, Bool (*compare)(ElemType, ElemType));

// merge the two sorted list into  a new sorted[just] list
void MergeList(List *La, List *Lb, List *Lc);

// destory a  list
Status DestoryList(List *L);

// clear a  list
Status ClearList(List *L);

// check if a list is empty
Bool ListEmpty(List *L);

// get the list length
int ListLength(List *L);

// get an element from a list if it existing
Status GetElem(List *L, int i, ElemType *e);

// get the preview element of the current element in a existing sequence list
Status PriorElem(List *L, ElemType cur_e, ElemType *pre_e, Bool (*compare)(ElemType, ElemType));

// get the next element of the current element in a exising  list if exist
Status NextElem(List *L, ElemType cur_e, ElemType *next_e, Bool (*compare)(ElemType, ElemType));

// visit each element in a existing list
Status ListTraverse(List *L, Status (*vist)(ElemType e));

#endif
