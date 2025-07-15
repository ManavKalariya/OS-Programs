#include <sys/types.h>
#include <sys/wait.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>

int main(int argc, char* argv[]){
	int pipefd[2];
	int a=pipe(pipefd);
	pid_t pid1,pid2;
	if(pipe(pipefd)==-1){
	    perror("pipe");
	    exit(EXIT_FAILURE);
	}
	if(pid1=fork()==-1){
	    perror("fork");
	    exit(EXIT_FAILURE);
	}
	if(pid1==0){
	        close(pipefd[0]);
	        dup2(pipefd[1],1);
	        close(pipefd[1]);
		printf("Hello from Child\n");
		execl("/bin/ls","ls",NULL);
	}
	else{
		wait(NULL);
		close(pipefd[1]);
		dup2(pipefd[0],1);
		close(pip
	  
		printf("Hello from Parent\n");
		execl("/bin/sort","sort",pipefd[0],NULL);
	}
	return 1;
}
