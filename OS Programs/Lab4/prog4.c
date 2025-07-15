#include<pthread.h>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void* proc();
int count=0;
pthread_mutex_t m=PTHREAD_MUTEX_INITIALIZER;
int main(){
	//char* str1="hello thread1\n";
	pthread_t t1,t2,t3;
	/*Race condition: when multiple threads try to access a global variable(Shared Resource)*/
	pthread_create(&t1,NULL,proc,NULL);
	pthread_create(&t2,NULL,proc,NULL);
	pthread_create(&t3,NULL,proc,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);
}

void* proc(void* arg){
	int i=100000;
	
	while(i>0){
		pthread_mutex_lock(&m);
		count++;
		pthread_mutex_unlock(&m);
		i--;
	}
	printf("thread:%d count=%d\n",getpid(),count);
}
