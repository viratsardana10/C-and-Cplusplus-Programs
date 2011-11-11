/* gcc -Wall -o set_funding set_funding.c -L../liblott -llott */

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
    pid_t uid;
    ticket_t base_tickets;
    bool got_base_tickets = FALSE, arg_error = FALSE;
    char c;

    uid = getuid();
    while((c = getopt(argc, argv, "u:t:")) != EOF) {
	switch(c) {
	case 'u':
	    uid = atoi(optarg);
	    break;
	case 't':
	    got_base_tickets = TRUE;
	    base_tickets = atoi(optarg);
	    break;
	case '?':
	default:
	    arg_error = TRUE;
	    break;
	}
    }

    if((got_base_tickets == FALSE) || (arg_error == TRUE)) {
	printf("usage: set_funding [-u<uid>] -t<base_tickets>\n");
	return -1;
    }

    if(lott_set_base_tickets(uid, base_tickets) == -1) {
	perror("lott_set_base_tickets");
	return -1;
    }

    return 0;
}
