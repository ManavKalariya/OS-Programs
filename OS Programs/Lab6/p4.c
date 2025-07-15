#include <sys/types.h>
#include <sys/wait.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char* argv[]){
	int pipefd[2];
	int a=pipe(pipefd);
	char buf1[500];
	char buf2[500];
	
	if(argc>1){
		//printf("%s",argv[1]);
		if(a==-1){
			printf("Error creating pipe\n");
		}
		else{
			int c=fork();
			if(c>0){
				close(pipefd[0]);
				write(pipefd[1],argv[1],strlen(argv[1])); 
			}
			else{
				close(pipefd[1]);
				int n=read(pipefd[0],buf1,sizeof(buf1));
				//printf("%ld %s\n",sizeof(buf1),buf1);
				int fd=open(buf1,O_RDONLY);
				if(fd==-1){
					printf("Error opening file\n");
				}
				else{
					read(fd,buf2,sizeof(buf2));
					printf("%s",buf2);
				}
				
			}
		}
	}
	return 1;
}
