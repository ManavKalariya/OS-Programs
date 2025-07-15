#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>

int main(){
	printf("Before Exec\n");
	//fflush(0);//to execute the command above printf command, the contents of buffer will be printed onto console
	execl("/bin/ls","ls",NULL);
	printf("After Exec");
}
