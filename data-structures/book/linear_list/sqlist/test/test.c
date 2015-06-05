#include "../../../../../utility/number/number.h"
#include "../../../../../utility/type/type.h"
#include "../list/list.h"
#include <stdio.h>

#define SIZE 1000

int array[SIZE];
int array_another[SIZE]; // copy for the list [merge, union] operation

// sqeuece list visit
Status ListVisit(ElemType e) {
    printf("%d  ", (int)e);
    return OK;
}

//sequence list compare
Bool ListCompare(ElemType e1, ElemType e2) {
    if (e1 == e2) {
        return True;
    }else {
        return False;
    }
}

// traverse a list and print each element if it can
void ListTraversePrint(List *L, Status (*visit)(ElemType e)) {
    ListTraverse(L, visit);
    printf("\n");
}

int main(int argc, char *argv[]) {
    // init
    //
    //
    int n = 100; // the number of element
    int limitation = 100; // the up boundary of the element
    
    // array assignment
    //
    //
    for (int i=0; i < n; i++) { // assignment for array
        array[i] = (i + 1) * 2; // even
    }
    
    for (int i=0; i < n; i++) { // assignment for array // copy
        array_another[i] = i * 2 + 1; // odd // copy for the list [merge, union] operation
    }
    
    
//    generateInteger(array , n, limitation);
//    test(n, limitation, sort);
    // integerArratPrint
    //
    //
    integerArrayPrint(array, n); // print the integer array
    
    integerArrayPrint(array_another, n); // copy for the list [merge, union] operation
    
    // List Declaration
    //
    //
    List list;
    List list_other; // copy for the list [merge, union] operation
    List list_another; // copy for the list [merge, union] operation
    
    // InitList
    //
    //
    InitList(&list); // @1 initilize the sequence list
    
    InitList(&list_other); // copy for the list [merge, union] operation

    InitList(&list_another); // copy for the list [merge, union] operation
    
    // ListEmpty
    //
    //
    if (ListEmpty(&list)) { // judge if the sequence list is empty
        printf("list is empty\n");
    }else {
        printf("list is not empty\n");
    }
    
    if (ListEmpty(&list_other)) { // judge if the sequence list is empty
        printf("list other is empty\n");
    }else {
        printf("list other is not empty\n");
    }
    
    if (ListEmpty(&list_another)) { // judge if the sequence list is empty
        printf("list another is empty\n");
    }else {
        printf("list another is not empty\n");
    }
    
    // ListLength
    //
    //
    printf("list length: %d\n", ListLength(&list)); // get the list length
    printf("list other length: %d\n", ListLength(&list_other)); // get the list length
    printf("list anoter length: %d\n", ListLength(&list_another)); // get the list length
    
    // ListInsert
    //
    //
    for (int i=0; i < n; i++) { // insert each element into the list
        ListInsert(&list, ListLength(&list)+1, (ElemType)array[i]);
    }
  
    // list other
    for (int i=0; i < n; i++) { // insert each element into the list
        ListInsert(&list_other, ListLength(&list_other)+1, (ElemType)array_another[i]);
    }
    
    
    // ListLength
    //
    //
    printf("list length: %d\n", ListLength(&list)); // get the list length
   
    printf("list other length: %d\n", ListLength(&list_other)); // get the list length
    
    // ListTraversePrint
    // ListTraverse
    // ListVisit
    ListTraversePrint(&list, ListVisit); // traverse the list and print each elemnt
    
    ListTraversePrint(&list_other, ListVisit);
    
    
    // MergeList
    //
    //
    MergeList(&list, &list_other, &list_another);
    // ListLength
    //
    //
    printf("list another length: %d\n", ListLength(&list_another)); // get the list length
   
    
    // ListTraversePrint
    // ListTraverse
    // ListVist
    ListTraversePrint(&list_another, ListVisit);
    
    // GetElem
    // PriorElem
    // NextElem
    ElemType e, cur_e, pre_e, next_e;    
    for (int i = 1; i <= n; i++) {
        if (GetElem(&list, i, &cur_e) == OK) { // obtain the element at the position of i in the list
            if (PriorElem(&list, cur_e, &pre_e, ListCompare) == OK) { // get the previous element of the current element if it exist in the list
                printf("%d element is %d, the previous element is %d\n", i, (int)cur_e, (int)pre_e);
            }else {
                printf("%d element is %d, did not has a previous element\n", i, (int)cur_e);
            }
        }else {
            printf("access %d element failed\n", i);
        }
    }
    
    for (int i=1; i <=n; i++) {
        if (GetElem(&list, i, &cur_e) == OK) {
            if (NextElem(&list, cur_e, &next_e, ListCompare) == OK) { //obtain the next elemnt of the current element if it exist
                printf("%d element is %d, the next element is %d\n", i, (int)cur_e, (int)next_e);
            }else {
                printf("%d element is %d, did not has a next element\n", i, (int)cur_e);
            }
        }else {
            printf("access %d element failed\n", i);
        }
    }
    
    
    // ListDelte
    //
    //
    for (int i=1; i <= n; i++) {
        if (ListDelete(&list, 1, &cur_e) == OK) {
            ListTraversePrint(&list, ListVisit);
            printf("list length is %d\n", ListLength(&list));
        }else {
            printf("delete position %d element failed\n", i);
        }
    }
//
//    for (int i=1; i <= n; i++) {
//        if (ListDelete(&list, ListLength(&list), &cur_e) == OK) {
//            ListTraversePrint(&list, ListVisit);
//            printf("list length is %d\n", ListLength(&list));
//        }else {
//            printf("delete position %d element failed\n", i);
//        }
//    }
    
//    for (int i=1; i <= n; i++) {
//        if (ListDelete(&list, i, &cur_e) == OK) {
//            ListTraversePrint(&list, ListVisit);
//            printf("list length is %d\n", ListLength(&list));
//        }else {
//            printf("delete position %d element failed\n", i);
//        }
//    }

    
    // ListEmpty
    //
    //
    if (ListEmpty(&list)) {
        printf("list is empty\n");
    }else {
        printf("list is not empty\n");
    }
    
    // ClearList
    //
    //
    ClearList(&list); // clear the list
    
    // ListEmpty
    //
    //
    if (ListEmpty(&list)) {
        printf("list is empty\n");
    }else {
        printf("list is not empty\n");
    }
    
    printf("list length is %d\n", ListLength(&list));
 
    // DestoryList
    //
    //
    DestoryList(&list); // destory the list
    
    DestoryList(&list_other);
    
    DestoryList(&list_another);
 
    
    return 0;
}