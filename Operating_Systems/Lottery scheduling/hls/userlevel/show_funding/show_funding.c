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
void kvm_show_funding(void);
void print_info(struct lott_user *luser);
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

    printf("uid\tbase tickets\n");

    /*    do_kvm();*/
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

    kvm_show_funding();

    if(kvm_close(kd) == -1) {
        /* this is not exactly what we want to do, because errno isn't set
	   by kvm_close().  afaik, kvm_close() never errs... */
	perror("kvm_close()");
    }
}

void
kvm_show_funding(void)
{
    int i;
    struct lott_user *luser;
    struct luser_hash *luser_hash_head;

    if((luser = malloc(sizeof(struct lott_user))) == 0) {
	printf("malloc() failure\n");
	exit(-1);
    }	
    luser_hash_head = lottery.luser_hash_head;
    if((lottery.luser_hash_head =
	malloc(sizeof(struct luser_hash) * lottery.luser_hash_value)) == 0) {
	printf("malloc() failure\n");
	exit(-1);
    }
    if(kvm_read(kd, (int)luser_hash_head,
		lottery.luser_hash_head,
		sizeof(struct luser_hash) * lottery.luser_hash_value)
       != sizeof(struct luser_hash) * lottery.luser_hash_value) {
	printf("kvm_read: %s\n", kvm_geterr(kd));
	exit(-1);
    }
    for(i = 0; i <= lottery.luser_hash_value; i++) {
	if(lottery.luser_hash_head[i].lh_first == 0) {
	    continue;
	}
	if(kvm_read(kd, (int)lottery.luser_hash_head[i].lh_first, luser,
		    sizeof(struct lott_user)) != sizeof(struct lott_user)) {
	    printf("kvm_read: %s\n", kvm_geterr(kd));
	    exit(-1);
	}
	while(1) {
	    print_info(luser);
	    
	    if(luser->luser_hash_entries.le_next == 0) {
		break;
	    }
	    if(kvm_read(kd, (int)luser->luser_hash_entries.le_next, luser,
			sizeof(struct lott_user))
	       != sizeof(struct lott_user)) {
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
    struct lott_user *luser;

    if((num_elements = lott_info(LUSER_INFO, 0, 0)) == -1) {
	perror("lott_info");
    }

    if((luser = malloc(num_elements * sizeof(struct lott_user))) == 0) {
	perror("malloc");
    }

    if((num_elements = lott_info(LUSER_INFO, (void *)luser, num_elements))
       == -1) {
	perror("lott_info");
    }    

    for(i = 0; i < num_elements; i++) {
	print_info(&luser[i]);
    }
}

void
print_info(struct lott_user *luser)
{
    if((uid != -1) && (uid != luser->uid)) {
	return;
    }

    printf("%d\t%d\n", luser->uid, luser->base_tickets_f32 >> FSHIFT_CNR);
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
    
    while((c = getopt(argc, argv, "hu:p:")) != EOF) {
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
	    /*	case 'x':
	    extra_info = TRUE;
	    break;*/
	case '?':
	default:
	    arg_error = TRUE;
	    break;
	}
    }

    if(arg_error == TRUE) {
        printf("usage: show_funding [-u<uid>]\n"
	       "       <uid> can be -1 for all users, default is your "
	       "uid\n");
        exit(-1);
    }
}
