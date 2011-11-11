#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int main()
{
	int tickets[50];
	int alloted = 0;
	pthread_t pth[100];
	int allotedTickets[100];
	
	int i = 0;
	while(alloted < 50)
	{
		int numAlloted = rand()%10 + 1;
		
		pthred_create(&pth[])
	}
}

void schedule()
{
	
}
