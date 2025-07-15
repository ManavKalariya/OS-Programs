#include <sys/types.h>
#include <sys/wait.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
//Below is working properly
/*
int main(){
	int pipefd[2];
	int a=pipe(pipefd);
	if(a==-1){
		printf("Error creating pipe");
		
	}
	else{
		int c=fork();
		if(c>0){
			close(pipefd[0]);
			write(pipefd[1],"hello",6); 
		}
		else{
			char buf[50];
			close(pipefd[1]);
			int n=read(pipefd[0],buf,5);
			//write(1,buf,n+1);
			printf("%s",buf);
		}
	}
	
}
*/

int main(){
	int pipefd[2];
	int a=pipe(pipefd);
	char* message="hello";
	char buf[50];
	if(a==-1){
		printf("Error creating pipe");
		
	}
	
	else{
		int c=fork();
		if(c>0){
			close(pipefd[0]);
			write(pipefd[1],message,strlen(message)); 
		}
		else{
			close(pipefd[1]);
			int n=read(pipefd[0],buf,sizeof(buf));
			//write(1,buf,n+1);
			printf("%s",buf);
		}
	}
	
}
