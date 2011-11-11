/*
 * Copyright (c) 1996,1997,1998,1999 Carnegie Mellon University.
 * All rights reserved.
 *
 * Permission to use, copy, modify and distribute this software and
 * its documentation is hereby granted, provided that both the copyright
 * notice and this permission notice appear in all copies of the
 * software, derivative works or modified versions, and any portions
 * thereof, and that both notices appear in supporting documentation.
 *
 * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"
 * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND
 * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.
 *
 * Carnegie Mellon requests users of this software to return to
 *
 *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU
 *  School of Computer Science
 *  Carnegie Mellon University
 *  Pittsburgh PA 15213-3890
 *
 * any improvements or extensions that they make and grant Carnegie Mellon the
 * rights to redistribute these changes.
 */

#ifndef _SYS_LOTTERY_H_
#define _SYS_LOTTERY_H_

/*
 * expose to everyone
 */
#include <sys/param.h>

#define LOTT_DIAG /* comment out for better performance */

typedef u_int32_t ticket_t;

#define MAX_RUN_ORDER 10000

#define WINDOW_SIZE 10

typedef enum {
    LPROC_INFO,
    LUSER_INFO,
} lott_info_t;

typedef enum {
    RINFO_PROC,
    RINFO_IDLE,
    RINFO_QUANTUM_EXPIRE,
    RINFO_CYCLES,
    RINFO_LOCATION,
} lott_run_info;

struct lott_rorder {
    lott_run_info run_info;
    union {
	struct {
	    pid_t pid;
	    char stat;
	    u_char kern_priority;
	    uid_t uid;
	    char comm[MAXCOMLEN + 1];
	    unsigned int time_used;
	    ticket_t num_tickets;
	    ticket_t eff_tickets;
	    ticket_t base_tickets;
	    unsigned int utilization_f32;
	    unsigned int time_used_over_window_usec;
	    unsigned int time_deserved_over_window;
	    unsigned int runtime_sec;
	    unsigned int runtime_usec;
	    unsigned int dispatch_time;
	} rinfo_proc_u;
	struct {
#define FUNCTION_STRLEN 31
	    char function[FUNCTION_STRLEN + 1];
	    pid_t pid;
	    long long cycles;
	    int priority;
	} rinfo_cycles_u;
	struct {
	    pid_t pid;                          /* 4 */
	    char comm[MAXCOMLEN + 1];           /* 16 */
	    void *chan;                         /* 4 */
	    int pri;                            /* 4 */
#define WMESGLEN 7 /* this should not be here, but can't include user.h... */
	    char wmesg[WMESGLEN + 1];          /* 9 */
	    int timo;                           /* 4 */
	    char function[FUNCTION_STRLEN + 1]; /* 32 */
#define FILE_STRLEN 63
	    char file[FILE_STRLEN + 1];     /* 64 */
	    int line_num;                       /* 4 */
	    long long cycles_start;             /* 8 */
	    long long cycles_end;               /* 8 */
	} rinfo_location_u;                     /* tot: 157 */
    } rinfo_u;
#define rinfo_proc rinfo_u.rinfo_proc_u
#define rinfo_cycles rinfo_u.rinfo_cycles_u
#define rinfo_location rinfo_u.rinfo_location_u
};

#if defined(LOTT_INCLUDE) || !defined(KERNEL)

/*
 * visible to userlevel and lottery functions
 */
typedef boolean_t bool;
typedef u_int32_t fix32_t;
typedef u_int64_t fix64_t;

#define LOTT_SYSCALL_NUM 154
#define MAX_USER_TICKETS 100
#define MIN_USER_TICKETS 1
#define MAX_BASE_TICKETS 10000
#define MIN_BASE_TICKETS 100

#define FSHIFT_COMP 8
#define FSHIFT_CNR 12
#define FSHIFT_64 (FSHIFT_COMP + FSHIFT_CNR)

typedef enum {
    LOTT_SET_USER_TICKETS = 0,
    LOTT_STAT,
    LOTT_CTL,
    LOTT_CHUSER,
    LOTT_RUN_ORDER,
    LOTT_SET_BASE_TICKETS,
    LOTT_SET_FORCE,
    LOTT_INFO,
    LOTT_HANDOFF,
} lott_syscall;

