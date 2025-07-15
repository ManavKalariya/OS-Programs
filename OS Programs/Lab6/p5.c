#include <sys/types.h>
#include <sys/wait.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char* argv[]){
	int pipefd1[2],pipefd2[2];
	int a=pipe(pipefd1);
	int b=pipe(pipefd2);
	char buf1[500];
	char buf2[500];
	char buf3[500];
	if(argc>1){
		//printf("%s",argv[1]);
		if(a==-1){
			printf("Error creating pipe\n");
		}
		else{
			int c=fork();
			if(c>0){
				close(pipefd1[0]);
				write(pipefd1[1],argv[1],strlen(argv[1])); 
			}
			else{
				close(pipefd1[1]);
				int n=read(pipefd1[0],buf1,sizeof(buf1));
				//printf("%ld %s\n",sizeof(buf1),buf1);
				int fd=open(buf1,O_RDONLY);
				/*if(fd==-1){
					printf("Error opening file\n");
				}*/
				//else{
					read(fd,buf2,sizeof(buf2));
					write(pipefd2[1],buf2,strlen(buf2)); 
					read(pipefd2[0],buf3,sizeof(buf3));
					printf("sizeof buf3:%ld  buf3: %s\n",sizeof(buf3),buf3);
				//}
				
			}
		}
	}
	return 1;
}
