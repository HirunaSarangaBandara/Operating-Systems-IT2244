#include<stdio.h>
#include<stdlib.h> // for exit()
#include<unistd.h> // for fork(), sleep()
#include<sys/wait.h> //for wait()

int main(){
	pid_t pid;
	
	printf("Parent process started. PID : %d\n", getpid());
	
	pid = fork();
	
	if(pid < 0){
		perror("fork failed");
		exit(1);
	}
	
	if(pid == 0){
		//Child process
		printf("Child process. PID : %d, Sleeping for 2 seconds...\n", getpid());
		sleep(2); 
		printf("Child process exiting.\n");
		exit(0); //Child exits with status 0 -> Successfully terminated
	}
	else{
		//Parent process
		int status;
		printf("Parent waiting for child to finish...\n");
		wait(&status); // Wait for child to finish
		
		if(WIFEXITED(status)){
			printf("Child exited with status : %d\n", WEXITSTATUS(status));
		}
		else{
			printf("Child did not exit normally.\n");
		}
		printf("Parent process ending.\n");
	}

	return 0;
}
