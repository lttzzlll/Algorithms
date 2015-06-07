#include "../../../../utility/type/type.h"
#include "linklist.h"
#include <stdlib.h>
#include <stdio.h> // may be for test
#include <assert.h>

// initialize a lined list
Status_L InitList_L(LinkList *L) {
    *L = (struct LNode *)malloc(sizeof(struct LNode));
    if (*L == NULL) {
        exit(OVERFLOW);
    }
    (*L)->next = NULL;
    assert(*L != NULL);
    return OK;
}

// insert an element into the linked list
Status_L ListInsert_L(LinkList *L, int i, ElemType_L e) {
    struct LNode *p;
    int j;
    j = 0;
    p = *L;
    
    while (p && j < i - 1) {
        p = p->next;
        ++j;
    }
    if (!p && j > i - 1) {
        return ERROR;
    }
    struct LNode *s = (struct LNode *)malloc(sizeof(struct LNode));
    if (s == NULL) {
        exit(OVERFLOW);
    }
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

// delete an element from a eisiting list
Status_L ListDelete_L(LinkList *L, int i, ElemType_L *e) {
    struct LNode *prev, *cur;
    
    if (i < 1 || i > ListLength_L(L)) {
        return ERROR;
    }
    
    int j = 1;
    prev = *L;
    cur = (*L)->next;
    while (cur != NULL && j < i) {
        prev = cur;
        cur = cur->next;
        ++j;
    }
    if (cur == NULL) {
        return ERROR;
    }
    
    prev->next = cur->next;
    *e = cur->data;
    free(cur);
    
    return OK;
}

// locate the position of an element in a existing linked list
int LocateElem_L(LinkList *L, ElemType_L e, Bool (*compare)(ElemType_L, ElemType_L)) {
    int i = 1;
    struct LNode *p = (*L)->next;
    while (p != NULL && p->data != e) {
        p = p->next;
        ++i;
    }
    if (!p) {
        return 0;
    }
    return i;
}

// merge the two sorted list into  a new sorted[just] list
void MergeList_L(LinkList *La, LinkList *Lb, LinkList *Lc) {
    struct LNode *pa, *pb, *pc;
    pa = (*La)->next;
    pb = (*Lb)->next;
    *Lc = pc = *La;
    
    while (pa && pb) {
        if (pa->data <= pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        } else {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa ? pa : pb;
    
    // added for marked
    free(*Lb); // actually it freed the first[yack] element of lb
    *Lb = NULL;
}

// destory a linked list
Status_L DestoryList_L(LinkList *L) {
    assert(*L != NULL);
    if (ClearList_L(L) == ERROR) {
        return ERROR;
    }
    
    
//    assert(L != NULL && *L != NULL);
    free(*L); // free the first element [yack]
    
    return OK;
}

// clear a linked list
Status_L ClearList_L(LinkList *L) {
    if (*L == NULL) {
        return ERROR;
    }
    struct LNode *cur = (*L)->next, *temp = NULL;
    while (cur != NULL) {
        temp = cur;
        cur = cur->next;
        free(temp);
    }
    return OK;
}

// check if a linked list is empty
Bool ListEmpty_L(LinkList *L) {
    if (ListLength_L(L) == 0) {
        return True;
    } else {
        return False;
    }
}

// get the lined list length
int ListLength_L(LinkList *L) {
    assert(*L != NULL);
    int length = 0;
    struct LNode *p;
    p = (*L)->next;
    
    while (p != NULL) {
        p = p->next;
        ++length;
    }
    return length;
}

// get an element from a linked list if it existing
Status_L GetElem_L(LinkList *L, int i, ElemType_L *e) {
    struct LNode *p = (*L)->next;
    int j = 1;
    while (p && j < i) {
        p = p->next;
        ++j;
    }
    if (!p || j > i) {
        return ERROR;
    }
    *e = p->data;
    return OK;
}

// get the preview element of the current element in a linked sequence list
Status_L PriorElem_L(LinkList *L, ElemType_L cur_e, ElemType_L *pre_e, Bool (*compare)(ElemType_L, ElemType_L)) {
    int length, i;
    length = ListLength_L(L);
    i = LocateElem_L(L, cur_e, compare);
    if (i > 1 && i <= length) {
        GetElem_L(L, i-1, pre_e);
        return OK;
    }else {
        return ERROR;
    }
}

// get the next element of the current element in a exising linked list if exist
Status_L NextElem_L(LinkList *L, ElemType_L cur_e, ElemType_L *next_e, Bool (*compare)(ElemType_L, ElemType_L)) {
    int length, i;
    length = ListLength_L(L);
    i = LocateElem_L(L, cur_e, compare);
    if (i >= 1 && i < length) {
        GetElem_L(L, i+1, next_e);
        return OK;
    }else {
        return False;
    }
}

// visit each element in a existing linked list
Status_L ListTraverse_L(LinkList *L, Status_L (*visit)(ElemType_L e)) {
    struct LNode *p = (*L)->next;
    while (p != NULL) {
        if (visit(p->data) != OK) {
            return ERROR;
        }
        p = p->next;
    }
    return OK;
}



