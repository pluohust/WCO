#include <pthread.h>
#include <malloc.h>
#include <iostream>
#include <sys/time.h>
#include <unistd.h>

using namespace std;

pthread_mutex_t L1;

int *p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8;

void *TestThread(void *arg)
{
	sleep(1);
	pthread_mutex_lock(&L1);
	*p1=2;
	pthread_mutex_unlock(&L1);
	cout<<"*p1: "<<*p1<<endl;
	pthread_mutex_lock(&L1);
	*p1=2;
	pthread_mutex_unlock(&L1);
	return NULL;
}

int main()
{
	pthread_t testthread;
	int rc;

	p1=(int *)malloc(sizeof(int));
char luopeng_malloc_get1[1];
sprintf(luopeng_malloc_get1,"",8808,p1,sizeof(int));

	rc=pthread_create(&testthread, NULL, TestThread, 0);
	pthread_mutex_lock(&L1);
	*p1=1;
	pthread_mutex_unlock(&L1);
	pthread_join(testthread, 0);
	cout<<"p1: "<<hex<<p1<<dec<<endl;
	free(p1);
	return 0;
}
