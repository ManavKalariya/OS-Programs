#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define CHAIN 4
int main(){
	//int c=fork();
	pid_t p=getpid();
	pid_t pp=getppid();
	printf("Hello Parent\n");	
	printf("Parent P_ID: %d\n",getpid());
	printf("Parent Parent P_ID: %d\n",getppid());
	for(int i=0;i<CHAIN;i++){
		if(p==getpid()){
			int c=fork();
			if(c==0){
				p=getpid();
				printf("Hello Child %d\n",(i+1));
				printf("Child %d P_ID: %d\n",i+1,getpid());
				printf("Child %d Parent P_ID: %d\n",i+1,getppid());
			}
			else if(c>0){
				p=-122;
				wait(NULL);
			}
			else{
				printf("Error Creating Child Process");
			}
			
		}
	}
}
