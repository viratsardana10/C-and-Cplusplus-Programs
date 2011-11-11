/*
 * smokers.cpp
 *
 *  Created on: 10-Nov-2010
 *      Author: vivek
 */

#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <cstdlib>
using namespace std;

sem_t A[3];
sem_t T;
int id[3] = {0, 1, 2};

void *arbiter(void * );
void *smoker(void * );

int main()
{
	for(int i = 0; i < 3; ++i)
		sem_init(&A[i], 0, 0);
	sem_init(&T, 0, 1);

	pthread_t p1, p[3];

	pthread_create(&p1, NULL, arbiter, NULL );
	for(int i = 0; i < 3; ++i)
		pthread_create(&p[i], NULL, smoker, &id[i]);

	pthread_join(p1, NULL);

	return 0;
}

void *arbiter(void *arg)
{
	int random = 0;
	while(true)
	{
		sem_wait(&T);
		srand(random);
		int i = rand()%3;
		srand(++random);
		int j = rand()%3;
		while(i == j)
		{
			srand(++random);
			j = rand()%3;
		}
		int k = 3 - (i+j);
		printf("Arbiter selected %d & %d. %d will now smoke.\n", i, j, k);
		sem_post(&A[k]);
		
		++random;
		if(random > 30)
			return NULL;
	}
}

void *smoker(void *arg)
{
	int id = *(int*)arg;
	while(true)
	{
//		printf("id : %d.\n", id);
		sem_wait(&A[id]);
		printf("%d : making a cigarette.\n", id);
		sem_post(&T);
		printf("%d : smoking cigarette.\n", id);
	}
}
