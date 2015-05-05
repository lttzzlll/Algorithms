#include "test/test.h"
#include "quick_sort/quick_sort.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int n;
    int limitation;

	if (argc == 1) {
		n = 10;
		limitation = 100;
	}else if (argc == 2) {
        n = atoi(argv[1]);
    }else if (argc == 3) {
        n = atoi(argv[1]);
        limitation = atoi(argv[2]);
    }else {
        printf("argc == %d, input invalid args too much!\n", argc);
    }
    
    test(n, limitation, sort);
    
    return 0;
}
