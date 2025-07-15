#include <sys/types.h>
#include <sys/wait.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

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
			wait(NULL);
			close(pipefd[1]);
			int n=read(pipefd[0],buf,sizeof(buf));
			//write(1,buf,n+1);
			printf("%s",buf);
			
		}
		else{
			close(pipefd[0]);
			write(pipefd[1],message,strlen(message)); 
		}
	}
	
}
