#include<pthread.h>
#include<stdio.h>

void* proc();

int main(){
	pthread_t t1;
	pthread_create(&t1,NULL,proc,NULL);
	pthread_join(t1,NULL);
	printf("main");
	
}

void* proc(){
	printf("thread1");
}