typedef enum {
    LOTT_SCHED,
    LOTT_UNSCHED /* Sleeping/Stopped/Swapped out/Just switched to... */
} lott_proc_state;

typedef enum {
    FORCE_NORMAL,
    FORCE_AT_LEAST,
    FORCE_AT_MOST,
} force_sched_t;

struct lott_global {

    LIST_HEAD(lproc_hash, lott_proc) *lproc_hash_head;
    u_long lproc_hash_value;

    LIST_HEAD(run_list, lott_proc) run_list_head;
    LIST_HEAD(krun_list, lott_proc) krun_list_head;

    LIST_HEAD(luser_hash, lott_user) *luser_hash_head;
    u_long luser_hash_value;

    bool time_untrusted;

    unsigned int quantum_usecs;
    fix32_t quantum_usecs_f32;
    
    struct proc *last_proc;

#ifdef LOTT_DIAG
    bool print_stats;
    bool proc_stats;
    bool location_stats;
    bool cycle_stats;
    pid_t pid_stats;

    bool do_abbrev_quanta;
    bool do_kern_priority;

    bool do_rorder;
    struct lott_rorder rorder[MAX_RUN_ORDER];
    int rorder_request;
    int current_rorder;
#endif /* LOTT_DIAG */    

/* util stuff */
    ticket_t all_base;
    ticket_t window_all_base[WINDOW_SIZE];
    int window_all_base_loc;
    int window_time_used_loc;
    struct timeval current_time_used_timestamp;
};

struct lott_proc {
    struct proc *process;
    pid_t pid;  /* can be derived from process->p_pid, but here for speed. */
    uid_t uid;  /* likewise... */
    struct lott_user *luser;
    lott_proc_state proc_state;
    u_char kern_priority;
    ticket_t num_tickets;

    bool eff_valid;
    fix32_t eff_tickets_f32;

    bool base_tickets_valid;
    fix64_t base_tickets_f64; /* eff_tickets in base currency */

    force_sched_t force_sched;
    fix64_t force_sched_val_f64;

    unsigned int time_used;
  
    pid_t handoff_pid;

    LIST_ENTRY(lott_proc) run_list_entries;
    LIST_ENTRY(lott_proc) krun_list_entries;
    LIST_ENTRY(lott_proc) lproc_hash_entries;

    /* util */
    unsigned int window_time_used[WINDOW_SIZE];
    unsigned int last_time_used;
    struct timeval time_used_timestamp;
    fix32_t utilization_f32;
    int last_window_loc;
    bool is_sleeping_window;
    /* for rinfo */
    unsigned int time_used_over_window_usec_rinfo;
    unsigned int time_deserved_over_window_rinfo;
    struct timeval setrunqueue_time;
    unsigned int dispatch_time;
};

struct lott_user {
    uid_t uid;
    ticket_t runnable_user_tickets;
    fix32_t base_tickets_f32;
    ticket_t allowed_base_tickets;

    bool exchange_rate_valid;
    fix32_t exchange_rate_f32;

    bool running_proc_in_currency;

    unsigned int ref_count;

    LIST_ENTRY(lott_user) luser_hash_entries;

    /* util */
    ticket_t all_tickets;
    ticket_t window_all_tickets[WINDOW_SIZE];
    int window_all_tickets_loc;
};

#endif /* defined(LOTT_INCLUDE) || !defined(KERNEL) */

#ifdef KERNEL

/*
 * expose to kernel
 */
#ifdef LOTT_DIAG
extern int lott_store_rinfo_cycles(char *function, struct proc *p,
				   long long cycles);
