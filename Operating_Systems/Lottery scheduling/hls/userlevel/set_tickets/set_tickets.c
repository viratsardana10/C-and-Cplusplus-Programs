/* gcc -Wall -o set_tickets set_tickets.c -L../liblott -llott */

#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include "../liblott/liblott.h"

int main(int argc, char **argv);

int
main(int argc, char **argv)
{
    pid_t pid;
    ticket_t num_tickets;
    bool got_pid = FALSE, got_num_tickets = FALSE, arg_error = FALSE;
    char c;

    while((c = getopt(argc, argv, "p:t:")) != EOF) {
	switch(c) {
	case 'p':
	    got_pid = TRUE;
	    pid = atoi(optarg);
	    break;
	case 't':
	    got_num_tickets = TRUE;
	    num_tickets = atoi(optarg);
	    break;
	case '?':
	default:
	    arg_error = TRUE;
	    break;
	}
    }

    if((got_pid == FALSE) || (got_num_tickets == FALSE)
       || (arg_error == TRUE)) {
	printf("usage: set_tickets -p<uid> -t<tickets>\n");
	return -1;
    }

    if(lott_set_user_tickets(pid, num_tickets) == -1) {
	perror("lott_set_user_tickets");
	return -1;
    }

    return 0;
}
