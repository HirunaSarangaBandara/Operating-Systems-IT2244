/*
Exercise 02:
First child : slept for 2 seconds, exits with status 2.
Second child : slept for 1 second, exits with status 1.
Parent : Wait twice, and prints which child (by PID or exit code)
finished first and second.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2;
    int status1, status2;
    pid_t finished_pid;
    int finished_status;

    printf("Parent started. PID: %d\n", getpid());

    pid1 = fork();
    if (pid1 < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid1 == 0) {
        // First child: sleep 2 seconds, exit with status 2
		printf("First child sleeping for 2 seconds...\n");
        sleep(2);
        exit(2);
    }

    // Parent forks second child
    pid2 = fork();
    if (pid2 < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid2 == 0) {
        // Second child: sleep 1 second, exit with status 1
		printf("Second child sleeping for 1 second...\n");
        sleep(1);
        exit(1);
    }

    // Parent waits twice, recording order
    pid_t first_finished = wait(&status1);
    pid_t second_finished = wait(&status2);

    // Helper function to get exit code from status
    int exit_code1 = WIFEXITED(status1) ? WEXITSTATUS(status1) : -1;
    int exit_code2 = WIFEXITED(status2) ? WEXITSTATUS(status2) : -1;

    printf("Child with PID %d finished first with exit status %d.\n", first_finished, exit_code1);
    printf("Child with PID %d finished second with exit status %d.\n", second_finished, exit_code2);

    printf("Parent ending.\n");

    return 0;
}
