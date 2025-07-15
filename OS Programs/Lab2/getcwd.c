#include <unistd.h>
#include <stdio.h>
int main(int argc,char* argv[]){
	char buf[100];
	char* path=getcwd(buf,sizeof(buf));
	printf("%s",path);
}
