#include<pthread.h>
#include<stdio.h>

void* proc();
int main(){
	char* str1="hello thread1\n";
	pthread_t t1;
	pthread_create(&t1,NULL,proc,str1);
	pthread_join(t1,NULL);
}

void* proc(void* arg){
	char* s=(char*)arg;
	printf("%s",s);
}
