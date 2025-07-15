#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define FAN 4
int main(){
	//int c=fork();
	pid_t p=getpid();
	//pid_t pp=getppid();
	
	for(int i=0;i<FAN;i++){
		if(p==getpid()){
			int c=fork();
			if(c==0){
				printf("Hello Child %d\n",(i+1));
				printf("Child %d P_ID: %d\n",i+1,getpid());
				printf("Child %d Parent P_ID: %d\n",i+1,getppid());
			}
			else if(c>0){
				wait(NULL);
			}
			else{
				printf("Error Creating Child Process");
			}
		}
	}
	if(p==getpid()){
		printf("Hello Parent\n");	
		printf("Parent P_ID: %d\n",getpid());
		printf("Parent Parent P_ID: %d\n",getppid());
	}
}
