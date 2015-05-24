#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

// the element type
// assume the element type is int [just for test]
typedef int ElementType;


// public interfaces

// is interge list create method a factory method? [if there are other methods like floatListCreate StringListCreate ?
List IntegerListCreate();

// make list empty
List MakeEmpty(List L);

// judge if the list is empty
int IsEmpty(List L);

// judge whether the position p is the last position in list l
int IsLast(Position P, List L);

// find the first position of x in list l
Position Find(ElementType X, List L);

// delete element x in list l
void Delete(ElementType X, List L);

// find the previous element of element x in list l
Position FindPrevious(ElementType X, List L);

// insert the element x of at the succeed position of p in list l
void Insert(ElementType X, List L, Position P);

// delete the list l and recover the memory
void DeleteList(List L);

// return the header of list l
Position Header(List L);

// return the first position of list l
Position First(List L);

// return the previous position before position p in list l
Position Advance(Position P, List L);

// obtain the element of position p [in list l]
ElementType Retrieve(Position P);

// additional method
// ...
void ListPrint(List L, void (*ElementPrint)(ElementType X));

// append element at the last of the list
void Append(ElementType X, List L);

// get the length of the list
int Length(List L);

#endif