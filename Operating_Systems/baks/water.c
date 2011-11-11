/*
 * water.c
 *
 *  Created on: 25-Jul-2010
 *      Author: vivek
 */

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

void *hReady(void *arg);
void *oReady(void *arg);
void *makeWater();

int hAtom;
int oAtom;
sem_t lock;
sem_t lockReturn;
pthread_t h1, h2, o;

int main()
{
    printf("Multithreaded Program !\n");

    while(1)
    {
    	hAtom = 2;
    	oAtom = 1;
    	sem_init(&lock, 0, 1);
    	sem_init(&lockReturn, 0, 0);

    	pthread_create(&h1, NULL, hReady, "H atom 1");
    	pthread_create(&h2, NULL, hReady, "H atom 2");
    	pthread_create(&o, NULL, oReady, "Oxygen atom");

    	pthread_join(o, NULL);
    	pthread_join(h1, NULL);
    	pthread_join(h2, NULL);
		pthread_detach(h1);
    	pthread_detach(h2);
    	pthread_detach(o);
    	sem_destroy(&lock);
    	sem_destroy(&lockReturn);
    	printf("========================================\n");
    	usleep(10001000);
    }

    return 0;
}

void *hReady(void *arg)
{
	char* msg;
	msg = (char*)arg;

	sem_wait(&lock);
	if(hAtom == 0)
	{
		sem_post(&lock);
		return;
	}
	hAtom--;
	printf("Created %s.\n",msg);
	sem_post(&lock);

	pthread_join(o, NULL);
	sem_wait(&lockReturn);
	printf("Returning from hReady() ( %s ).\n",msg);
	sem_post(&lockReturn);
	return;
}

void *oReady(void *arg)
{
	char* msg;
	msg = (char*)arg;

	while(1)
	{
		if(oAtom == 0)
		{
			sem_wait(&lock);
			if(hAtom == 0)
			{
				pthread_t water;
				pthread_create(&water, NULL, makeWater, "make water");
				pthread_join(water, NULL);
				sem_post(&lockReturn);
				printf("Returning from oReady() ( %s ).\n",msg);
				return;
			}
			sem_post(&lock);
		}
		else if(oAtom == 1)
		{
			oAtom--;
			printf("Created %s.\n",msg);
		}
	}
	return;
}

void *makeWater()
{
	printf("Making water using 2 H atoms & 1 O atom.\n");
	return;
}
