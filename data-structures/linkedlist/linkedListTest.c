#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

#define NOT_EXIST -1


// element print
void ElementPrint(ElementType X) {
    printf("%d\n", X);
}


int main(int argc, char *argv[]) {
    int arr[10], n = 10;
    
    for (int i=0; i < n; i++) {
        arr[i] = i;
    }
    
    List curList = IntegerListCreate();
    
    for (int i=0; i<n; i++) {
        Append(arr[i], curList);
    }
    
    ListPrint(curList, ElementPrint);
 
    printf("the list length is: %d\n", Length(curList));
    
    
    return 0; // the return code 0 means succeed!
}
