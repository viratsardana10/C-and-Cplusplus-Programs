/*
 * dining_philosphers.cpp
 *
 *  Created on: 29-Jul-2010
 *      Author: vivek
 */

#include <iostream>
#include <semaphore.h>
#include <pthread.h>
#include <cstdlib>
using namespace std;

int main()
{
	sem_t forks[5];
	for(int i = 0; i < 5; i++)
	{
		sem_init(&forks[i], 0, 1);
	}
}