static inline void
lott_cycle_counter(boolean_t start, char *function, struct proc *p)
{
    static unsigned long long start_cycles, end_cycles, diff_cycles;

/* *** calls to this function must be START, END; START, END... *** */

    if(start == TRUE) {
	asm volatile (".byte 0x0f, 0x31" : "=A" (start_cycles));
    } else {
	asm volatile (".byte 0x0f, 0x31" : "=A" (end_cycles));
	diff_cycles = end_cycles - start_cycles;
	lott_store_rinfo_cycles(function, p, diff_cycles);
    }
}
#else /* LOTT_DIAG */
#define lott_cycle_counter(foo, bar, baz)
#define lott_store_rinfo_cycles(foo, bar, baz)
#endif /* LOTT_DIAG */

extern void lott_sleep_util(pid_t pid);
extern int lott_init(void);
extern int lott_add_proc(struct proc *parent_proc, struct proc *process);
extern int lott_remove_proc(struct proc *process);
extern int lott_compensate(struct proc *p, struct timeval *tv);
extern int lott_should_resched(struct proc *p);
extern struct proc *lott_choose_next_runner(void);
extern void lott_do_util(void);
extern int lott_setuid(pid_t pid, uid_t uid);
extern int lott_trust_time(void);
extern int lott_pseudo_nice(struct proc *process);
extern void lott_loadav(struct loadavg *avg);
#ifdef LOTT_DIAG
extern int lott_store_rinfo_quantum_expire(void);
#else /* LOTT_DIAG */
#define lott_store_rinfo_quantum_expire()
#endif /* LOTT_DIAG */

#endif /* KERNEL */

#ifdef LOTT_INCLUDE

/*
 * local to kernel lottery
 */
#include <sys/proc.h>

#define LOTT_DEFAULT_TICKETS 10
#define LOTT_DEFAULT_BASE_PER_USER 1000

#define LOAD_SCALE_FACTOR 10

#define USECS_PER_SEC 1000000

#ifdef LOTT_DIAG
#define CHECK_LPROC(lproc, pid, function)                                   \
    if(lproc == 0) {                                                        \
        panic("%s: couldn't find pid %d", function, pid);                   \
    }
#define CHECK_LUSER(luser, uid, function)                                   \
    if(luser == 0) {                                                        \
        panic("%s: couldn't find uid %d", function, uid);                   \
    }
#else /* LOTT_DIAG */
#define CHECK_LPROC(foo, bar, baz)
#define CHECK_LUSER(foo, bar, baz)
#endif /* LOTT_DIAG */

#define	LPROC_HASH(pid)	(&lottery.lproc_hash_head[(pid) & \
						 lottery.lproc_hash_value])
#define	LUSER_HASH(uid)	(&lottery.luser_hash_head[(uid) & \
						 lottery.luser_hash_value])

/* nice + NICE_BIAS index the following array to get the correct base tickets
   for use in our "at most/at least" pseudo-nice algorithm.  These numbers are
   hard-coded rather than derived as needed because I didn't feel like
   encoding $y = 10^{\frac{1}{20}(-x + 20) + 2}$ in the kernel.  BTW,
   these numbers are truncated, not rounded; again because I feel like it. */
#define NICE_BIAS 20
ticket_t nice_to_base[] =
{ 10000, 8912, 7943, 7079, 6309, 5623, 5011, 4466, 3981, 3548,
  3162, 2818, 2511, 2238, 1995, 1778, 1584, 1412, 1258, 1122,
  1000, 891, 794, 707, 630, 562, 501, 446, 398, 354,
  316, 281, 251, 223, 199, 177, 158, 141, 125, 112, 100 };
ticket_t nice_to_user[] = { 100, 89, 79, 70, 63, 56, 50, 44, 39, 35,
			    31, 28, 25, 22, 19, 17, 15, 14, 12, 11,
			    10, 8, 7, 7, 6, 5, 5, 4, 3, 3,
			    3, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1 };

#endif /* LOTT_INCLUDE */

#if defined(KERNEL) && !defined(LOTTERY)
/* for profiling bsd... */
#ifdef LOTT_DIAG
extern int lott_store_rinfo_proc(struct proc *p, struct timeval *tv);
#else /* LOTT_DIAG */
#define lott_store_rinfo_proc(foo, bar);
#endif /* LOTT_DIAG */

#endif /*defined(KERNEL) && !defined(LOTTERY)*/

#endif /* !_SYS_LOTTERY_H_ */
