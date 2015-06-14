#include "../../../../utility/number/number.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define MAXSIZE 100

typedef int ElemType;

typedef struct {
    ElemType data;
    int cur;
}component, SLinkList[MAXSIZE];


int LocateElem_SL(SLinkList S, ElemType e) {
    int i  = S[0].cur;
    while (i && S[i].data != e) {
        i = S[i].cur;
    }
    return i;
}

void InitSpace_SL(SLinkList space) {
    int i;
    for (i = 0; i < MAXSIZE - 1; ++i) {
        space[i].cur = i + 1;
    }
    space[i].cur = 0;
}


int Malloc_SL(SLinkList space) {
    int i = space[0].cur;
    if (space[0].cur) {
        space[0].cur = space[i].cur;
    }
    return i;
}


void Free_SL(SLinkList space, int k) {
    space[k].cur = space[k].cur;
    space[k].cur = k;
}


void difference(SLinkList space, int *S) {
    int i, j, k, m, n, r, p;
    ElemType b;
    
    InitSpace_SL(space);
    *S = Malloc_SL(space); // printf("*S=%d\n", *S);
    r = *S;
    
    scanf("%d %d", &m, &n);
    
    for (j = 1; j <= m; ++j) {
        i = Malloc_SL(space); // printf("i=%d\n", i);
        scanf("%d", (int *) (&space[i].data)); // printf("scanf=%d\n", space[i].data);
        space[r].cur = i;
        r = i;
    }
    
    space[r].cur = 0; // end
    
    for (j = 1 ; j <= n; ++j) {
        scanf("%d", (int *)&b); // printf("scanf=%d\n", b);
        p = *S;
        k = space[*S].cur;
        while (k != space[r].cur && space[k].data != b) {
            p = k;
            k = space[k].cur;
        }
        if (k == space[r].cur) { // no repeated, append it
            i = Malloc_SL(space);
            space[i].data = b;
            space[i].cur = space[r].cur;
            space[r].cur = i;
        } else {
            space[p].cur = space[k].cur; // repeated, delete it
            Free_SL(space, k);
            if (r == k) { // k is the last one
                r = p; // change r to p
            }
        }
    }
}


// test block
int main(int argc, char *argv[]) {
    // declaration
//    int array[MAXSIZE];
    SLinkList sl;

// all passed!
//    for (int i = 0; i < MAXSIZE; i++) {
//        array[i] = i;
//    }
//    // size
//    printf("sl size: %lu\n", sizeof(sl));
//    
//    // init
    InitSpace_SL(sl);
//
//    for (int i = 0; i < MAXSIZE; ++i) {
//        printf("sl[%d].cur = %d\n", i, sl[i].cur);
//    }
//    
    
//    
//    // set
//    for (int i = 0; i < MAXSIZE; ++i) {
//        sl[i].data = (ElemType)(i * i);
//    }
//    
//    for (int i = 0; i < MAXSIZE; ++i) {
//        printf("position %d is %d\n", i, (int)(sl[i].data));
//    }
//    
//    // get element
//    for (int i = 0; i < MAXSIZE; ++i) {
//        printf("%d at position %d\n", (int)(sl[i].data), LocateElem_SL(sl, (int)(sl[i].data)));
//    }
 
    
    
//    printf("**************************\n");
  
    int S = 0; // init

    // difference
    difference(sl, &S);
//    3 3
//    4 5 6
//    5 6 7
//    S = 2, data = 4
//    S = 5, data = 7
    for (S = sl[S].cur; S != 0; S = sl[S].cur) {
        printf("S = %d, data = %d\n", S, (int)(sl[S].data));
    }

    return 0;
}