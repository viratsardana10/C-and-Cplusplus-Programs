/*
 *  Selfish Round Robin.cpp
 * 
 *  Created on : 18-08-2010
 *  	Author : Vivek Prakash
 * 
 */

#include <iostream>
#include <cstdlib>
#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

#define FOR(A,B,C) for(int i = A; i < B; i+=C)

#define rate_x 3
#define rate_y 2

int numProcess;
struct PCB{
	int id;
	sem_t lock;
	int priority;
	bool waiting;
} *pcb;

vector<int> completedProcess;
sem_t lock;

void scheduler();
void *process(void *);
void isAllowedToExecute(int );

int main()
{
	
	cout << "Enter the no. of processes: ";
	cin >> numProcess;
	
	pcb = new struct PCB[numProcess];
	for(int i = 0 ; i < numProcess ; i++)
	{
		sem_init(&(pcb[i].lock), 0 , 0);
		pcb[i].priority = 1;  			/* Initialize priority of all processes with 1 */
		pcb[i].waiting = true;
	}
	
	pcb[0].priority = 150;		/* Set prcess 0 to execute */
	pcb[0].waiting = false;
	
	pthread_t pth[numProcess];
	
	for(int i = 0; i < numProcess ; i++)
	{	
		pcb[i].id = i;
		pthread_create(&pth[0], NULL, process, &(pcb[i].id));
	}
	
	scheduler();
	return 0;
}

void scheduler()
{
	printf("Scheduling the processes: \n");
	sem_init(&lock, 0, 1);

	while(completedProcess.size()!=numProcess)
	{
		FOR(0,numProcess,1)
			printf("%d  ", pcb[i].priority);

		printf("\n");
		
		for(int i = 0; i < numProcess; i++)
		{
			if(pcb[i].waiting)
			{
				(pcb[i].priority) += (2*rate_x);
				isAllowedToExecute(i);
			}
			else if(!pcb[i].waiting)
			{
				(pcb[i].priority) += (2*rate_y);
				sem_post(&(pcb[i].lock));
			}
		}
		
	}
	return;
}

void isAllowedToExecute(int i)
{
	for(int k = 0; k < numProcess; k++)
	{
		if(!pcb[k].waiting)
		{
			if(pcb[i].priority >= pcb[k].priority) {
				printf("Process %d priority: %d \n", i, pcb[i].priority);
				pcb[i].waiting = false;
				return;
			}
		}
	}
	return;
}

void *process(void *arg)
{
	int id;
	id = *(int*)arg;
	sem_wait(&(pcb[id].lock));
	
//	pcb[id].waiting = false;
//	int counter = 3;
//	while(counter--)
//	{
	printf("Process %d executing. Priority: %d\n", id, pcb[id].priority);
//	}
	completedProcess.push_back(id);
	sem_post(&lock);
}

