#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int fibonacci_array[MAX_SIZE];
int kthFibonacci_array[MAX_SIZE];

int fibonacci(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
int fibonacciArray(int n) {
    fibonacci_array[0] = fibonacci_array[1] = 1;
    for (int i = 2; i <= n-1; i++) {
        fibonacci_array[i] = fibonacci_array[i-1] + fibonacci_array[i-2];
    }
    return fibonacci_array[n-1];
}

int kthFibonacci(int k, int n) {
    if (n <= k-2) {
        return 0;
    }else if (n == k-1) {
        return 1;
    }else {
        int sum = 0;
        for (int i = n-1 ; i >= n-k; i--) {
            sum += kthFibonacci(k, i);
        }
        return sum;
    }
}

int kthFibonacciArray(int k, int n) { //the start index is 0
    for (int i = 0; i <= k - 2; i++) {
        kthFibonacci_array[i] = 0;
    }
    kthFibonacci_array[k-1] = kthFibonacci_array[k] = 1;
    
    for (int i = k+1; i <= n; i++) {
        int temp = 0;
        for (int j = i-1; j >= i-k ; j--) {
            temp += kthFibonacci_array[j];
        }
        kthFibonacci_array[i] = temp;
    }
    return kthFibonacci_array[n];
}

int main(int argc, char *argv[]) {
    int n = 10;
    
    // fibonacci recursive
    for (int i = 1; i <= n; i++) {
        printf("%4d", fibonacci(i));
    }
    printf("\n");
    // fibnonacci loop
    for (int i = 1; i <= n; i++) {
        printf("%4d", fibonacciArray(i));
    }
    printf("\n");
    
    // Kth fibonacci loop
    for (int i = 1; i <= n; i++) {
        printf("%4d", kthFibonacciArray(2, i));
    }
    printf("\n");
    // Kth fibonacci recursive
    for (int i = 1; i <= n; i++) {
        printf("%4d", kthFibonacci(2, i));
    }
    printf("\n");
    
    return 0;
}