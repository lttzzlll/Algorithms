#include "type.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateInteger(int boundary) {
    srand((unsigned)time(NULL));
    return rand() % boundary;
}
int main(int argc, char *argv[]) {
    enum Bool flag;
    int boundary = 10;
    int result = generateInteger(boundary);
    if (result > 5) {
        flag = True;
    }else {
        flag = False;
    }
    printf("result is %d, flag is %d\n", result, flag);
    
    return 0;
}