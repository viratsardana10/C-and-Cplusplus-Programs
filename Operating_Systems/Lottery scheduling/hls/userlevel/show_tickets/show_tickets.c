/* gcc -Wall -o show_tickets show_tickets.c -L../liblott -llott */

#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <kvm.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../liblott/liblott.h"

int main(int argc, char **argv);
void do_kvm(void);
void do_lott_info(void);
void kvm_show_tickets(void);
void print_info(struct lott_proc *lproc);
void parse_args(int argc, char **argv);

kvm_t *kd;
struct lott_global lottery;

pid_t pid;
uid_t uid;
bool just_runnable;
bool extra_info;

int
main(int argc, char **argv)
{
    parse_args(argc, argv);

    if(extra_info == TRUE) {
	printf("pid\tuid\trunning\ttickets\tt used\teff\tforce\tforce base\n");
    } else {
	printf("pid\tuid\ttickets\n");
    }

    /*do_kvm();*/
    do_lott_info();

    return 0;
}

void
do_kvm(void)
{
    char s[_POSIX2_LINE_MAX + 1];
    struct nlist nl[2];

    if((kd = kvm_openfiles(0, 0, 0, O_RDONLY, s)) == 0) {
	printf("kvm_openfiles: %s\n", s);
	exit(-1);
    }
    
    nl[0].n_name = "_lottery";
    nl[1].n_name = 0;
    
    if(kvm_nlist(kd, nl) != 0) {
	printf("kvm_nlist: %s\n", kvm_geterr(kd));
	exit(-1);
    }

    if(kvm_read(kd, nl[0].n_value, &lottery, sizeof(struct lott_global))
       != sizeof(struct lott_global)) {
	printf("kvm_read: %s\n", kvm_geterr(kd));
	exit(-1);
    }

    kvm_show_tickets();

    if(kvm_close(kd) == -1) {
        /* this is not exactly what we want to do, because errno isn't set
	   by kvm_close().  afaik, kvm_close() never errs... */
	perror("kvm_close()");
    }
}

void
kvm_show_tickets(void)
{
    int i;
    struct lott_proc *lproc;
    struct lproc_hash *lproc_hash_head;

    if((lproc = malloc(sizeof(struct lott_proc))) == 0) {
	printf("malloc() failure\n");
	exit(-1);
    }	
    lproc_hash_head = lottery.lproc_hash_head;
    if((lottery.lproc_hash_head =
	malloc(sizeof(struct lproc_hash) * lottery.lproc_hash_value)) == 0) {
	printf("malloc() failure\n");
	exit(-1);
    }
    if(kvm_read(kd, (int)lproc_hash_head,
		lottery.lproc_hash_head,
		sizeof(struct lproc_hash) * lottery.lproc_hash_value)
       != sizeof(struct lproc_hash) * lottery.lproc_hash_value) {
	printf("kvm_read: %s\n", kvm_geterr(kd));
	exit(-1);
    }
    for(i = 0; i <= lottery.lproc_hash_value; i++) {
	if(lottery.lproc_hash_head[i].lh_first == 0) {
	    continue;
	}
	if(kvm_read(kd, (int)lottery.lproc_hash_head[i].lh_first, lproc,
		    sizeof(struct lott_proc)) != sizeof(struct lott_proc)) {
	    printf("kvm_read: %s\n", kvm_geterr(kd));
	    exit(-1);
	}
	while(1) {
	    print_info(lproc);
	    
	    if(lproc->lproc_hash_entries.le_next == 0) {
		break;
	    }
	    if(kvm_read(kd, (int)lproc->lproc_hash_entries.le_next, lproc,
			sizeof(struct lott_proc))
	       != sizeof(struct lott_proc)) {
		printf("kvm_read: %s\n", kvm_geterr(kd));
		exit(-1);
	    }
	}
    }
}

void
do_lott_info(void)
{
    int num_elements, i;
    struct lott_proc *lproc;

    if((num_elements = lott_info(LPROC_INFO, 0, 0)) == -1) {
	perror("lott_info");
    }

    if((lproc = malloc(num_elements * sizeof(struct lott_proc))) == 0) {
	perror("malloc");
    }

    if((num_elements = lott_info(LPROC_INFO, (void *)lproc, num_elements))
       == -1) {
	perror("lott_info");
    }    

    for(i = 0; i < num_elements; i++) {
	print_info(&lproc[i]);
    }
}

void
print_info(struct lott_proc *lproc)
{
#define MAX_STR 80
    char force_str[MAX_STR + 1], running_str[MAX_STR + 1];

    if((uid != -1) && (uid != lproc->uid)) {
	return;
    }

    if((pid != -1) && (lproc->pid != pid)) {
	return;
    }

    if((just_runnable == TRUE) && (lproc->proc_state == LOTT_UNSCHED)) {
	return;
    }

    if(extra_info == TRUE) {
	switch(lproc->proc_state) {
	case LOTT_SCHED:
	    strcpy(running_str, "yes");
	    break;
	case LOTT_UNSCHED:
	    strcpy(running_str, "no");
	    break;
	}
	switch(lproc->force_sched) {
	case FORCE_NORMAL:
	    strcpy(force_str, "normal");
	    break;
	case FORCE_AT_LEAST:
	    strcpy(force_str, "least");
	    break;
	case FORCE_AT_MOST:
	    strcpy(force_str, "most");
	    break;
	}
	printf("%d\t%d\t%s\t%d\t%d\t(?)\t%s\t%d\n", lproc->pid, lproc->uid,
	       running_str, lproc->num_tickets, lproc->time_used, force_str,
	       (int)(lproc->force_sched_val_f64 >> FSHIFT_64));
    } else {
	printf("%d\t%d\t%d\n", lproc->pid, lproc->uid, lproc->num_tickets);
    }
}

void
parse_args(int argc, char **argv)
{
    char c;
    bool arg_error = FALSE;

    just_runnable = FALSE;
    extra_info = FALSE;
    uid = getuid();
    pid = -1;
    
    while((c = getopt(argc, argv, "hu:p:x")) != EOF) {
	switch(c) {
	case 'h':
	    arg_error = TRUE;
	    break;
/*	case 'r':
	    just_runnable = TRUE;
	    break;*/
	case 'u':
	    uid = atoi(optarg);
	    if((uid != getuid()) && (getuid() != 0)) {
		if(uid == -1) {
		    printf("You are not root.\n");
		} else {
		    printf("You are not uid %d or root.\n", uid);
		}
		exit(-1);
	    }		
	    break;
	case 'p':
	    pid = atoi(optarg);
	    break;
	case 'x':
	    extra_info = TRUE;
	    break;
	case '?':
	default:
	    arg_error = TRUE;
	    break;
	}
    }

    if(arg_error == TRUE) {
	printf("usage: show_tickets [-u<uid>] [-p<pid>] [-x]\n"
	       "       <uid> can be -1 for all users, the default is your "
	       "uid\n"
	       "       <pid> can be -1 for all procs, the default is "
	       "-1\n"
	       "       <-x> shows extra information\n");
	exit(-1);
    }
}
