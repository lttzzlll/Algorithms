#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid;
    pid = fork();
    
    if (pid < 0) { // fork failed
        fprintf(stderr, "Fork Failed\n");
        exit(-1);
    } else if(pid == 0) { // child process
        execlp("/bin/ls", "ls", NULL);
    } else { // parent process
        wait(NULL);
        printf("Child process Complete!\n");
        exit(0);
    }
}