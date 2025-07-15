#include<pthread.h>
#include<stdio.h>

void* add();
void* sub();
void* mul();
void* div();
struct mystruct{
	int x,y;
}typedef structure;
int main(){
	int x,y;
	char op;
	printf("Enter two numbers:\n");
	scanf("%d\n%d",&x,&y);
	structure s={x,y};
	pthread_t thread_add,thread_sub,thread_mul,thread_div;
	printf("Enter Operation(+,-,*,/):\n");
	scanf("%*c%c",&op);
	switch(op){
		case '+':
		pthread_create(&thread_add,NULL,add,&s);
		pthread_join(thread_add,NULL);
		break;
		case '-':
		pthread_create(&thread_sub,NULL,sub,&s);
		pthread_join(thread_sub,NULL);
		break;
		case '*':
		pthread_create(&thread_mul,NULL,mul,&s);
		pthread_join(thread_mul,NULL);
		break;
		case '/':
		pthread_create(&thread_div,NULL,div,&s);
		pthread_join(thread_div,NULL);
		break;
		default:
		printf("Invalid Operation");
		break;
	}
}

void* add(void* arg){
	structure* s=(structure*)arg;
	printf("Answer=%d\n",(s->x)+(s->y));
}
void* sub(void* arg){
	structure* s=(structur e*)arg;
	printf("Answer=%d\n",(s->x)-(s->y));
}
void* mul(void* arg){
	structure* s=(structure*)arg;
	printf("Answer=%d\n",(s->x)*(s->y));
}
void* div(void* arg){
	structure* s=(structure*)arg;
	printf("Answer=%lf\n",(s->x)/(double)(s->y));
}

/*#include<pthread.h>
#include<stdio.h>

void* proc1();
void* proc2();
struct mystruct{
	int x,y;
}typedef structure;
int main(){
	
	structure s={1,2};
	pthread_t t1,t2;
	pthread_create(&t1,NULL,proc1,&s);
	pthread_create(&t2,NULL,proc2,&s);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
}

void* proc1(void* arg){
	structure* s=(structure*)arg;
	printf("In thread 1\nx=%d\ty=%d\n",s->x,s->y);
}
void* proc2(void* arg){
	structure* s=(structure*)arg;
	printf("In thread 2\nx=%d\ty=%d\n",s->x,s->y);
}
*/
