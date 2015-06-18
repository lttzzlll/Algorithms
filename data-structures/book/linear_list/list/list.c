#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// allcate space of e to p
Status MakeNode(Link *p, ElemType e) {
    if (!((*p) = (Link)malloc(sizeof(struct LNode)))) {
        return ERROR;
    }
    (*p)->data = e;
    (*p)->next = NULL;
    return OK;
}

// free p
void FreeNode(Link p) {
//    assert(p != NULL);
//    printf("p->data is %d\n", (int)p->data);
//    free(p);
//    printf("i do nothing\n");
}

// init a list
Status InitList(LinkList *L) {
    L->len = 0;
    L->head = NULL;
    L->tail = NULL;
    return OK;
}

// destory a list
Status DestoryList(LinkList *L) {
    ClearList(L);
    return OK;
}

// clear list
Status ClearList(LinkList *L) {
    Link p, temp = NULL;
    for (p = GetHead(L); p != GetLast(L); p = NextPos(L, p)) {
        FreeNode(temp);
        temp = p;
    }
    FreeNode(temp);
    return OK;
}

// insert s into the first element
Status InsFirst(Link h, Link s) {
    s->next = h->next;
    h->next = s;
    return OK;
}

// delete the first element to q
Status DelFirst(Link *h, Link *q) {
    *q = *h;
    (*h) = (*h)->next;
    return OK;
}

// append s at the last position of l
Status Append(LinkList *L, Link *s) {
    if (ListEmpty(L)) {
//        printf("here\n");
        L->head = *s;
        L->tail = *s;
//        printf("here\n");
    } else {
//        printf("there list length is: %d\n", ListLength(L));
        Link p = GetLast(L);
//        printf("get last after\n");
//        assert(p != NULL);
//        assert(p->next != NULL);
        p->next = *s;
//        assert (p->next != NULL);
//        printf("middle\n");
        L->tail = *s;
//        printf("end there\n");
    }
    ++L->len;
    return OK;
}

// delete the laste element to q
Status Remove(LinkList *L, Link *q) {
    Link p, temp;
    temp = GetLast(L);
    p = PriorPos(L, temp);
    
    *q = GetLast(L);
    
    p->next = temp->next;
    if (GetLast(L) == GetHead(L)) {
        L->head = p;
    }
    L->tail = p;
    
    return OK;
}

// insert s before p at l
Status InsBefore(LinkList *L, Link *p, Link s) {
    if (GetHead(L) == *p) {
        s->next = *p;
        L->head = s;
    } else {
        Link previous = PriorPos(L, *p);
        s->next = *p;
        previous->next = s;
    }
    return OK;
}

// insert s after p at l
Status InsAfter(LinkList *L, Link *p, Link s) {
    if (GetLast(L) == *p) {
        s->next = NULL;
        (*p)->next = s;
        L->tail = s;
    } else {
        Link next = NextPos(L, *p);
        s->next = next;
        (*p)->next = s;
    }
    return OK;
}

// set e to p->data
Status SetCurElem(Link *p, ElemType e) {
    (*p)->data = e;
    return OK;
}

// get element from p
ElemType GetCurElem(Link p) {
    return p->data;
}

// return True if l is empty
Status ListEmpty(LinkList *L) {
    if (ListLength(L) > 0) {
        return False;
    } else {
        return True;
    }
}

// get list lenght
int ListLength(LinkList *L) {
    return L->len;
}

//get the head element
Position GetHead(LinkList *L) {
    return L->head;
}

// get the last element
Position GetLast(LinkList *L) {
    return L->tail;
}

// get the previous element of p
Position PriorPos(LinkList *L, Link p) {
    if (p == GetHead(L)) {
        return NULL;
    }
    
    for (Link cur = GetHead(L); cur != GetLast(L); cur = NextPos(L, cur)) {
        if (NextPos(L, cur) == p) {
            return cur;
        }
    }
    return NULL;
}

// get the next element of p
Position NextPos(LinkList *L, Link p) {
    if (p == GetLast(L)) {
        return NULL;
    }
    return p->next;
}

// get the position of the i[th]
Status LocatePos(LinkList *L, int i, Link *p) {
    int counter = 1;
    Link cur;
    for (cur = GetHead(L); cur !=*p && counter != i; cur = NextPos(L, cur)) {
        ++counter;
    }
    if (cur == NULL || counter > i) {
        return ERROR;
    } else {
        return OK;
    }
}

// get the element position which equals to element e
Position LocateElem(LinkList *L, ElemType e, Status(* compare)(ElemType , ElemType)) {
    for (Link cur = GetHead(L); cur != NULL; cur = NextPos(L, cur)) {
        if (compare(GetCurElem(cur), e)) {
            return cur;
        }
    }
    return NULL;
}

// visit each element
Status ListTraverse(LinkList *L, Status (*visit)(ElemType )) {
    for (Link cur = GetHead(L); cur != NULL; cur = NextPos(L, cur)) {
        if (!visit(GetCurElem(cur))) {
            return ERROR;
        }
    }
    return OK;
}

// merge two sorted list

Status MergeList(LinkList *La, LinkList *Lb, LinkList *Lc, int (*compare)(ElemType, ElemType)) {
    Link ha, hb, pa, pb, *q;
    ElemType a, b;
    if (!InitList(Lc)) {
        return ERROR;
    }
    ha = GetHead(La);
    hb = GetHead(Lb);
    pa = NextPos(La, ha);
    pb = NextPos(Lb, hb);
    
    while (pa && pb) {
        static int counter = 0;
        printf("counter is %d\n", ++counter);
        a = GetCurElem(pa);
        b = GetCurElem(pb);
        printf("a=%d, b=%d\n", (int)a, (int)b);
        if ((*compare)(a, b) <= 0) {
            DelFirst(&ha, q);
            Append(Lc, q);
            pa = NextPos(La, ha);
        } else {
            DelFirst(&hb, q);
            Append(Lc, q);
            pb = NextPos(Lb, hb);
        }
    }
//    printf("here is ok\n");
    if (pa) {
        Append(Lc, &pa);
    } else {
        Append(Lc, &pb);
    }
//    printf("there you wont see\n");
    FreeNode(ha);
    FreeNode(hb);
    return OK;
}