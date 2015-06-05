#include "../../../../utility/type/type.h"
#include "sqlist.h"
#include <stdlib.h>
#include <stdio.h> // for test

// initialize a sequence list
Status_Sq InitList_Sq(Sqlist *L) {
    L->elem = (ElemType_Sq *)malloc(sizeof(ElemType_Sq) * LIST_INIT_SIZE);
    if (!L->elem) {
        exit(OVERFLOW);
    }
    
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;

    return OK;
}

// insert an element into the sequence list
Status_Sq ListInsert_Sq(Sqlist *L, int i, ElemType_Sq e) {
    if (i < 1 || i > L->length + 1) { // the insert position validation check
        return ERROR;
    }
    if (L->length >= L->listsize) {
        ElemType_Sq *newbase = (ElemType_Sq *)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(ElemType_Sq));
        if (!newbase) {
            exit(OVERFLOW);
        }
        L->elem = newbase;
        L->listsize += LISTINCREMENT;
    }
    ElemType_Sq *q = &L->elem[i-1];
    for (ElemType_Sq *p = &L->elem[L->length-1]; p >= q; --p) {
        *(p+1) = *p;
    }
    *q = e;
    ++L->length;
        
    return OK;
}

// delete an element from a eisiting list
Status_Sq ListDelete_Sq(Sqlist *L, int i, ElemType_Sq *e) {
    if (i < 1 || i > L->length) { // the delete position validation check
        return ERROR;
    }
    ElemType_Sq *p = &L->elem[i-1];
    *e = *p;
    ElemType_Sq *q = L->elem + L->length - 1;
    for (++p; p <= q; ++p) {
        *(p-1) = *p;
    }
    --L->length;

    return OK;
}


// locate the position of an element in a existing sequence list
int LocateElem_Sq(Sqlist *L, ElemType_Sq e, Bool (*compare)(ElemType_Sq, ElemType_Sq)) {
    int i = 1;
    ElemType_Sq *p = L->elem;
    while (i <= L->length && (*compare)(*p++, e) == False) {
        ++i;
    }
    if (i <= L->length) {
        return i;
    }else {
        return 0;
    }
}

// merge the two sorted list into  a new sorted[just] list
void MergeList_Sq(Sqlist *La, Sqlist *Lb, Sqlist *Lc) {
    ElemType_Sq *pa = La->elem;
    ElemType_Sq *pb = Lb->elem;
    Lc->listsize = Lc->length = La->length + Lb->length;
    ElemType_Sq *pc = Lc->elem = (ElemType_Sq *)malloc(sizeof(ElemType_Sq) * Lc->listsize);
    if (!Lc->elem) {
        exit(OVERFLOW);
    }
    ElemType_Sq *pa_last = La->elem + La->length - 1;
    ElemType_Sq *pb_last = Lb->elem + Lb->length - 1;
    while (pa <= pa_last && pb <= pb_last) {
        if (*pa <= *pb) { // <=
            *pc++ = *pa++;
        }else {
            *pc++ = *pb++;
        }
    }
    while (pa <= pa_last) { // <=
        *pc++ = *pa++;
    }
    while (pb <= pb_last) { // <=
        *pc++ = *pb++;
    }
}


// destory a sequence list
Status_Sq DestoryList_Sq(Sqlist *L) {
    ClearList_Sq(L);
    free(L->elem);
    return OK;
}

// clear a sequence list
Status_Sq ClearList_Sq(Sqlist *L) {
    L->length = 0;
    if (L->length > LIST_INIT_SIZE) {
        free(L->elem + LIST_INIT_SIZE);
    }
    L->listsize = LIST_INIT_SIZE;
    return OK;
}

// check if a sequence list is empty
Bool ListEmpty_Sq(Sqlist *L) {
    if (L->length == 0) {
        return True;
    }else {
        return False;
    }
}

// get the sequence list length
int ListLength_Sq(Sqlist *L) {
    return L->length;
}

// get an element from a sequence list if it existing
Status_Sq GetElem_Sq(Sqlist *L, int i, ElemType_Sq *e) {
    if (i < 1 || i > L->length) { // check the validation of the i[position]
        return ERROR;
    }else {
        *e = L->elem[i-1];
        return OK;
    }
}

// get the preview element of the current element in a existing sequence list
Status_Sq PriorElem_Sq(Sqlist *L, ElemType_Sq cur_e, ElemType_Sq *pre_e, Bool (*compare)(ElemType_Sq, ElemType_Sq)) {
    int i;
    i = LocateElem_Sq(L, cur_e, compare);
    if (i > 1 && i <= L->length) {
        GetElem_Sq(L, i-1, pre_e);
        return OK;
    }else {
        return ERROR;
    }
}

// get the next element of the current element in a exising sequence list if exist
Status_Sq NextElem_Sq(Sqlist *L, ElemType_Sq cur_e, ElemType_Sq *next_e, Bool (*compare)(ElemType_Sq, ElemType_Sq)) {
    int i;
    i = LocateElem_Sq(L, cur_e, compare);
    if (i >= 1 && i < L->length) {
        GetElem_Sq(L, i+1, next_e);
        return OK;
    }else {
        return ERROR;
    }
}

// visit each element in a existing sequence list
Status_Sq ListTraverse_Sq(Sqlist *L, Status_Sq (*visit)(ElemType_Sq e)) {
    int counter = 1;
    for (ElemType_Sq *p = L->elem; counter <= L->length; p++) {
        if (!visit(*p)) {
            return ERROR;
        }
        ++counter;
    }
    return OK;
}
