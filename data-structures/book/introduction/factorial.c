#include <stdio.h>
#include <assert.h>

#define MAXINT 2147483647
#define MAX_SIZE 10
int fact_array[MAX_SIZE];

int fact(int n) {
    assert(n < MAX_SIZE);
    fact_array[0] = 1;
    for (int i=1; i <= n; i++) {
        assert(2 * i * fact_array[i-1] <= MAXINT);
        fact_array[i] = 2 * i * fact_array[i-1];
    }
    return fact_array[n];
}

int main(int argc, char *argv[]) {
    int n = 10;
    for (int i=0; i<n; i++) {
        printf("%d  ", fact(i));
    }
    printf("\n");
    return 0;
}
