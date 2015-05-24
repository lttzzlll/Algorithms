#include "number.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
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
    return 0;
}