#ifndef __SQLIST_H__
#define __SQLIST_H__

#define OK 1
#define ERROR -1
#define OVERFLOW -2

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef int Status;
typedef int ElemType; // in fact, it is a int type

typedef struct sqlist {
    ElemType *elem;
    int length;
    int listsize;
}Sqlist;

// initialize a sequence list
Status InitList_Sq(Sqlist *L);

// insert an element into the sequence list
Status ListInsert_Sq(Sqlist *L, int i, ElemType e);

// delete an element from a eisiting list
Status ListDelete_Sq(Sqlist *L, int i, ElemType *e);

// locate the position of an element in a existing sequence list
int LocateElem_Sq(Sqlist *L, ElemType e, Bool (*compare)(ElemType, ElemType));

// merge the two sorted list into  a new sorted[just] list
void MergeList_Sq(Sqlist *La, Sqlist *Lb, Sqlist *Lc);

// destory a sequence list
Status DestoryList_Sq(Sqlist *L);

// clear a sequence list
Status ClearList_Sq(Sqlist *L);

// check if a sequence list is empty
Bool ListEmpty_Sq(Sqlist *L);

// get the sequence list length
int ListLength_Sq(Sqlist *L);

// get an element from a sequence list if it existing
Status GetElem_Sq(Sqlist *L, int i, ElemType *e);

// get the preview element of the current element in a existing sequence list
Status PriorElem_Sq(Sqlist *L, ElemType cur_e, ElemType *pre_e, Bool (*compare)(ElemType, ElemType));

// get the next element of the current element in a exising sequence list if exist
Status NextElem_Sq(Sqlist *L, ElemType cur_e, ElemType *next_e, Bool (*compare)(ElemType, ElemType));

// visit each element in a existing sequence list
Status ListTraverse_Sq(Sqlist *L, Status (*vist)(ElemType e));

#endif
