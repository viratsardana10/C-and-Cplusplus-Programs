/*
 * lottery.c
 *
 *  Created on: 15-Aug-2010
 *      Author: vivek
 */

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <queue.h>
#include <vector.h>

void *scheduler(void* );
int numProcess, numTickets;

int main()
{
	printf("Enter the no. of processes to create: ");
	scanf("%d", &numProcess);

	numTickets = numProcess * 5;

	int ticket[numProcess];

	int i = 0;
	for( ; i < numProcess ; i++)
	{
		ticket[i] = 0;
	}

	int k = 0;
	while(k < numTickets)
	{
		srand(k);
		int random = rand();
		int index = random%numProcess;
//		printf("%d %d,", random, index);
		ticket[index]++;
		k++;
//		usleep(10000);
	}

	i = 0;
	for( ; i < numProcess ; i++)
	{
		if(ticket[i] == 0)
		{
			ticket[i]++;
			numTickets++;
		}
		printf("Process %d is allocated %d tickets.\n", i, ticket[i]);
	}

	return 0;
}

void *scheduler(void *arg)
{
	srand((unsigned) time(NULL));
//	int ticketId = rand()%
}
