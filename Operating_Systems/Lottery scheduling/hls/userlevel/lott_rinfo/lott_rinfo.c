/* gcc -Wall -o lott_rinfo lott_rinfo.c -L../liblott -llott */

#include <sys/types.h>
#include <sys/proc.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../liblott/liblott.h"

#define MAX_STR 80

int main(int argc, char **argv);
void tab_strcpy(char *dest, char *source, int tabs);
void parse_args(int argc, char **argv);

bool show_proc;
bool show_idle;
bool show_quantum_expire;
bool show_cycles;
bool show_location;
bool for_stat;

int num_repeat = 1;
int num_entries;

int
main(int argc, char **argv)
{
    struct lott_rorder *rorder;
    int i;
    char comm[MAXCOMLEN], p_stat[MAX_STR + 1], function[FUNCTION_STRLEN + 10];
    int iter;

    parse_args(argc, argv);

    if((rorder = malloc(sizeof(struct lott_rorder) * num_entries))
       == 0) {
	printf("couldn't malloc() space\n");
	return -1;
    }

    if(for_stat == FALSE) {
	if(show_proc == TRUE) {
	    printf("command\t\tpid\tstat\tpri\tuid\ttime\ttick\tefftick"
		   "\tbasetic\tutil_f32\tt_used\tt_desv\tr_sec\tr_usec\t"
		   "d_time\n");
	}
	if(show_cycles == TRUE) {
	    printf("\tfunction\t\tpid\tcycles\tpri\n");
	}
	if(show_location == TRUE) {
	    printf("loc: pid, comm, chan, pri, wmesg, timo, function, file, line_num, cycles_start, cycles_end\n");
	}
    }

    for(iter = 0; iter < num_repeat; iter++) {
	if((num_entries = lott_run_order(rorder, num_entries)) == -1) {
	    perror("lott_run_order");
	    return -1;
	}
	
	for(i = 0; i < num_entries; i++) {
	    switch(rorder[i].run_info) {
	    case RINFO_PROC:
		if(show_proc == FALSE) {
		    break;
		}
		if(for_stat == TRUE) {
		    break;
		}
		tab_strcpy(comm, rorder[i].rinfo_proc.comm, 2);
		switch(rorder[i].rinfo_proc.stat) {
		case SIDL:
		    tab_strcpy(p_stat, "SIDL", 1);
		    break;
		case SRUN:
		    tab_strcpy(p_stat, "SRUN", 1);
		    break;
		case SSLEEP:
		    tab_strcpy(p_stat, "SSLEEP", 1);
		    break;
		case SSTOP:
		    tab_strcpy(p_stat, "SSTOP", 1);
		    break;
		case SZOMB:
		    tab_strcpy(p_stat, "SZOMB", 1);
		    break;
		}
		printf("%s%d\t%s%d\t%d\t%u\t%u\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
		       comm,
		       rorder[i].rinfo_proc.pid, p_stat,
		       rorder[i].rinfo_proc.kern_priority,
		       rorder[i].rinfo_proc.uid, rorder[i].rinfo_proc.time_used,
		       rorder[i].rinfo_proc.num_tickets,
		       rorder[i].rinfo_proc.eff_tickets,
		       rorder[i].rinfo_proc.base_tickets,
		       rorder[i].rinfo_proc.utilization_f32,
		       rorder[i].rinfo_proc.time_used_over_window_usec,
		       rorder[i].rinfo_proc.time_deserved_over_window,
		       rorder[i].rinfo_proc.runtime_sec,
		       rorder[i].rinfo_proc.runtime_usec,
		       rorder[i].rinfo_proc.dispatch_time);
		break;
	    case RINFO_IDLE:
		if(show_idle == FALSE) {
		    break;
		}
		if(for_stat == TRUE) {
		    break;
		}
		printf("<kernel idle>\n");
		break;
	    case RINFO_QUANTUM_EXPIRE:
		if(show_quantum_expire == FALSE) {
		    break;
		}
		if(for_stat == TRUE) {
		    break;
		}
		printf("<quantum expiration, force mi_switch()>\n");
		break;
	    case RINFO_CYCLES:
		if(show_cycles == FALSE) {
		    break;
		}
		if(for_stat == TRUE) {
		    printf("%qd\t\t%s\n", rorder[i].rinfo_cycles.cycles,
			   rorder[i].rinfo_cycles.function);
		} else {
		    tab_strcpy(function, rorder[i].rinfo_cycles.function, 3);
		    if(rorder[i].rinfo_cycles.pid == -1) {
			printf("\t%s(none)\t%qd\t%d\n", function,
			       rorder[i].rinfo_cycles.cycles,
			       rorder[i].rinfo_cycles.priority);
		    } else {
			printf("\t%s%d\t%qd\t%d\n", function,
			       rorder[i].rinfo_cycles.pid,
			       rorder[i].rinfo_cycles.cycles,
			       rorder[i].rinfo_cycles.priority);
		    }
		}
		break;
	    case RINFO_LOCATION:
		printf("loc: %d, %s, %p, %d, %s, %d, %s, %s, %d, %qd, %qd\n",
		       rorder[i].rinfo_location.pid,
		       rorder[i].rinfo_location.comm,
		       rorder[i].rinfo_location.chan,
		       rorder[i].rinfo_location.pri,
		       rorder[i].rinfo_location.wmesg,
		       rorder[i].rinfo_location.timo,
		       rorder[i].rinfo_location.function,
		       rorder[i].rinfo_location.file,
		       rorder[i].rinfo_location.line_num,
		       rorder[i].rinfo_location.cycles_start,
		       rorder[i].rinfo_location.cycles_end);
		break;
	    }
	}
    }

    return 0;
}

