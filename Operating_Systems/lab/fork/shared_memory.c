/*
 * shared_memory.cpp
 *
 *  Created on: 09-Aug-2010
 *      Author: vivek
 */

#include <stdio.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <wait.h>


#define SHMSZ 64

int main()
{
	char c;
	int shmid;
	key_t key;
	char *shm, *s;

	key = 5678;

	pid_t pid;
	pid = fork();
	if(pid > 0)
	{
		printf("In parent process");

		/*
		 * Create the segment.
		 */
		if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
			perror("shmget");
			exit(1);
		}

		/*
		 * Now attach the segment to our data space.
		 */
		if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
			printf("shmat");
			exit(1);
		}

		s = shm;

		for (c = '1'; c <= '9'; c++)
			*s++ = c;
		*s = NULL;

		/*
		 * Finally, we wait until the other process
		 * changes the first character of our memory
		 * to '*', indicating that it has read what
		 * we put there.
		 */
		while (*shm != '*')
			sleep(1);

		printf("In parent process");

		exit(0);
	}
	else if( pid == 0)
	{
		/*
		 * Locate the segment.
		 */
		shmid = -1;
		while(shmid < 0)
		{
			shmid = shmget(key, SHMSZ, 0666);
			if(shmid >= 0)
				break;
			printf("getting shmid.\n");
		}

		if (shmid < 0) {
			printf("shmget");
			exit(1);
		}

		/*
		 * Now we attach the segment to our data space.
		 */
		if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
			printf("shmat");
			exit(1);
		}

		/*
		 * Now read what the server put in the memory.
		 */
		s = shm;
		int i = 1;
		for( ; i <= 9; i++)
			s++;
		while(1)
		{

			if(*s == NULL)
				break;
			else
			{
				printf("checking for *s == NULL");
				continue;
			}
		}
		for (s = shm; *s != NULL; s++)
			putchar(*s);
		putchar('\n');

		/*
		 * Finally, change the first character of the
		 * segment to '*', indicating we have read
		 * the segment.
		 */
		*shm = '*';

		exit(0);

	}
}
