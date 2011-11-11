/*
 * bounded_buffer.cpp
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

#define BUF_SIZE 8
char buffer[BUF_SIZE];
sem_t empty_buf;
sem_t full_buf;
pthread_t p1, p2;

void *writer(void *arg );
void *reader(void *arg );

int main()
{
	sem_init(&empty_buf, 0, BUF_SIZE);
	sem_init(&full_buf, 0, 0);

	char *a = "Writer Initialised";
	char *b = "Reader Initialised";

	pthread_create(&p1, NULL, writer, a);
	pthread_create(&p2, NULL, reader, b);

	pthread_join(p1, NULL);
	pthread_join(p2, NULL);

	pthread_detach(p1);
	pthread_detach(p2);

	sem_destroy(&empty_buf);
	sem_destroy(&full_buf);

	return 0;
}

void *writer(void *arg)
{
	char *msg = (char*)arg;
	printf("%s\n", msg);

	string s;
	char *all = "abcdefghijklmnopqrstuvwxyz";

	for(int i = 0 ; i < BUF_SIZE*2; ++i)
	{
		srand(i);
		char c = all[rand()%26];

		sem_wait(&empty_buf);
//		printf("%s : %c\n", "WRITER", c);
		s.push_back(c);
//		printf("%s : %s\n", "W", s);
		cout << "W : " << s << endl;
		buffer[i%BUF_SIZE] = c;
		sem_post(&full_buf);
	}
}

void *reader(void *arg)
{
	char *msg = (char*)arg;
	printf("%s\n", msg);

	string s;
	for(int i = 0 ; i < BUF_SIZE*2; ++i)
	{
		sem_wait(&full_buf);
		char c = buffer[i%BUF_SIZE];
//		printf("%s : %c\n", "READER", c);
		s.push_back(c);
//		printf("%s : %s\n", "R", s);
		cout << "R : " << s << endl;
		sem_post(&empty_buf);
	}
}
