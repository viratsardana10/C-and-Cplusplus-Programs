/* gcc -Wall -o show_tickets set_handoff.c -L../liblott -llott */

#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../liblott/liblott.h"

int main(int argc, char **argv);
void parse_args(int argc, char **argv);

pid_t pid_from, pid_to;

int
main(int argc, char **argv)
{
    parse_args(argc, argv);

    printf("from: %d, to: %d\n", pid_from, pid_to);
    lott_handoff(pid_from, pid_to);

    return 0;
}

void
parse_args(int argc, char **argv)
{
    char c;
    bool arg_error = FALSE;

    bool got_to_pid = FALSE, got_from_pid = FALSE;

    while((c = getopt(argc, argv, "hf:t:")) != EOF) {
	switch(c) {
	case 'h':
	    arg_error = TRUE;
	    break;
	case 'f':
	    got_from_pid = TRUE;
	    pid_from = atoi(optarg);
	    break;
	case 't':
	    got_to_pid = TRUE;
	    pid_to = atoi(optarg);
	    break;
	case '?':
	default:
	    arg_error = TRUE;
	    break;
	}
    }

    if((arg_error == TRUE) || (got_to_pid == FALSE) ||
       (got_from_pid == FALSE)){
	printf("usage: set_handoff [-f<from_pid>] [-t<to_pid>]\n");
	exit(-1);
    }

    if(pid_from == pid_to) {
	printf("i can't let you do that, dave\n");
    }
}
