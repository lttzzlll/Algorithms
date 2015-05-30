#include <stdio.h>

#define MAX_SIZE 100

double polynomail_array[MAX_SIZE];
double factorial_array[MAX_SIZE];

void fact(double x, int factorial) {
    factorial_array[0] = 1;
    for (int i = 1; i <= factorial; i++) {
        factorial_array[i] = factorial_array[i-1] * x;
    }
}

double polynomailArray(int *para, int factorial, double x, int n) {
    fact(x, n);
    polynomail_array[0] = factorial_array[0];
    for (int i = 1; i <= n; i++) {
        polynomail_array[i] += polynomail_array[i-1] + factorial_array[i] * para[i];
    }
    return polynomail_array[n];
}

double polynomail(int *para, int factorial, double x, int n) {
    if (factorial > 0) {
        return para[n-factorial] + polynomail(para, factorial-1, x, n) * x;
    }else {
        return para[n];
    }
}

int main(int argc, char *argv[]) {
    int n = 10;
    int parameters[MAX_SIZE];
    double x = 2;
 
    // set parameters
    for (int i = 0; i < MAX_SIZE; i++) {
        parameters[i] = 1;
    }
    
    //  each factorial
    for (int factorial = 0; factorial <= n; factorial++) {
        printf("%.lf  ", polynomail(parameters, factorial , x, n));
    }
    printf("\n");
    
    polynomailArray(parameters, n, x, n);
    
    for (int i=0; i <= n; i++) {
        printf("%.lf  ", polynomail_array[i]);
    }
    printf("\n");
    
    return 0;
}