void
tab_strcpy(char *dest, char *source, int tabs)
{
    int i;

    i = strlen(source) / 8;
    tabs -= i;

    strcpy(dest, source);
    for(i = 0; i < tabs; i++) {
	strcat(dest, "\t");
    }
}

void
parse_args(int argc, char **argv)
{
    char c;
    bool arg_error = FALSE, got_num_entries = FALSE;

    show_proc = TRUE;
    show_idle = TRUE;
    show_quantum_expire = TRUE;
    show_cycles = TRUE;
    show_location = TRUE;
    for_stat = FALSE;

    while((c = getopt(argc, argv, "hp:i:q:c:n:s:l:r:")) != EOF) {
	switch(c) {
	case 'h':
	    arg_error = TRUE;
	    break;
	case 'n':
	    got_num_entries = TRUE;
	    num_entries = atoi(optarg);
	    break;
	case 'r':
	    num_repeat = atoi(optarg);
	    break;
	case 'p':
	    if(strcmp(optarg, "on") == 0) {
		show_proc = TRUE;
	    } else {
		show_proc = FALSE;
	    }	  
	    break;
	case 'i':
	    if(strcmp(optarg, "on") == 0) {
		show_idle = TRUE;
	    } else {
		show_idle = FALSE;
	    }	  
	    break;
	case 'q':
	    if(strcmp(optarg, "on") == 0) {
		show_quantum_expire = TRUE;
	    } else {
		show_quantum_expire = FALSE;
	    }	  
	    break;
	case 'c':
	    if(strcmp(optarg, "on") == 0) {
		show_cycles = TRUE;
	    } else {
		show_cycles = FALSE;
	    }	  
	    break;
	case 'l':
	    if(strcmp(optarg, "on") == 0) {
		show_location = TRUE;
	    } else {
		show_location = FALSE;
	    }	  
	    break;
	case 's':
	    if(strcmp(optarg, "on") == 0) {
		for_stat = TRUE;
	    } else {
		for_stat = FALSE;
	    }	  
	    break;
	case '?':
	default:
	    arg_error = TRUE;
	    break;
	}
    }

    if((arg_error == TRUE) || (got_num_entries == FALSE)) {
	printf("usage: lott_rinfo [-p<on|off>] [-i<on|off>] [-q<on|off>]\n"
	       "                  [-c<on|off>] [-s<on|off>] [-l<on|off>]\n"
	       "                  -n<num_entries> [-r<num_repeat>]\n"
	       "       -p controls process information\n"
	       "       -i controls idle information\n"
	       "       -q controls quantum expiration information\n"
	       "       -c controls cycle information\n"
	       "       -l controls location information\n"
	       "       (all of the previous options are on by default)\n"
	       "       -s clean output for statistical analysis "
	       "(default is off)\n"
	       "       -r specifies the number of times to repeat the run\n"
	       "       -n specifies the number of entries to record\n");
	exit(-1);
    }
}
