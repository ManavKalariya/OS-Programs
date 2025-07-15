#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	pid_t p=fork();
	if(p==0){
		printf("Hello Child");
	}
	else if(p>0){
		printf("Hello Parent");		
	}	
	else{
		printf("Error creating Child");
	}
}
