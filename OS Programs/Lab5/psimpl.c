#include<sys/types.h>
#include<sys/stat.h>
#include<stdbool.h>
#include<fcntl.h>
#include<dirent.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include <stdlib.h>
#include <ctype.h>

void openstat(char path[]){
	char new_path[2000];
	strcpy(new_path,path);
	strcat(new_path,"/");
	strcat(new_path,"stat");
	int fd=open(new_path,O_RDONLY);
	char p_id[50];
	char p_name[50];
	char buf[50];
	int i,j=0,size_read=read(fd,buf,sizeof(buf));
	for(i=0;buf[i]!=' ';i++){
		p_id[i]=buf[i];
	}
	p_id[i]='\0';
	++i;
	++i;
	for(;buf[i]!=')';i++){
		p_name[j]=buf[i];
		j++;
	}
	p_name[j]='\0';
	printf("%s\t%s\n",p_id,p_name);
}
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
			int flag=1;
			int j=0;
			char* temp=d->d_name;
			while(j<strlen(temp)){
				if(!(temp[j]>='0' && temp[j]<='9')){
					flag=0;
					break;
				}
				j++;
			}
			if(flag){
				char new_path[2000];
				strcpy(new_path,path);
				strcat(new_path,d->d_name);
				openstat(new_path);
			}
		}
	}
	closedir(D);
	return;
}

int main(){
	char path[]="/proc/";
	dir(path);
	return 1;
}





