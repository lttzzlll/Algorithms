#include "linkedList.h"
#include <stdlib.h>

// implementation
struct Node {
    ElementType Element;
    Position Next;
};

List IntegerListCreate() {
    List L = (List)malloc(sizeof(struct Node));
    if (L == NULL) {
        exit(-1);
    }
    L->Next = NULL;
    return L;
}

List MakeEmpty(List L) {
    DeleteList(L);
    return L;
}

int IsEmpty(List L) {
    return L->Next == NULL;
}

int IsLast(Position P, List L) {
    return P->Next == NULL;
}

Position Find(ElementType X, List L) {
    Position P; // declaration
    P = L->Next; // assignment
    while (P != NULL && P->Element != X) {
        P = P->Next;
    }
    return P;
}

Position FindPrevious(ElementType X, List L) {
    Position P; // declaration
    P = L; // assignment [L<Node> is the dummy Node, wouldn't be None]
    while (P->Next != NULL && P->Next->Element != X) {
        P = P->Next;
    }
    return P;
}

void Delete(ElementType X, List L) {
    Position P, TmpCell;
    P = FindPrevious(X, L);
    if (!IsLast(P, L)) {
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free(TmpCell);
    }
}

void Insert(ElementType X, List L, Position P) {
    Position TmpCell;
    TmpCell = (struct Node *)malloc(sizeof(struct Node));
    if (TmpCell == NULL) {
        exit(-1); // anyway, a error handle process will be excute!
    }
    TmpCell->Element = X;
    TmpCell->Next =  P->Next;
    P->Next = TmpCell;
}



void DeleteList(List L) {
    Position P, TmpCell;
    P = L->Next;
    L->Next = NULL;
    while (P != NULL) {
        TmpCell = P->Next;
        free(P);
        P = TmpCell;
    }
}

// public interface will not used in this file
// for user
Position Header(List L) {
    return L;
}

// for user
Position First(List L) {
    return L->Next;
}

// for user
Position Advance(Position P, List L) {
    Position I;
    I = L;
    while (I != NULL && I->Next != P) {
        I = I->Next;
    }
    return I;
}

// for user
ElementType Retrieve(Position P) {
    return P->Element;
}

// additional methods
void ListPrint(List L, void (*ElementPrint)(ElementType X)) {
    Position P;
    P = L->Next;
    while (P != NULL) {
        ElementPrint(P->Element);
        P = P->Next;
    }
}

// append an element in the list
Position GetLast(List L) {
    Position P = L;
    while (P->Next != NULL) {
        P = P->Next;
    }
    return P;
}

void Append(ElementType X, List L) {
    Position P, TmpCell;
    P = GetLast(L);
    TmpCell = (struct Node *)malloc(sizeof(struct Node));
    if (TmpCell == NULL) {
        exit(-1);
    }
    TmpCell->Element = X;
    TmpCell->Next = NULL;
    P->Next = TmpCell;
}

int Length(List L) {
    int Counts = 0;
    Position P;
    P = L->Next;
    while (P != NULL) {
        P = P->Next;
        Counts++;
    }
    return Counts;
}


