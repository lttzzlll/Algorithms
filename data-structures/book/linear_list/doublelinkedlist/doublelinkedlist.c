#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef int Status;

typedef int ElemType;

typedef struct DuLNode {
    ElemType data;
    struct DuLNode *prior;
    struct DuLNode *next;
}DuLNode, *DuLinkList;

DuLNode *GetElemP_DuL(DuLinkList L, int i) {
    int counter = 1;
    DuLNode *cur = L->next;
    while (cur && counter < i) {
        cur = cur->next;
        ++counter;
    }
    if (!cur || counter > i) {
        return NULL;
    } else {
        return cur;
    }
}

Status ListInsert_DuL(DuLinkList L, int i, ElemType e) {
    DuLNode *p, *s;
    if (!(p = GetElemP_DuL(L, i))) {
        return ERROR;
    }
    if (!(s = (DuLNode *)malloc(sizeof(DuLNode)))) {
        return ERROR;
    }
    
    s->data = e;
    s->prior = p->prior;
    p->prior->next = s;
    s->next = p;
    p->prior = s;
    
    return OK;
}

Status ListDelete_DuL(DuLinkList L, int i, ElemType *e) {
    DuLNode *p;
    if (!(p = GetElemP_DuL(L, i))) {
        return ERROR;
    }
    
    *e = p->data;
    p->prior->next = p->next;
//    printf("the next statement has a bug when the element is the last one\n");
    if(p->next != NULL) {
        p->next->prior = p->prior;
    }
    free(p);
    
    return OK;
}

void display(DuLinkList L) {
    int i = 1;
    for (DuLNode *p = L->next; p != NULL; p = p->next) {
        printf("%d element is %d\n", i++, (int)p->data);
    }
}

int main(int argc, char *argv[]) {
    int n = 10, i;
    DuLNode l;
    
    // the first yack node init
    l.next = 0;
    l.prior = 0;
    l.data = -1;
    

    DuLNode *p, *pre = &l;
    for (int i = 1; i <= n; i++) {

        if (!(p = (DuLNode *)malloc(sizeof(DuLNode)))) {
            printf("allocate space failed\n");
            exit(-1);
        }
        p->data = i * i * i;
        p->next = NULL;
        
        p->prior = pre;
        pre->next = p;
        pre = pre->next;
    }
    display(&l);
    
    // insert
    for (i = 1; i <= n; ++i) {
        ElemType e = (ElemType) (i * i * i * i);
        if (ListInsert_DuL(&l, i, e)) {
            printf("insert node[%d] into list\n", e);
        } else {
            printf("insert position[%d] node failed\n", i);
        }
    }
    display(&l);
 
    printf("*********************************\n");
    // delete
    for (i = 1; i <= n * 2; ++i) {
    
        ElemType e;
        if (ListDelete_DuL(&l, 1, &e)) {
            printf("delete node[%d] from list\n", (int)e);
            // print the left element
            display(&l);
        } else {
            printf("delete position[%d] node failed\n", 1);
        }
    }
    display(&l);
    
    return 0;
}