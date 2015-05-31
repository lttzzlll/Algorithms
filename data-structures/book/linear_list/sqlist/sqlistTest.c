#include "../../../../utility/number/number.h"
#include "../../../../utility/type/type.h"
//#include "../../../sort/test/test.h"
//#include "../../introduction/bubble_sort/bubble_sort.h"
#include "sqlist.h"
#include <stdio.h>

#define SIZE 1000

int array[SIZE];
int array_another[SIZE]; // copy for the list [merge, union] operation

// sqeuece list visit
Status ListVisit_Sq(ElemType e) {
    printf("%d  ", (int)e);
    return OK;
}

//sequence list compare
Bool ListCompare_Sq(ElemType e1, ElemType e2) {
    if (e1 == e2) {
        return True;
    }else {
        return False;
    }
}

// traverse a list and print each element if it can
void ListTraversePrint_Sq(Sqlist *L, Status (*visit)(ElemType e)) {
    ListTraverse_Sq(L, visit);
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
    Sqlist list;
    Sqlist list_other; // copy for the list [merge, union] operation
    Sqlist list_another; // copy for the list [merge, union] operation
    
    // InitList
    //
    //
    InitList_Sq(&list); // @1 initilize the sequence list
    
    InitList_Sq(&list_other); // copy for the list [merge, union] operation

    InitList_Sq(&list_another); // copy for the list [merge, union] operation
    
    // ListEmpty
    //
    //
    if (ListEmpty_Sq(&list)) { // judge if the sequence list is empty
        printf("list is empty\n");
    }else {
        printf("list is not empty\n");
    }
    
    if (ListEmpty_Sq(&list_other)) { // judge if the sequence list is empty
        printf("list other is empty\n");
    }else {
        printf("list other is not empty\n");
    }
    
    if (ListEmpty_Sq(&list_another)) { // judge if the sequence list is empty
        printf("list another is empty\n");
    }else {
        printf("list another is not empty\n");
    }
    
    // ListLength
    //
    //
    printf("list length: %d\n", ListLength_Sq(&list)); // get the list length
    printf("list other length: %d\n", ListLength_Sq(&list_other)); // get the list length
    printf("list anoter length: %d\n", ListLength_Sq(&list_another)); // get the list length
    
    // ListInsert
    //
    //
    for (int i=0; i < n; i++) { // insert each element into the list
        ListInsert_Sq(&list, ListLength_Sq(&list)+1, (ElemType)array[i]);
    }
  
    // list other
    for (int i=0; i < n; i++) { // insert each element into the list
        ListInsert_Sq(&list_other, ListLength_Sq(&list_other)+1, (ElemType)array_another[i]);
    }
    
    
    // ListLength
    //
    //
    printf("list length: %d\n", ListLength_Sq(&list)); // get the list length
   
    printf("list other length: %d\n", ListLength_Sq(&list_other)); // get the list length
    
    // ListTraversePrint
    // ListTraverse
    // ListVisit
    ListTraversePrint_Sq(&list, ListVisit_Sq); // traverse the list and print each elemnt
    
    ListTraversePrint_Sq(&list_other, ListVisit_Sq);
    
    
    // MergeList
    //
    //
    MergeList_Sq(&list, &list_other, &list_another);
    // ListLength
    //
    //
    printf("list another length: %d\n", ListLength_Sq(&list_another)); // get the list length
   
    
    // ListTraversePrint
    // ListTraverse
    // ListVist
    ListTraversePrint_Sq(&list_another, ListVisit_Sq);
    
    // GetElem
    // PriorElem
    // NextElem
    ElemType e, cur_e, pre_e, next_e;    
    for (int i = 1; i <= n; i++) {
        if (GetElem_Sq(&list, i, &cur_e) == OK) { // obtain the element at the position of i in the list
            if (PriorElem_Sq(&list, cur_e, &pre_e, ListCompare_Sq) == OK) { // get the previous element of the current element if it exist in the list
                printf("%d element is %d, the previous element is %d\n", i, (int)cur_e, (int)pre_e);
            }else {
                printf("%d element is %d, did not has a previous element\n", i, (int)cur_e);
            }
        }else {
            printf("access %d element failed\n", i);
        }
    }
    
    for (int i=1; i <=n; i++) {
        if (GetElem_Sq(&list, i, &cur_e) == OK) {
            if (NextElem_Sq(&list, cur_e, &next_e, ListCompare_Sq) == OK) { //obtain the next elemnt of the current element if it exist
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
        if (ListDelete_Sq(&list, 1, &cur_e) == OK) {
            ListTraversePrint_Sq(&list, ListVisit_Sq);
            printf("list length is %d\n", ListLength_Sq(&list));
        }else {
            printf("delete position %d element failed\n", i);
        }
    }
//
//    for (int i=1; i <= n; i++) {
//        if (ListDelete_Sq(&list, ListLength_Sq(&list), &cur_e) == OK) {
//            ListTraversePrint_Sq(&list, ListVisit_Sq);
//            printf("list length is %d\n", ListLength_Sq(&list));
//        }else {
//            printf("delete position %d element failed\n", i);
//        }
//    }
    
//    for (int i=1; i <= n; i++) {
//        if (ListDelete_Sq(&list, i, &cur_e) == OK) {
//            ListTraversePrint_Sq(&list, ListVisit_Sq);
//            printf("list length is %d\n", ListLength_Sq(&list));
//        }else {
//            printf("delete position %d element failed\n", i);
//        }
//    }

    
    // ListEmpty
    //
    //
    if (ListEmpty_Sq(&list)) {
        printf("list is empty\n");
    }else {
        printf("list is not empty\n");
    }
    
    // ClearList
    //
    //
    ClearList_Sq(&list); // clear the list
    
    // ListEmpty
    //
    //
    if (ListEmpty_Sq(&list)) {
        printf("list is empty\n");
    }else {
        printf("list is not empty\n");
    }
    
    printf("list length is %d\n", ListLength_Sq(&list));
 
    // DestoryList
    //
    //
    DestoryList_Sq(&list); // destory the list
    
    DestoryList_Sq(&list_other);
    
    DestoryList_Sq(&list_another);
 
    
    return 0;
}