#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
int main(){
	printf("Before Child\n");
	//fflush(0);//to execute the command above printf command, the contents of buffer will be printed onto console
	int c=fork();
	if(c==0){
		printf("Hello from Child\n");
		execl("/bin/pwd","pwd",NULL);
	}
	else{
		wait(NULL);
		printf("Hello from Parent\n");
		execl("/bin/ls","ls",NULL);
	}
	printf("After Exec");
}
