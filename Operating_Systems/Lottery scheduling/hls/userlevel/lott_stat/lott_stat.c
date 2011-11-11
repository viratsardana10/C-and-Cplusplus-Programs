/* gcc -Wall -o lott_stat lott_stat.c -L../liblott -llott */

#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include "../liblott/liblott.h"

int main(int argc, char **argv);

int
main(int argc, char **argv)
{
    bool print_stats = FALSE, cycle_stats = FALSE, proc_stats = FALSE,
	location_stats = FALSE;
    pid_t pid = -1;
    bool arg_error = FALSE;
    char c;

    while((c = getopt(argc, argv, "i:l:c:p:o:")) != EOF) {
	switch(c) {
	case 'i':
	    if(strcmp(optarg, "on") == 0) {
		print_stats = TRUE;
	    } else {
		print_stats = FALSE;
	    }	  
	    break;
	case 'l':
	    if(strcmp(optarg, "on") == 0) {
		proc_stats = TRUE;
	    } else {
		proc_stats = FALSE;
	    }	  
	    break;
	case 'c':
	    if(strcmp(optarg, "on") == 0) {
		cycle_stats = TRUE;
	    } else {
		cycle_stats = FALSE;
	    }	  
	    break;
	case 'o':
	    if(strcmp(optarg, "on") == 0) {
		location_stats = TRUE;
	    } else {
		location_stats = FALSE;
	    }	  
	    break;
	case 'p':
	    pid = atoi(optarg);
	    break;
	case '?':
	default:
	    arg_error = TRUE;
	    break;
	}
    }

    if(arg_error == TRUE) {
	printf("usage: lott_stat [-i<on|off>] [-l<on|off>] [-c<on|off>] "
	       "[-p<pid|-1>] [-o<on|off>]\n"
	       "       -i means print miscellaneous information\n"
	       "       -l means turn on process instrumentation\n"
	       "       -c means turn on cycle count instrumentation\n"
	       "       -o means turn on location instrumentation\n"
	       "       (the default for the previous arguments is off)\n"
	       "       -p specifies process, -1 for all (the default)\n");
	return -1;
    }

    if(lott_stat(print_stats, proc_stats, cycle_stats, location_stats, pid)
       == -1) {
	perror("lott_stat");
	return -1;
    }

    return 0;
}
