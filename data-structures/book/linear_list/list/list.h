#ifndef __LIST_H__
#define __LIST_H__

typedef enum Status {
    False = 0,  ERROR = 0,
    True = 1, OK = 1
}Status;

typedef int ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode *next;
}*Link, *Position;

typedef struct {
    Link head, tail;
    int len;
}LinkList;

// allcate space of e to p
Status MakeNode(Link *p, ElemType e);

// free p
void FreeNode(Link p);

// init a list
Status InitList(LinkList *L);

// destory a list
Status DestoryList(LinkList *L);

// clear list
Status ClearList(LinkList *L);

// insert s into the first element
Status InsFirst(Link h, Link s);

// delete the first element to q
Status DelFirst(Link *h, Link *q);

// append s at the last position of l
Status Append(LinkList *L, Link *s);

// delete the laste element to q
Status Remove(LinkList *L, Link *q);

// insert s before p at l
Status InsBefore(LinkList *L, Link *p, Link s);

// insert s after p at l
Status InsAfter(LinkList *L, Link *p, Link s);

// set e to p->data
Status SetCurElem(Link *p, ElemType e);

// get element from p
ElemType GetCurElem(Link p);

// return True if l is empty
Status ListEmpty(LinkList *L);

// get list lenght
int ListLength(LinkList *L);

//get the head element
Position GetHead(LinkList *L);

// get the last element
Position GetLast(LinkList *L);

// get the previous element of p
Position PriorPos(LinkList *L, Link p);

// get the next element of p
Position NextPos(LinkList *L, Link p);

// get the position of the i[th]
Status LocatePos(LinkList *L, int i, Link *p);

// get the element position which equals to element e
Position LocateElem(LinkList *L, ElemType e, Status(* compare)(ElemType , ElemType));

// visit each element
Status ListTraverse(LinkList *L, Status (*visit)(ElemType ));

// merge to sorted list

Status MergeList(LinkList *La, LinkList *Lb, LinkList *Lc, int (*compare)(ElemType, ElemType));

#endif