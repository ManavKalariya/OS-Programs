/*This program creates only one thread refered by t1 and calls different procedures.
So multithreading isnt achieved by it.
#include<pthread.h>
#include<stdio.h>

void* proc1();
void* proc2();
int main(){
	pthread_t t1;
	pthread_create(&t1,NULL,proc1,NULL);
	pthread_create(&t1,NULL,proc2,NULL);
	pthread_join(t1,NULL);
	//pthread_join(t1,NULL);
}

void* proc1(){
	printf("thread1");
}
void* proc2(){
	printf("thread2");
}

way1:At a time only one thread is in execution
create1
join1
create2
join2
.
.
.

way2: At a time multiple threads are in parallel execution
create1
create2
create3
join1
join2
join3
*/

#include<pthread.h>
#include<stdio.h>

void* proc1();
void* proc2();
int main(){
	pthread_t t1,t2;
	pthread_create(&t1,NULL,proc1,NULL);
	pthread_create(&t2,NULL,proc2,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
}

void* proc1(){
	printf("thread1");
}
void* proc2(){
	printf("thread2");
}
