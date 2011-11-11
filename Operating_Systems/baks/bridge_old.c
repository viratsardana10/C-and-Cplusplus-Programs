#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>


void* OneVehicle(void* );
void ArriveBridge(int );
void CrossBridge(int );
void ExitBridge(int );

//int bridgeCapacity = 3;
//int currentLoad = 0;
//int time = 100000;
sem_t numAllowedtoCross;
sem_t lockBridge;
sem_t lock;

int currentDirec;

int main()
{
	 printf("Multi-threaded Program !\n");

	 sem_init(&numAllowedtoCross, 0, 3);            // critical section lock
	 sem_init(&lockBridge, 0, 1);      // bridge lock
	 sem_init(&lock, 0, 1);
//	 Queue q;
//	 q = CreateQueue(100);

	 while(1)
	 {
		 srand((unsigned) time(NULL));
		 int direc = rand()%2;
		 printf("Another vehicle arrived in direction: %d.\n",direc);
//		 Enqueue(direc, q);
		 pthread_t pth;
		 pthread_create(&pth, NULL, OneVehicle, &direc);
		 int randTime = rand()%1000000;
		 usleep(randTime);
//		 count ++;
	 }

	 return 0;
}

void* oneVehicle(void* arg)
{
	int direc = *((int*)arg);
	ArriveBridge(direc);
	CrossBridge(direc);
	ExitBridge(direc);
}

void ArriveBridge(int direc)
{
	/*  Lock the critical section because if two cars
	 *  arrive on the bridge at the same time, there
	 *  will be a deadlock with neither willing to go back !
	 */
	sem_wait(&lock);

	while(1)
	{
		if(sem_getvalue(lockBridge) == 1)
		{
			if(direc != currentDirec)
			{
				currentDirec = direc;
				sem_init(&numAllowedtoCross, 0, 3);
			}
			break;  // no head-on collision
		}
		else if(sem_getvalue(lockBridge) == 0)
			continue;
	}
	/* pass through above code only after bridge is unlocked */

	sem_wait(numAllowedtoCross); // no bridge collapse

	/* Lock the bridge if numAllowedToCross is zero */
//	if(sem_getvalue(numAllowedtoCross) == 0)
//		sem_wait(lockBridge);

	sem_post(lock);

	printf("Arrived on bridge in direction: %d.\n",direc);
	return;
}

void CrossBridge(int direc)
{
	printf("Crossing bridge in direction: %d.\n",direc);
//	usleep(time);
}

void ExitBridge(int direc)
{
	sem_post(numAllowedtoCross);
	printf("Exiting bridge in direction: %d.\n",direc);
}
