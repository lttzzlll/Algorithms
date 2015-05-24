#include "merge_sort_withoutRecursion.h"
#include <stdlib.h>
#include <stdio.h>

void base_sort(int *arr, int *additionalArray, int left, int middle, int right) {
    int i = left, j = middle + 1, cursor, pos;
    for (cursor = i; i <= middle && j <= right; cursor++) {
        if (arr[i] < arr[j]) {
            additionalArray[cursor] = arr[i++];
        }else {
            additionalArray[cursor] = arr[j++];
        }
    }
    if (i <= middle) {
        for (pos = 0; pos + i <= middle; pos++) {
            additionalArray[cursor + pos] = arr[i + pos];
        }
    }else {
        for (pos = 0; pos + j<= right; pos++) {
            additionalArray[cursor + pos] = arr[j + pos];
        }
    }
}

void Merge(int *arr, int *additionalArray, int scale, int length) {
    int i, j;
    for (i = 0; i + 2 * scale <= length; i += 2 * scale) {
        base_sort(arr, additionalArray, i, i + scale - 1, i + 2 * scale - 1);
    }
    if (i < length - scale + 1) {
        base_sort(arr, additionalArray, i, i + scale - 1, length - 1);
    }else {
        for (j = i; j < length; j++) {
            additionalArray[j] = arr[j];
        }
    }
    for (i = 0; i < length; i++) { // copy back from the additional array
        arr[i] = additionalArray[i];
    }
}

void MergeSort(int *arr, int length) {
    int *additionalArray = (int *)malloc(sizeof(int) * length);
    if (additionalArray == NULL) {
        exit(-1);
    }
    for (int scale = 1; scale < length; scale *= 2) {
        Merge(arr, additionalArray, scale, length);
    }
}

// public interface
void merge_sort(int *arr, int n) {
    MergeSort(arr, n);
}

// public interface
void sort(int *arr, int n) {
    merge_sort(arr, n);
}