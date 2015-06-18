#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int value = 5;

int main() {
    pid_t pid;
    pid = fork();
    
    if (pid == 0) { // child process
        value += 15; // just a completely copy
        printf("Child: value = %d\n", value);
    } else if (pid > 0) { // parent process
        wait(NULL);
        printf("Parent: value = %d\n", value); // 5
        exit(0);
    }
    return 0;
}