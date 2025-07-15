#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(){
	printf("hello\n");
	const char* filepath="f1.txt";
	int oldfd=open(filepath,O_WRONLY);
	fflush(0);
	int newstdoutfd=dup2(oldfd,1);
	printf("%d\n",newstdoutfd);
	printf("hello");
}
