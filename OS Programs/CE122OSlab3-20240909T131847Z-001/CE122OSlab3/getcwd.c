#include <unistd.h>

int main(int argc,char* argv[]){
	char buf[100];
	char** path=getcwd(buf,sizeof(buf));
	write(1,path,sizeof(path));
}
