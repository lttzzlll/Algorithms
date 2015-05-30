#include "../../../sort/test/test.h"
#include "bubble_sort.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int n = 10;
    int limitation = 100;
    if (argc == 2) {
        n = atoi(argv[1]);
    }else if (argc == 3) {
        n = atoi(argv[1]);
        limitation = atoi(argv[2]);
    }else {
        printf("input invalid args too much!\n");
    }
    
    test(n, limitation, sort);
    
    return 0;
}
