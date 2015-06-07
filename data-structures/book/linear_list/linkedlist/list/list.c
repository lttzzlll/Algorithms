#include "../../../../../utility/type/type.h"
#include "../../../../../utility/number/number.h"
#include "../linklist.h"
#include "list.h"
#include <stdio.h>
#include <assert.h>

// initialize a  list
Status InitList(List *L) {
    Status res;
    res = InitList_L((LinkList *)L);
    assert(L != NULL);
    return res;
}

// insert an element into the  list
Status ListInsert(List *L, int i, ElemType e) {
    return ListInsert_L((LinkList *)L, i, (ElemType_L)e);
}

// delete an element from a eisiting list
Status ListDelete(List *L, int i, ElemType *e) {
    return ListDelete_L((LinkList *)L, i, (ElemType_L *)e);
}

// locate the position of an element in a existing list
int LocateElem(List *L, ElemType e, Bool (*compare)(ElemType, ElemType)) {
    return LocateElem_L((LinkList *)L, (ElemType_L)e, compare);
}

// merge the two sorted list into  a new sorted[just] list
void MergeList(List *La, List *Lb, List *Lc) {
    MergeList_L((LinkList *)La, (LinkList *)Lb, (LinkList *)Lc);
}

// destory a  list
Status DestoryList(List *L) {
    return DestoryList_L((LinkList *)L);
}

// clear a  list
Status ClearList(List *L) {
    return ClearList_L((LinkList *)L);
}

// check if a list is empty
Bool ListEmpty(List *L) {
    return ListEmpty_L((LinkList *)L);
}

// get the list length
int ListLength(List *L) {
    return ListLength_L((LinkList *)L);
}

// get an element from a list if it existing
Status GetElem(List *L, int i, ElemType *e) {
    return GetElem_L((LinkList *)L, i, (ElemType_L *)e);
}

// get the preview element of the current element in a existing sequence list
Status PriorElem(List *L, ElemType cur_e, ElemType *pre_e, Bool (*compare)(ElemType, ElemType)) {
    return PriorElem_L((LinkList *)L, (ElemType_L)cur_e, (ElemType_L *)pre_e, compare);
}

// get the next element of the current element in a exising  list if exist
Status NextElem(List *L, ElemType cur_e, ElemType *next_e, Bool (*compare)(ElemType, ElemType)) {
    return NextElem_L((LinkList *)L, cur_e, (ElemType_L *)next_e, compare);
}

// visit each element in a existing list
Status ListTraverse(List *L, Status (*visit)(ElemType e)) {
    return ListTraverse_L((LinkList *)L, visit);
}
