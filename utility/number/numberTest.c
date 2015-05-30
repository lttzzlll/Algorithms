#include "number.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    
    // the sort code test block
    int n = 100, limitation = 100;
    int *arr = (int *)malloc(sizeof(int) * n);
    if (arr == NULL) {
        printf("allocate memory error!");
        exit(-1);
    }
    generateUniqueInteger(arr, n, limitation);
    integerArrayPrint(arr, n);
    qsort(arr, n, sizeof(int), integerCompare);
    integerArrayPrint(arr, n);
    
    // the swap code test block
    int a = 1, b = 2;
    float c = 1, d = 2;
    double e = 1, f = 2;
    swap2Ints(&a, &b);
    printf("a=%d, b=%d\n", a, b);
    swap2Floats(&c, &d);
    printf("c=%f, d=%f\n", c, d);
    swap2Doubles(&e, &f);
    printf("e=%lf, f=%lf\n", e, f);
    
    return 0;
}