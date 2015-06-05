#ifndef __SQLIST_H__
#define __SQLIST_H__

#define OK 1
#define ERROR -1
#define OVERFLOW -2

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef int Status_Sq;
typedef int ElemType_Sq; // in fact, it is a int type

typedef struct sqlist {
    ElemType_Sq *elem;
    int length;
    int listsize;
}Sqlist;

// initialize a sequence list
Status_Sq InitList_Sq(Sqlist *L);

// insert an element into the sequence list
Status_Sq ListInsert_Sq(Sqlist *L, int i, ElemType_Sq e);

// delete an element from a eisiting list
Status_Sq ListDelete_Sq(Sqlist *L, int i, ElemType_Sq *e);

// locate the position of an element in a existing sequence list
int LocateElem_Sq(Sqlist *L, ElemType_Sq e, Bool (*compare)(ElemType_Sq, ElemType_Sq));

// merge the two sorted list into  a new sorted[just] list
void MergeList_Sq(Sqlist *La, Sqlist *Lb, Sqlist *Lc);

// destory a sequence list
Status_Sq DestoryList_Sq(Sqlist *L);

// clear a sequence list
Status_Sq ClearList_Sq(Sqlist *L);

// check if a sequence list is empty
Bool ListEmpty_Sq(Sqlist *L);

// get the sequence list length
int ListLength_Sq(Sqlist *L);

// get an element from a sequence list if it existing
Status_Sq GetElem_Sq(Sqlist *L, int i, ElemType_Sq *e);

// get the preview element of the current element in a existing sequence list
Status_Sq PriorElem_Sq(Sqlist *L, ElemType_Sq cur_e, ElemType_Sq *pre_e, Bool (*compare)(ElemType_Sq, ElemType_Sq));

// get the next element of the current element in a exising sequence list if exist
Status_Sq NextElem_Sq(Sqlist *L, ElemType_Sq cur_e, ElemType_Sq *next_e, Bool (*compare)(ElemType_Sq, ElemType_Sq));

// visit each element in a existing sequence list
Status_Sq ListTraverse_Sq(Sqlist *L, Status_Sq (*visit)(ElemType_Sq e));

#endif
