/* gcc -Wall -o lott_ctl lott_ctl.c -L../liblott -llott */

#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include "../liblott/liblott.h"

int main(int argc, char **argv);

int
main(int argc, char **argv)
{
    bool do_abbrev_quanta;
    bool got_abbrev_quanta = FALSE, arg_error = FALSE;
    char c;
    /* bool do_kern_priority;*/
    
    while((c = getopt(argc, argv, "a:")) != EOF) {
	switch(c) {
	case 'a':
	    got_abbrev_quanta = TRUE;
	    if(strcmp(optarg, "on") == 0) {
		do_abbrev_quanta = TRUE;
	    } else {
		do_abbrev_quanta = FALSE;
	    }	  
	    break;
	case '?':
	default:
	    arg_error = TRUE;
	    break;
	}
    }

    if((got_abbrev_quanta == FALSE) || (arg_error == TRUE)) {
	printf("usage: lott_ctl -a <on|off>\n"
	       "       -a means abbreviated quanta\n");
	return -1;
    }

    if(lott_ctl(TRUE, do_abbrev_quanta, TRUE) == -1) {
	perror("lott_ctl");
	return -1;
    }

    return 0;
}
