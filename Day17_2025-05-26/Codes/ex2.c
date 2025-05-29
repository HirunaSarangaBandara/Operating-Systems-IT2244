/*
First child : slept for 1 second.
Second child : slept for 3 seconds.
Parent : Both children have finished.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2;

    printf("Parent process started. PID: %d\n", getpid());

    pid1 = fork();

    if (pid1 < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid1 == 0) {
        // First child process
        printf("First child process. PID: %d, Sleeping for 1 second...\n", getpid());
        sleep(1);
        printf("First child process done sleeping.\n");
        exit(0);  // Important to exit child
    }
	
	wait(NULL);

    // Only parent reaches here
    pid2 = fork();

    if (pid2 < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid2 == 0) {
        // Second child process
        printf("Second child process. PID: %d, Sleeping for 3 seconds...\n", getpid());
        sleep(3);
        printf("Second child process done sleeping.\n");
        exit(0);  // Important to exit child
    }
	
	wait(NULL);

    // Parent process waits for both children
    //waitpid(pid1, NULL, 0);
    //waitpid(pid2, NULL, 0);

    printf("Both children have finished.\n");
    printf("Parent process ending.\n");

    return 0;
}
