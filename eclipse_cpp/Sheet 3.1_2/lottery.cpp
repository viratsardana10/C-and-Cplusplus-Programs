/*
 * lottery.cpp
 *
 *  Created on: 15-Aug-2010
 *      Author: vivek
 */

#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <cstdlib>
#include <cstring>
#include <iterator>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

//#define    _time 3000

int numProcess;
int numTickets;
vector<int> *ticket;
vector<int> completedProcessId;
sem_t *lock;
sem_t _lock;

void scheduler();
void *process(void *arg );

ostream_iterator<int> output(cout, " ");

int main()
{

	printf("Hello \n");
	printf( "Enter the no. of processes to create :");
	cin >> numProcess;

	ticket = new vector<int>[numProcess];
	lock = new sem_t[numProcess];

	numTickets = numProcess * 5;
	cout << "\nAllocating " << numTickets << " tickets to the processes. \n";

	int i = 1;
	while(i <= numTickets)
	{
		srand(i);
		ticket[rand()%numProcess].push_back(i) ;
		i++;
	}

	pthread_t pth[numProcess];
	int pid[numProcess];
	sem_init(&_lock, 0, 0);

	int k = 0;
	for( ; k < numProcess; k++ )
	{
		cout << "Process " << k << " : ";
		copy(ticket[k].begin(), ticket[k].end(), output);
		cout << endl;

		/* Initialise the semaphores. */
		sem_init(&lock[k], 0, 0);
		pid[k] = k;
		pthread_create(&pth[k], NULL, process, &pid[k]);
	}
	cout << endl;

	scheduler();

	return 0;
}

void scheduler()
{

	int randomize = (unsigned) time(NULL);
	while(true)
	{
		srand(randomize);
		int ticketId = rand()%numTickets;
//		printf("randomize: %d, ticketId: %d\n", randomize, ticketId);
//		printf("Ticket %d is selected.\n", ticketId);
//		bool isTicketPresent = true;
		/* search for that ticket in the assigned process */

//		copy(completedProcessId.begin(), completedProcessId.end(), output);

		int counter = 0;
		for( ; counter < numProcess; counter++)
		{
			/* Check if the process is already executed */
			if( find( completedProcessId.begin(), completedProcessId.end(), counter) == completedProcessId.end())
			{
				/* Check the ticket in the list of tickets assigned to the process */
				if( find( ticket[counter].begin(), ticket[counter].end(), ticketId ) != ticket[counter].end() )
				{
					/* Choose process with id k to execute.*/
//					printf("counter: %d \n", counter);
					sem_post(&lock[counter]);
					completedProcessId.push_back(counter);
					break;
				}
				else continue;
			}
			else sem_post(&_lock);
		}
		randomize++;
		sem_wait(&_lock);

		/* Check if all processes have been executed */
//		if(counter == numProcess)
//			break;
	}

	return;
}

void *process(void *arg)
{
	int id;
	id = *((int*)arg);
//	printf("Id: %d\n", id) ;
	sem_wait(&lock[id]);
	printf("Process %d executing.\n", id);
	sem_post(&lock[id]);
//	usleep(5000);
	sem_post(&_lock);

}
