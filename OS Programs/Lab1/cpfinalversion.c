#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc,char* argv[]){
	char buf[50];
	int fd1=open(argv[1],O_RDWR);
	int fd2=open(argv[2],O_RDWR|O_CREAT,S_IRWXU);
	int n1=read(fd1,buf,sizeof(buf));
	int n2=write(fd2,buf,n1);
	return 1;
}
