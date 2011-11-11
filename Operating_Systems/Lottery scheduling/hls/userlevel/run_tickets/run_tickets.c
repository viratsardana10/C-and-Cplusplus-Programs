/* gcc -Wall -o run_tickets run_tickets.c -L../liblott -llott */

#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../liblott/liblott.h"

int main(int argc, char **argv);

int
main(int argc, char **argv)
{
    int num_tickets;

    if(argc < 3) {
	printf("usage: run_tickets <tickets> <program> [args...]\n");
	exit(-1);
    }

    num_tickets = atoi(argv[1]);

    if(lott_set_user_tickets(getpid(), num_tickets) == -1) {
	perror("lott_set_tickets");
	return -1;
    }

    if(execvp(argv[2], &argv[2]) == -1) {
	perror("execvp");
	return -1;
    }

    return 0;
}


