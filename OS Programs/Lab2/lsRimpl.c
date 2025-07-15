#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>

void dir(char path[]){
	DIR* D=opendir(path);
	if(D==NULL){
		perror("opendir");
		return;
	}
	struct dirent* d;
	while((d=readdir(D))!=NULL){
		if(strcmp(d->d_name,".")==0 || strcmp(d->d_name,"..")==0){
			continue;
		}
		if(d->d_type==DT_DIR){
			char new_path[2000];
			//snprintf(new_path,sizeof(new_path),"%s/%s",path,d->d_name);
			strcpy(new_path,path);
			strcat(new_path,"/");
			strcat(new_path,d->d_name);
			printf("Directory: %s\n",d->d_name);
			dir(new_path);
		}
		else{
			printf("File: %s\n",d->d_name);
		}
	}
	closedir(D);
	return;
}

int main(int argc,char* argv[]){
	if(argc<2){
		dir(".");
	}
	else{
		dir(argv[1]);
	}
	
	return 1;
}
