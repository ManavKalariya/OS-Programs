#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdio.h>
int main(int argc,char* argv[]){
	DIR* D;
	if(argv[1]==NULL){
		D=opendir(".");
	}
	else{
		D=opendir(argv[1]);
	}
	
	struct dirent* d;
	while(d=readdir(D)){
		printf("%s\n",d->d_name);
	}
	return 1;
}
