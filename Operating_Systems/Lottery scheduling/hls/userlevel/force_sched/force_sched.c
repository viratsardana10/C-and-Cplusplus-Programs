/* gcc -Wall -o force_sched force_sched.c -L../liblott -llott */

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
    force_sched_t force_sched;
    ticket_t force_sched_val;
    bool got_pid = FALSE, got_force_sched = FALSE, arg_error = FALSE;
    char c;

    while((c = getopt(argc, argv, "np:m:l:")) != EOF) {
	switch(c) {
	case 'p':
	    got_pid = TRUE;
	    pid = atoi(optarg);
	    break;
	case 'm':
	    got_force_sched = TRUE;
	    force_sched = FORCE_AT_MOST;
	    force_sched_val = atoi(optarg);
	    break;
	case 'l':
	    got_force_sched = TRUE;
	    force_sched = FORCE_AT_LEAST;
	    force_sched_val = atoi(optarg);
	    break;
	case 'n':
	    if(optarg != 0) {
		arg_error = TRUE;
	    }
	    got_force_sched = TRUE;
	    force_sched = FORCE_NORMAL;
	    force_sched_val = 1000; /* xxx don't use constants! :) */
	    break;
	case '?':
	default:
	    arg_error = TRUE;
	    break;
	}
    }

    if((got_pid == FALSE) || (got_force_sched == FALSE)
       || (arg_error == TRUE)) {
	printf("usage: force_sched -p<pid> -m|-l|-n <base tickets>\n"
	       "       -m means schedule with at most <base tickets>\n"
	       "       -l means schedule with at least <base tickets> if "
	       "root\n"
	       "       -n means normal scheduling (exclude <base tickets>)\n");
	return -1;
    }

    if(lott_set_force(pid, force_sched, force_sched_val) == -1) {
	perror("lott_set_force");
	return -1;
    }

    return 0;
}
