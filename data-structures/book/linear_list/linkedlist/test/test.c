#include "../../../../../utility/number/number.h"
#include "../../../../../utility/type/type.h"
#include "../list/list.h"
#include <stdio.h>
#include <assert.h>



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
    
    
    // integerArratPrint
    //
    //
//    printf("the first integer array display\n");
    integerArrayPrint(array, n); // print the integer array
    
//    printf("the second integer array display\n");
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
//    printf("check whether the list is empty\n");
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
//    printf("get the list length\n");
    printf("the first list length: %d\n", ListLength(&list)); // get the list length
    printf("the second list other length: %d\n", ListLength(&list_other)); // get the list length
    printf("the third list anoter length: %d\n", ListLength(&list_another)); // get the list length
    
    // ListInsert
    //
    //
//    printf("insert element into the list one\n")
    for (int i=0; i < n; i++) { // insert each element into the list
        ListInsert(&list, ListLength(&list)+1, (ElemType)array[i]);
    }
  
//    printf("insert element into the other list\n");
    // list other
    for (int i=0; i < n; i++) { // insert each element into the list
        ListInsert(&list_other, ListLength(&list_other)+1, (ElemType)array_another[i]);
    }
    
    
    // ListLength
    //
    //
    printf("the first list length: %d\n", ListLength(&list)); // get the list length
    printf("the second list other length: %d\n", ListLength(&list_other)); // get the list length
    
    // ListTraversePrint
    // ListTraverse
    // ListVisit
    
    // list tarverse print
//    printf("list traverse print the first\n");
    ListTraversePrint(&list, ListVisit); // traverse the list and print each elemnt
    
    // list traverse print
//    printf("list traverse print the second\n");
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
    int length = ListLength(&list_another);
    for (int i = 1; i <= length; i++) {
        if (GetElem(&list_another, i, &cur_e) == OK) { // obtain the element at the position of i in the list
            if (PriorElem(&list_another, cur_e, &pre_e, ListCompare) == OK) { // get the previous element of the current element if it exist in the list
                printf("%d element is %d, the previous element is %d\n", i, (int)cur_e, (int)pre_e);
            }else {
                printf("%d element is %d, did not has a previous element\n", i, (int)cur_e);
            }
        }else {
            printf("access %d element failed\n", i);
        }
    }
    
    for (int i=1; i <=length; i++) {
        if (GetElem(&list_another, i, &cur_e) == OK) {
            if (NextElem(&list_another, cur_e, &next_e, ListCompare) == OK) { //obtain the next elemnt of the current element if it exist
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
    for (int i=1; i <= length; i++) {
        if (ListDelete(&list_another, 1, &cur_e) == OK) {
            ListTraversePrint(&list_another, ListVisit);
            printf("list length is %d\n", ListLength(&list_another));
        }else {
            printf("delete position %d element failed\n", i);
        }
    }
//
//    for (int i=1; i <= length; i++) {
//        if (ListDelete(&list_another, ListLength(&list_another), &cur_e) == OK) {
//            ListTraversePrint(&list_another, ListVisit);
//            printf("list length is %d\n", ListLength(&list_another));
//        }else {
//            printf("delete position %d element failed\n", i);
//        }
//    }
    
//    for (int i=1; i <= length; i++) {
//        if (ListDelete(&list_another, i, &cur_e) == OK) {
//            ListTraversePrint(&list_another, ListVisit);
//            printf("list length is %d\n", ListLength(&list_another));
//        }else {
//            printf("delete position %d element failed\n", i);
//        }
//    }

    
    // ListEmpty
    //
    //
    if (ListEmpty(&list_another)) {
        printf("list is empty\n");
    }else {
        printf("list is not empty\n");
    }
    
    // ClearList
    //
    //
    ClearList(&list_another); // clear the list
    
    
    // ListEmpty
    //
    //
//    assert(list != NULL);
    if (list != NULL) {
        if (ListEmpty(&list)) {
            printf("the first list is empty\n");
        }else {
            printf("the first list is not empty\n");
        }
    
        printf("the first list length: %d\n", ListLength(&list));
        
        
        // Destory List
        //
        //
        assert(list != NULL);
        if (DestoryList(&list) == OK) {
            printf("delete the first list\n");
        } else {
            printf("delete the first list failed\n");
        }
    }
    
    // ListEmpty
    //
    //
//    assert(list_other != NULL);
//    printf("%d\n", ListLength(&list_other));
    if (list_other != NULL) {
        if (ListEmpty(&list_other)) {
        printf("the second list is empty\n");
        }else {
            printf("the second list is not empty\n");
        }
        
        printf("the second list length: %d\n", ListLength(&list_other));
        
        
        // Destory List
        //
        //
        assert(list_other != NULL);
        if (DestoryList(&list_other) == OK) {
            printf("delete the first list\n");
        } else {
            printf("delete the first list failed\n");
        }
    }
    
    // ListEmpty
    //
    //
//    assert(list_another != NULL);
    if (list_another != NULL) {
        if (ListEmpty(&list_another)) {
            printf("the third list is empty\n");
        }else {
            printf("the third list is not empty\n");
        }
    
        printf("the third list length: %d\n", ListLength(&list_another));
        
        
        // Destory List
        //
        //
        assert(list_another != NULL);
        
        if (DestoryList(&list_another) == OK) {
            printf("delete the first list\n");
        } else {
            printf("delete the first list failed\n");
        }
    }
    
    
    // DestoryList
    //
//    //
//    assert(list != NULL);
//    if (list != NULL) {
///        DestoryList(&list); // destory the list
//    }
//    
////    assert(list_other != NULL);
//    if (list_other != NULL) {
//        DestoryList(&list_other);
//    }
//    
//    assert(list_another != NULL);
//    if (list_another != NULL) {
//        DestoryList(&list_another);
//    }
    
    return 0;
}