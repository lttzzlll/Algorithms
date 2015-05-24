#include "number.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateInteger(int *arr, int counts, int limitation) {
    srand((unsigned)time(NULL));
    for (int i = 0; i < counts; i++) {
        arr[i] = rand() % limitation;
    }
}

void generateUniqueInteger(int *arr, int counts, int limitation) {
    if (limitation < counts) {
        generateInteger(arr, counts, limitation);
    }else {
        srand((unsigned)time(NULL));
        for (int i=0; i<counts; i++) {
            for (int j;;) {
                arr[i] = rand() % limitation;
                for (j=0; j<i; j++) {
                    if (arr[j] == arr[i]) {
                        break;
                    }
                }
                if (j == i) {
                    break;
                }
            }
        }
    }
}

void integerArraySnippetPrint(int *arr, int left, int right) {
    for (int i = left; i<= right; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void integerArrayPrint(int *arr, int n) {
    integerArraySnippetPrint(arr, 0, n-1);
}


void integerArrayCopyFrom(int *src, int *des, int n) {
    for (int i=0; i<n; i++) {
        des[i] = src[i];
    }
}

int integerArrayCompare(int *lhs, int *rhs, int n) {
    for (int i=0; i<n; i++) {
        if (lhs[i] != rhs[i]) {
            return -1;
        }
    }
    return 0;
}

int integerCompare(const void *a, const void *b) {
    return *(int *)a  - *(int *)b;
}