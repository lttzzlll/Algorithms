#include "bubble_sort.h"
#include "../../../../utility/number/number.h"
#include "../../../../utility/type/type.h"
//
//typedef enum {
//    FALSE,
//    TRUE
//} Bool;


// bubble sort the pretty simple version
void bubble_sort(int *arr, int n) {
    Bool change;
    for (int i = n-1, change = True; i >= 0 && change; i--) {
        change = False; // change is a flag if it still need to sort
        for (int j=0; j<i; j++) {
            if (arr[j] > arr[j+1]) {
                swap2Ints(&arr[j], &arr[j+1]);
                change = True;
            }
        }
    }
}

void sort(int *arr, int n) {
    bubble_sort(arr, n);
}