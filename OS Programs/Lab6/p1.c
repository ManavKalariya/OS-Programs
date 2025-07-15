#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	int pipefd[2];
	int a=pipe(pipefd);
	printf("write end fd: %d\nread end fd: %d\n",pipefd[1],pipefd[0]);
	pipe(pipefd);
	printf("write end fd: %d\nread end fd: %d\n",pipefd[1],pipefd[0]);
}

