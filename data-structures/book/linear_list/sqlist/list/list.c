#include "../../../../../utility/type/type.h"
#include "../../../../../utility/number/number.h"
#include "../sqlist.h"
#include "list.h"


// initialize a  list
Status InitList(List *L) {
    return InitList_Sq((Sqlist *)L);
}

// insert an element into the  list
Status ListInsert(List *L, int i, ElemType e) {
    return ListInsert_Sq((Sqlist *)L, i, e);
}

// delete an element from a eisiting list
Status ListDelete(List *L, int i, ElemType *e) {
    return ListDelete_Sq((Sqlist *)L, i, e);
}

// locate the position of an element in a existing list
int LocateElem(List *L, ElemType e, Bool (*compare)(ElemType, ElemType)) {
    return LocateElem_Sq((Sqlist *)L, e, compare);
}

// merge the two sorted list into  a new sorted[just] list
void MergeList(List *La, List *Lb, List *Lc) {
    MergeList_Sq((Sqlist *)La, (Sqlist *)Lb, (Sqlist *)Lc);
}

// destory a  list
Status DestoryList(List *L) {
    return DestoryList_Sq((Sqlist *)L);
}

// clear a  list
Status ClearList(List *L) {
    return ClearList_Sq((Sqlist *)L);
}

// check if a list is empty
Bool ListEmpty(List *L) {
    return ListEmpty_Sq((Sqlist *)L);
}

// get the list length
int ListLength(List *L) {
    return ListLength_Sq((Sqlist *)L);
}

// get an element from a list if it existing
Status GetElem(List *L, int i, ElemType *e) {
    return GetElem_Sq((Sqlist *)L, i, e);
}

// get the preview element of the current element in a existing sequence list
Status PriorElem(List *L, ElemType cur_e, ElemType *pre_e, Bool (*compare)(ElemType, ElemType)) {
    return PriorElem_Sq((Sqlist *)L, cur_e, pre_e, compare);
}

// get the next element of the current element in a exising  list if exist
Status NextElem(List *L, ElemType cur_e, ElemType *next_e, Bool (*compare)(ElemType, ElemType)) {
    return NextElem_Sq((Sqlist *)L, cur_e, next_e, compare);
}

// visit each element in a existing list
Status ListTraverse(List *L, Status (*visit)(ElemType e)) {
    return ListTraverse_Sq((Sqlist *)L, visit);
}
