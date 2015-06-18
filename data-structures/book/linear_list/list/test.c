#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int compare(ElemType a, ElemType b) {
    return a - b;
}

Status visit(ElemType e) {
    printf("%d\n", (int)e);
    return OK;
}

int main(int argc, char *argv[]) {
    // declaration
    LinkList la, lb, lc;
    Link s;
    int n = 10;
    
    // init list
    InitList(&la);
    InitList(&lb);
    InitList(&lc);
    
    // list lenght
    printf("list la length: %d\n", ListLength(&la));
    printf("list lb length: %d\n", ListLength(&lb));
    printf("list lc length: %d\n", ListLength(&lc));
    
    // list empty
    if (ListEmpty(&la)) {
        printf("list la is empty\n");
    } else {
        printf("list la length: %d\n", ListLength(&la));
    }
    if (ListEmpty(&lb)) {
        printf("list lb is empty\n");
    } else {
        printf("list lb length: %d\n", ListLength(&lb));
    }
    if (ListEmpty(&lc)) {
        printf("list lc is empty\n");
    } else {
        printf("list lc length: %d\n", ListLength(&lc));
    }
    
    // head and tail
    if (la.head == NULL && la.tail == NULL) {
        printf("la head and tail is null\n");
    } else {
        printf("la head nor tail is not null\n");
    }
    if (lb.head == NULL && lb.tail == NULL) {
        printf("lb head and tail is null\n");
    } else {
        printf("lb head nor tail is not null\n");
    }
    if (lc.head == NULL && lc.tail == NULL) {
        printf("lc head and tail is null\n");
    } else {
        printf("lc head nor tail is not null\n");
    }
    
    
    //print
    printf("*******\n*******\n*******\n");
    
    // insert into list
    for (int i = 1; i <= n; i++) {
        if (MakeNode(&s, (ElemType)(i * 2 + 1))) {
            Append(&la, &s);
            printf("list la length: %d\n", ListLength(&la));
            ListTraverse(&la, visit);
        } else {
            printf("%d times, make node failed\n", i);
        }
    }
 
    //print
    printf("*******\n*******\n*******\n");
    
    
    // list traverse
//    ListTraverse(&la, visit);
    printf("\n\n\n");
    
    
    for (int i = 1; i <= n; i++) {
        if (MakeNode(&s, (ElemType)(i * 2))) {
            Append(&lb, &s);
            printf("list lb length: %d\n", ListLength(&lb));
            ListTraverse(&lb, visit);
        } else {
            printf("%d times, make node failed\n", i);
        }
    }
    // list traverse
//    ListTraverse(&lb, visit);
    printf("\n\n\n");
    
    
    
    //print
    printf("*******\n*******\n*******\n\n\nMergeList\n");
    
    
    // merge list
    if (MergeList(&la, &lb, &lc, compare)) {
        printf("merge list succeed!\n");
        
        // list length
        printf("list lc length is %d\n", ListLength(&lc));
        
        // list traverse
        ListTraverse(&lc, visit);
    } else {
        printf("merge failed\n");
    }
    
    
    // clear list
    ClearList(&la);
    ClearList(&lb);
    ClearList(&lc);
    
    DestoryList(&la);
    DestoryList(&lb);
    DestoryList(&lc);
    
    return 0;
}