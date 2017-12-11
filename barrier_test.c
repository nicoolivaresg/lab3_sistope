#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

pthread_barrier_t barrier;

void* barrier_test(void* args) {
	int* threadP = (int*)args;
	int thread = *threadP;
	printf("thread %d starts execution\n", thread);
	for (int i = 0; i < 1000000000; ++i){}
	printf("thread %d enters barrier\n", thread);
	pthread_barrier_wait(&barrier);
	printf("thread %d exits barrier\n", thread);
	for (int i = 0; i < 1000000000; ++i){}
	printf("thread %d enters second barrier\n", thread);
	pthread_barrier_wait(&barrier);
	printf("thread %d exits second barrier\n", thread);
	for (int i = 0; i < 1000000000; ++i){}
	printf("thread %d enters third barrier\n", thread);
	pthread_barrier_wait(&barrier);
	printf("thread %d exits third barrier\n", thread);
	for (int i = 0; i < 1000000000; ++i){}
	printf("thread %d enters fourth barrier\n", thread);
	pthread_barrier_wait(&barrier);
	printf("thread %d exits fourth barrier\n", thread);
}

int main(int  argc, char ** argv) {
	int threadCount = 5;
	pthread_barrier_init(&barrier, NULL, threadCount);
	pthread_t* threads = malloc(threadCount * sizeof(*threads));
	int* ids = malloc(threadCount * sizeof(*ids));
	for (int i = 0; i < threadCount; ++i)
	{
		ids[i] = i+1;
		pthread_create(&(threads[i]), NULL, barrier_test, (void *)&(ids[i]));
	}

	for (int i = 0; i < threadCount; ++i)
	{
		pthread_join(threads[i], NULL);
	}

	return 0;
}