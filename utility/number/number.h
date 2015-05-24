#ifndef __NUMBER_H__
#define __NUMBER_H__

// randomly generate integers
void generateInteger(int *arr, int counts, int limitation);

// randomly generate unique integers
void generateUniqueInteger(int *arr, int counts, int limitation);

// print snippet array
void integerArraySnippetPrint(int *arr, int left, int right);

// print the array
void integerArrayPrint(int *arr, int n);

// copy from another array
void integerArrayCopyFrom(int *src, int *des, int n);

// integer array compare
int integerArrayCompare(int *lhs, int *rhs, int n);

// compare function of integer
int integerCompare(const void *a, const void *b);

#endif