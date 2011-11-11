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

using namespace std;

void *scheduler(void* );

int main()
{
	int numProcess;
	cout << "Enter the no. of processes to create :";
	cin >> numProcess;

	int numTickets = numProcess * 5;
	cout << "\nAllocating " << numTickets << " tickets to the processes. \n";

	int *processTicket;
	processTicket = new int[numProcess];


	int i = 0;
	while(i < numTickets)
	{
		srand((unsigned) time(NULL));
		processTicket[rand()%numProcess] += 1;
		i++;
	}

	ostream_iterator<int> output(cout, " ");
	copy(processTicket, processTicket + numProcess, output);

	cout << endl;

	return 0;
}
