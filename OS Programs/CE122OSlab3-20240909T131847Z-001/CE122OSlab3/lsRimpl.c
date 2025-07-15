#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>

void dir(char* path){
	
	DIR* D=opendir(path);
	struct dirent* d;
	while(1){
		d=readdir(D);
		if(d==NULL){
			break;
		}
		if(d->d_name=="." || d->d_name==".."){
			continue;
		}
		if(d->d_type==DT_DIR){
			strcat(path,"/");
			strcat(path,d->d_name);
			printf("%s\n",d->d_name);
			//printf("dfvd");
			dir(path);
		}
		else{
			printf("%s\n",d->d_name);
		}
	}
}

int main(int argc,char* argv[]){
	if(argv[1]==NULL){
		dir(".");
	}
	else{
		dir(argv[1]);
	}
	
	return 1;
}
