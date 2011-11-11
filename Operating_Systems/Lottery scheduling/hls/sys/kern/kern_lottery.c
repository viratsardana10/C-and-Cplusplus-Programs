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

#include <sys/param.h>
#include <sys/kernel.h>
#include <sys/malloc.h>
#include <sys/queue.h>
#include <sys/proc.h>
#include <sys/signalvar.h>
#include <sys/sysproto.h>
#include <sys/systm.h>
#include <machine/cpu.h>
#include "opt_lottery.h"

#ifdef LOTTERY

#define LOTT_INCLUDE
#include <sys/lottery.h>

const char lott_version[] = "0.6";
struct lott_global lottery;

/* inline function declarations */
static inline u_quad_t umul32_64(u_long x, u_long y);
static inline u_long in_random(void);
static inline struct lott_proc *proc_find(pid_t pid);
static inline struct lott_user *user_find(uid_t uid);
static inline int adjust_user_sched(struct lott_proc *lproc);
static inline int adjust_user_unsched(struct lott_proc *lproc);
static inline int remrq_helper(struct lott_proc *lproc);
static inline int set_tickets(struct lott_proc *lproc, ticket_t num_tickets);

/* locally visible function declarations */
static int add_user(struct lott_proc *lproc);
static int user_decref(struct lott_proc *lproc);

/* syscall function declarations */
static int lott_set_user_tickets(struct proc *p, pid_t pid,
				 ticket_t num_tickets, int *retval);
#ifdef LOTT_DIAG
static int lott_stat(struct proc *p, bool print_stats, bool proc_stats,
		     bool cycle_stats, bool location_stats, pid_t pid,
		     int *retval);
static int lott_ctl(struct proc *p, bool do_abbrev_quanta,
		    bool do_kern_priority, int *retval);
static int lott_run_order(struct proc *p, struct lott_rorder *rorder_user,
			  int num_entries, int *retval);
static int store_rinfo_proc(struct lott_proc *lproc);
static int store_rinfo_idle(void);
static void check_finish_rorder(void);
static void comp_util(struct lott_proc *lproc);
#else /* LOTT_DIAG */
#define store_rinfo_proc(foo)
#define store_rinfo_idle()
#endif /* LOTT_DIAG */
static int lott_chuser(struct proc *p, pid_t pid, uid_t uid, int *retval);
static int lott_set_base_tickets(struct proc *p, uid_t uid,
				 ticket_t base_tickets, int *retval);
static int lott_set_force(struct proc *p, pid_t pid, force_sched_t force_sched,
				 ticket_t force_sched_val, int *retval);
static int lott_info(struct proc *p, lott_info_t lott_info, char *buffer,
		     int num_elements, int *retval);
static int lott_handoff(struct proc *p, pid_t pid_from, pid_t pid_to,
			int *retval);
/* debugging function declarations */
#ifdef LOTT_DIAG
static void lott_debug(void);
#endif /* LOTT_DIAG */

/* inline function definitions */
static inline u_quad_t
umul32_64(u_long x, u_long y) {
    u_quad_t res;
    
    asm volatile("mull %1" : "=A" (res) : "g" (y), "a" (x));

    return res;
}

static inline u_long
in_random(void)                 /* from libkern/random.c (this is inlined) */
{
    register long x, hi, lo, t;
    static u_long randseed = 1;

    x = randseed;
    hi = x / 127773;
    lo = x % 127773;
    t = 16807 * lo - 2836 * hi;
    if (t <= 0)
	t += 0x7fffffff;
    randseed = t;

    return (t);
}

static inline struct lott_proc *
proc_find(pid_t pid)
{
    struct lott_proc *lproc;
#ifdef LOTT_DIAG
    int loops = 0;
#endif /* LOTT_DIAG */

    for(lproc = LPROC_HASH(pid)->lh_first; lproc != 0;
	lproc = lproc->lproc_hash_entries.le_next) {
	if(pid == lproc->pid) {
#ifdef LOTT_DIAG
	    if(lottery.print_stats) {
		if((lottery.pid_stats == -1) || (lottery.pid_stats == pid)) {
/*		    printf("%s: loops = %d\n", __FUNCTION__, loops);*/
		}
	    }
#endif /* LOTT_DIAG */
	    return lproc;
	}
#ifdef LOTT_DIAG
	loops++;
#endif /* LOTT_DIAG */
    }

    return 0;
}

static inline struct lott_user *
user_find(uid_t uid)
{
    struct lott_user *luser;
#ifdef LOTT_DIAG
    int loops = 0;
#endif /* LOTT_DIAG */

    for(luser = LUSER_HASH(uid)->lh_first; luser != 0;
	luser = luser->luser_hash_entries.le_next) {
	if(uid == luser->uid) {
#ifdef LOTT_DIAG
	    if(lottery.print_stats) {
/*	        printf("%s: loops = %d\n", __FUNCTION__, loops);*/
	    }
#endif /* LOTT_DIAG */
	    return luser;
	}
#ifdef LOTT_DIAG
	loops++;
#endif /* LOTT_DIAG */
    }

    return 0;
}

static inline int
adjust_user_sched(struct lott_proc *lproc)
{
    lproc->luser->runnable_user_tickets += lproc->num_tickets;
    lproc->luser->exchange_rate_valid = FALSE;

    return 0;
}

static inline int
adjust_user_unsched(struct lott_proc *lproc)
{
    lproc->luser->runnable_user_tickets -= lproc->num_tickets;
    lproc->luser->exchange_rate_valid = FALSE;

    return 0;
}

static inline int
remrq_helper(struct lott_proc *lproc)
{
    lproc->proc_state = LOTT_UNSCHED;

#ifdef LOTT_DIAG
    if(lottery.do_kern_priority) {
#endif /* LOTT_DIAG */
	if(lproc->kern_priority < PUSER) {
	    LIST_REMOVE(lproc, krun_list_entries);
	} else {
	    LIST_REMOVE(lproc, run_list_entries);
	    adjust_user_unsched(lproc);
	}
#ifdef LOTT_DIAG
    } else {
	LIST_REMOVE(lproc, run_list_entries);
	adjust_user_unsched(lproc);
    }
#endif /* LOTT_DIAG */

    return 0;
}

static inline int
set_tickets(struct lott_proc *lproc, ticket_t num_tickets)
{
    ticket_t save_num_tickets;
    int s;

    save_num_tickets = lproc->num_tickets;

#ifdef LOTT_DIAG
    if(lottery.do_kern_priority) {
#endif /* LOTT_DIAG */
	if((lproc->proc_state == LOTT_SCHED) &&
	   (lproc->kern_priority >= PUSER)) {
	    adjust_user_unsched(lproc);
	    lproc->num_tickets = num_tickets;
	    adjust_user_sched(lproc);
	} else {
	    lproc->num_tickets = num_tickets;
	}
#ifdef LOTT_DIAG
    } else {
	if(lproc->proc_state == LOTT_SCHED) {
	    adjust_user_unsched(lproc);
	    lproc->num_tickets = num_tickets;
	    adjust_user_sched(lproc);
	} else {
	    lproc->num_tickets = num_tickets;
	}
    }
#endif /* LOTT_DIAG */

    s = splhigh();
    if(lproc->is_sleeping_window == FALSE) {
	lproc->luser->all_tickets -= save_num_tickets;
	lproc->luser->all_tickets += lproc->num_tickets;
    }
    splx(s);

    lproc->eff_valid = FALSE;

    return 0;
}

/* externally visible function definitions */
int
lott_init(void)
{
    int i;

    printf("initializing lottery scheduler %s, <dpetrou@cs.cmu.edu>\n",
	   lott_version);

    lottery.lproc_hash_head = hashinit(maxproc / 4, M_LOTTERY,
				 &lottery.lproc_hash_value);

    LIST_INIT(&lottery.run_list_head);
    LIST_INIT(&lottery.krun_list_head);

    lottery.luser_hash_head = hashinit(maxproc / 16, M_LOTTERY,
				 &lottery.luser_hash_value);

    lottery.time_untrusted = TRUE;

    lottery.quantum_usecs = USECS_PER_SEC / quantum;
    lottery.quantum_usecs_f32 = lottery.quantum_usecs << FSHIFT_COMP;
    
    lottery.last_proc = 0;

#ifdef LOTT_DIAG
    lottery.print_stats = FALSE;
    lottery.proc_stats = FALSE;
    lottery.cycle_stats = FALSE;
    lottery.location_stats = FALSE;
    lottery.pid_stats = -1;

    lottery.do_abbrev_quanta = TRUE;
    lottery.do_kern_priority = TRUE;

    lottery.do_rorder = FALSE;
    lottery.current_rorder = 0;
#endif /* LOTT_DIAG */

#ifdef LOTT_DIAG
    if(lottery.do_kern_priority) {
	printf("lott: kernel priorities on\n");
    } else {
	printf("lott: kernel priorities off\n");
    }
#endif /* LOTT_DIAG */

    lottery.all_base = 0;
    lottery.window_all_base_loc = 0;
    for(i = 0; i < WINDOW_SIZE; i++) {
	lottery.window_all_base[i] = LOTT_DEFAULT_BASE_PER_USER;
    }

    lottery.window_time_used_loc = 0;

    return 0;
}

int
lott_add_proc(struct proc *parent_proc, struct proc *process)
{
    struct lott_proc *parent_lproc, *lproc;
    int i;

    lproc = malloc(sizeof(struct lott_proc), M_LOTTERY, M_WAITOK);

    lproc->process = process;
    lproc->pid = process->p_pid;
    lproc->proc_state = LOTT_UNSCHED;

    if(parent_proc == 0) {
	lproc->num_tickets = LOTT_DEFAULT_TICKETS;
	lproc->uid = process->p_cred->p_ruid;
    } else {
	parent_lproc = proc_find(parent_proc->p_pid);
	CHECK_LPROC(parent_lproc, parent_proc->p_pid, __FUNCTION__);
	lproc->num_tickets = parent_lproc->num_tickets;
	lproc->uid = parent_lproc->uid;
    }

    lproc->kern_priority = process->p_priority;

    lproc->eff_valid = TRUE;
    lproc->eff_tickets_f32 = lproc->num_tickets << FSHIFT_COMP;

    lproc->base_tickets_valid = FALSE;
    /* no need to set base_tickets_f64, as it's set b4 used in CNR. */

    lproc->force_sched = FORCE_NORMAL;
    lproc->force_sched_val_f64 = (fix64_t)LOTT_DEFAULT_BASE_PER_USER
	<< FSHIFT_64;

/* can't set to time_used to 0 because if a set_tickets (from a nice) happens
   before the proc is scheduled for the first time, we set eff_valid to false.
   then CNR will recalculate the effective tickets with a 0 time_used,
   causing a divide fault... */
    lproc->time_used = lottery.quantum_usecs;

/* make -1 a #define some day... */
    lproc->handoff_pid = -1;

    LIST_INSERT_HEAD(LPROC_HASH(lproc->pid), lproc, lproc_hash_entries);

    for(i = 0; i < WINDOW_SIZE; i++) {
	lproc->window_time_used[i] = USECS_PER_SEC;
    }
    lproc->last_time_used = lottery.quantum_usecs;
    microtime(&lproc->time_used_timestamp);
    lproc->utilization_f32 = (1 << FSHIFT_COMP);
    lproc->last_window_loc = 0;

    add_user(lproc);

    lproc->is_sleeping_window = FALSE;

    if(process->p_nice != 0) {
        lott_pseudo_nice(process);
    }

    return 0;
}

int
lott_remove_proc(struct proc *process)
{
    struct lott_proc *lproc;
    int s;

    s = splhigh();

    lproc = proc_find(process->p_pid);
    CHECK_LPROC(lproc, process->p_pid, __FUNCTION__);

#ifdef LOTT_DIAG
    if(lproc->proc_state == LOTT_SCHED) {
	panic("%s: process on runqueue when it should not be", __FUNCTION__);
    }
#endif /* LOTT_DIAG */
    
    user_decref(lproc);

    LIST_REMOVE(lproc, lproc_hash_entries);
    free(lproc, M_LOTTERY);
    
    splx(s);
    return 0;
}

void
setrunqueue(struct proc *process)
{
    struct lott_proc *lproc, *search_lproc;
    int s;

    s = splhigh();

    lproc = proc_find(process->p_pid);
    CHECK_LPROC(lproc, process->p_pid, __FUNCTION__);

#ifdef LOTT_DIAG
    if(lproc->proc_state == LOTT_SCHED) {
	panic("%s: pid %d is already on runqueue", __FUNCTION__,
	      process->p_pid);
    }
#endif /* LOTT_DIAG */

    lproc->proc_state = LOTT_SCHED;

    lproc->kern_priority = process->p_priority;
#ifdef LOTT_DIAG
    if(lottery.do_kern_priority) {
#endif /* LOTT_DIAG */
	if(process->p_priority < PUSER) {
	    if(lottery.krun_list_head.lh_first == 0) {
		LIST_INSERT_HEAD(&lottery.krun_list_head, lproc,
				 krun_list_entries);
	    } else {
		for(search_lproc = lottery.krun_list_head.lh_first;
		    search_lproc != 0;
		    search_lproc = search_lproc->krun_list_entries.le_next) {
		    if(lproc->kern_priority < search_lproc->kern_priority) {
			LIST_INSERT_BEFORE(search_lproc, lproc,
					   krun_list_entries);
			break;
		    }
		    if(search_lproc->krun_list_entries.le_next == 0) {
			LIST_INSERT_AFTER(search_lproc, lproc,
					  krun_list_entries);
			break;
		    }
		}
	    }
	} else {
	    LIST_INSERT_HEAD(&lottery.run_list_head, lproc, run_list_entries);
	    adjust_user_sched(lproc);
	}
#ifdef LOTT_DIAG
    } else {
	LIST_INSERT_HEAD(&lottery.run_list_head, lproc, run_list_entries);
	adjust_user_sched(lproc);
    }
#endif /* LOTT_DIAG */

    if(lproc->is_sleeping_window == TRUE) {
	if(lproc->luser->all_tickets == 0) {
	    lottery.all_base += lproc->luser->base_tickets_f32 >> FSHIFT_CNR;
	}
	lproc->luser->all_tickets += lproc->num_tickets;
	lproc->is_sleeping_window = FALSE;
    }

/* take out when done! */
    microtime(&lproc->setrunqueue_time);

    splx(s);

    comp_util(lproc);
}

void
remrq(struct proc *process)
{
    struct lott_proc *lproc;
    int s;

    s = splhigh();

    lproc = proc_find(process->p_pid);
    CHECK_LPROC(lproc, process->p_pid, __FUNCTION__);

#ifdef LOTT_DIAG
    if(lproc->proc_state == LOTT_UNSCHED) {
	panic("%s: pid %d is not on runqueue", __FUNCTION__, process->p_pid);
    }
#endif /* LOTT_DIAG */

    remrq_helper(lproc);

    splx(s);
}

int
lott_compensate(struct proc *process, struct timeval *tv)
{
    struct lott_proc *lproc;
    int time_used;
    int s;

    /* used by handoff */
    lottery.last_proc = curproc;

    if(lottery.time_untrusted == TRUE) {
	time_used = lottery.quantum_usecs;
    } else {
	time_used = ((tv->tv_sec - runtime.tv_sec) * USECS_PER_SEC) +
	    (tv->tv_usec - runtime.tv_usec);
	if(time_used <= 0) {
#ifdef LOTT_DIAG
	    printf("%s: got negative time_used %d in pid %d\n", __FUNCTION__,
		   time_used, process->p_pid);
	    printf("%s (cont): %ld, %ld; prev: %ld, %ld\n", __FUNCTION__,
		   tv->tv_sec, tv->tv_usec, runtime.tv_sec, runtime.tv_usec);
#endif /* LOTT DIAG */
	    time_used = 1;
	}
    }
    
    s = splhigh();

    lproc = proc_find(process->p_pid);
    CHECK_LPROC(lproc, process->p_pid, __FUNCTION__);

    lproc->time_used += time_used;

    /* for util */
    lproc->last_time_used = time_used;
    lproc->time_used_timestamp.tv_usec = tv->tv_usec;
    lproc->time_used_timestamp.tv_sec = tv->tv_sec;

    if(lproc->time_used == 0) {
	/* this probably will never happen...  only if a process that spends
	   most of its time in the kernel will be able to overflow an int.
	   and even then, it will be unlikely to land exactly on 0.  and
	   even then, the only procs that will be able to do this will be
	   kernel threads, as other procs will get forced out when accruing
	   a quantum of time_used anyway.  and it really doesn't matter if
	   a kernel thread has 0 time_used as time_used will never be used
	   in a calculation in this case. */
#ifdef LOTT_DIAG
	printf("%s: lproc->time_used is 0 (time_used=%d, pid=%d)!  "
	       "tell dpetrou\n",
	       __FUNCTION__, time_used, lproc->pid);
#endif LOTT_DIAG
	lproc->time_used = 1;
    }

#ifdef LOTT_DIAG
    if(lottery.print_stats == TRUE) {
	if((lottery.pid_stats == -1) || (lottery.pid_stats == lproc->pid)) {
	    printf("%s: pid %d used %d usecs\n", __FUNCTION__, lproc->pid,
		   lproc->time_used);
	}
    }
#endif /* LOTT_DIAG */

    store_rinfo_proc(lproc);

    lproc->luser->running_proc_in_currency = FALSE;

    splx(s);
    return 0;
}

int
lott_should_resched(struct proc *p)
{
    unsigned int time_used;
    struct timeval tv;
    struct lott_proc *lproc;
    int s;

    s = splhigh();
#ifdef LOTT_DIAG
    if(lottery.do_abbrev_quanta == FALSE) {
	splx(s);
	return FALSE;
    }
#endif /* LOTT_DIAG */

#ifdef LOTT_DIAG
    if((lottery.do_kern_priority) && (lottery.krun_list_head.lh_first != 0)) {
#else /* LOTT_DIAG */
    if(lottery.krun_list_head.lh_first != 0) {
#endif /* LOTT_DIAG */
	splx(s);
	return TRUE;
    }

    /* now, what we really want to compare is p's base tickets with
       curproc's base tickets, but we don't have these values.  so instead,
       we compare how long they've run for... if we're wrong, nothing
       really bad happens, we just increase overhead by forcing a
       rescheduling event. */
    if(curproc != 0) {
	microtime(&tv); /* this is fast on a pentium or higher */
	/* there may be a chance that we calc. time_used after a process
	   is switched in, but before runtime is updated.  in that case,
	   we just switch when we probably shouldn't have.  no big deal. */
	time_used = ((tv.tv_sec - runtime.tv_sec) * USECS_PER_SEC) +
	    (tv.tv_usec - runtime.tv_usec);
	lproc = proc_find(p->p_pid);
	if(lproc->time_used < time_used) {
	    splx(s);
	    return TRUE;
	}
    }

    /* if there is no current proc, the interrupt that caused the wakeup()
       or whatever will cause lott_choose_next_runner() to be called */

    splx(s);
    return FALSE;
}

struct proc *
lott_choose_next_runner(void)
{
    struct lott_proc *lproc;
    struct lott_user *luser;
    fix32_t amount_deserved_f32;
    fix64_t total_base_tickets_f64 = 0;
    fix64_t winning_ticket_f64;
    fix64_t running_count_f64 = 0;
    union { fix32_t random_val_f32[2]; fix64_t random_val_f64; } random_u;

    /* take out when done! */
    struct timeval current_time;

    struct lott_proc *lproc_from, *lproc_to;
    if(lottery.last_proc != 0) {
	if((lproc_from = proc_find(lottery.last_proc->p_pid)) != 0) {
	    if(lproc_from->handoff_pid != -1) {
		if((lproc_to = proc_find(lproc_from->handoff_pid)) != 0) {
		    if(lproc_to->proc_state == LOTT_SCHED) {
			remrq_helper(lproc_to);

			lproc_to->luser->running_proc_in_currency = TRUE;

			microtime(&current_time);
			lproc_to->dispatch_time =
			    ((current_time.tv_sec -
			      lproc_to->setrunqueue_time.tv_sec) * USECS_PER_SEC) +
			    (current_time.tv_usec -
			     lproc_to->setrunqueue_time.tv_usec);

			return lproc_to->process;
		    }
		}
	    }
	}
    }


#ifdef LOTT_DIAG
    if(lottery.do_kern_priority) {
#endif /* LOTT_DIAG */
	if((lottery.krun_list_head.lh_first == 0) &&
	   (lottery.run_list_head.lh_first == 0)) {
	    store_rinfo_idle();
	    return 0;  /* the gimp's sleeping */	
	}
#ifdef LOTT_DIAG
    } else {
	if(lottery.run_list_head.lh_first == 0) {
	    store_rinfo_idle();
	    return 0;  /* the gimp's sleeping */
	}
    }
#endif /* LOTT_DIAG */

#ifdef LOTT_DIAG
    if(lottery.do_kern_priority) {
#endif /* LOTT_DIAG */
	lproc = lottery.krun_list_head.lh_first;
	if(lproc != 0) {
	    remrq_helper(lproc);
	    
	    if(lproc->time_used >= 10000) {
/*	    if(lproc->time_used >= lottery.quantum_usecs) { 100,000 */
	        need_resched();
	    }
	    
	    lproc->luser->running_proc_in_currency = TRUE;
	    
	    microtime(&current_time);
	    lproc->dispatch_time =
		((current_time.tv_sec - lproc->setrunqueue_time.tv_sec) *
		 USECS_PER_SEC) +
		(current_time.tv_usec -
		 lproc->setrunqueue_time.tv_usec);

	    return lproc->process;
	}
#ifdef LOTT_DIAG
    }
#endif /* LOTT_DIAG */

    for(lproc = lottery.run_list_head.lh_first; lproc != 0;
	lproc = lproc->run_list_entries.le_next) {
	luser = lproc->luser;

/* Following code works when FSHIFT_COMP = 8, FSHIFT_CNR = 12,
   FSHIFT_64 = 8 + 12, lottery.quantum_usecs = 100000, num_tickets
   ranging from 1 to 100, and base_tickets ranging from 100-10000.
   also, one user (procs in a currency) shouldn't have 4096 or more
   _runnable_ procs with 100 tickets each (this is an exceedingly rare
   event).  lastly, there is a system-wide limitation of 17,592
   runnable processes with maximum compensation (meaning that they
   blocked after using 1 microseconds of CPU time) and 100 tickets
   each.  this won't happen.  (and it's not hard to increase this
   last limit by scaling down the last multiply by min(FSHIFT_COMP,
   FSHIFT_CNR)... */

	if(lproc->utilization_f32 == (1 << FSHIFT_COMP)) {
	    if(lproc->eff_valid == FALSE) {
		lproc->eff_valid = TRUE;
		
		amount_deserved_f32 = lottery.quantum_usecs_f32 /
		    lproc->time_used;
		if(amount_deserved_f32 == 0) {
		    /* do i want to do this, or just set it equal to 1? */
		    amount_deserved_f32 = 1 << FSHIFT_COMP;
		}
		lproc->eff_tickets_f32 =
		    amount_deserved_f32 * lproc->num_tickets;
		
		lproc->base_tickets_valid = FALSE;
	    }
	} else {
	    lproc->eff_tickets_f32 = lproc->utilization_f32 *
		lproc->num_tickets;
	}

	if(luser->exchange_rate_valid == FALSE) {
	    luser->exchange_rate_valid = TRUE;

	    luser->exchange_rate_f32 = luser->base_tickets_f32 /
		luser->runnable_user_tickets;

	    lproc->base_tickets_valid = FALSE;
	}

	if(lproc->base_tickets_valid == FALSE) {
	    lproc->base_tickets_valid = TRUE;

	    lproc->base_tickets_f64 = umul32_64(luser->exchange_rate_f32,
						lproc->eff_tickets_f32);

	    if(lproc->force_sched != FORCE_NORMAL) {
		if((lproc->force_sched == FORCE_AT_LEAST) &&
		   (lproc->base_tickets_f64 < lproc->force_sched_val_f64)) {
		    lproc->base_tickets_f64 = lproc->force_sched_val_f64;
		} else {
		    if((lproc->force_sched == FORCE_AT_MOST) &&
		       (lproc->base_tickets_f64 >
			lproc->force_sched_val_f64)) {
			lproc->base_tickets_f64 = lproc->force_sched_val_f64;
		    }
		}
	    }
	}
	
	total_base_tickets_f64 += lproc->base_tickets_f64;
    }

    random_u.random_val_f32[0] = in_random();
    random_u.random_val_f32[1] = in_random();

    winning_ticket_f64 = random_u.random_val_f64 % total_base_tickets_f64;
    
    for(lproc = lottery.run_list_head.lh_first; lproc != 0;
	lproc = lproc->run_list_entries.le_next) {
	running_count_f64 += lproc->base_tickets_f64;
	if(running_count_f64 > winning_ticket_f64) {
	    remrq_helper(lproc);

	    lproc->eff_valid = FALSE;
	    lproc->time_used = 0;
	    
	    lproc->luser->running_proc_in_currency = TRUE;

	    microtime(&current_time);
	    lproc->dispatch_time =
		((current_time.tv_sec - lproc->setrunqueue_time.tv_sec) *
		 USECS_PER_SEC) +
		(current_time.tv_usec -
		 lproc->setrunqueue_time.tv_usec);
	    
	    return lproc->process;
	}
    }
    
    panic("%s: couldn't find process (random: %d)", __FUNCTION__,
	  (int)winning_ticket_f64);
    return 0;
}

/*--*/
void
comp_util(struct lott_proc *lproc)
{
/* using FSHIFT_CNR for 64 bit... */
    struct timeval tv;
    int elapsed;
    int count;
    unsigned int time_used_over_window_usec;
    int index;
    bool zero = FALSE;
    int i;
    struct lott_user *luser;
    fix64_t exchange_rate_f32;
    fix64_t temp;
    fix64_t time_deserved_over_window_f64;
    int scale = 1;

/* update time window for proc */
    if(lottery.time_untrusted == TRUE) {
	elapsed = 0;
    } else {
	elapsed = lottery.current_time_used_timestamp.tv_sec -
	    lproc->time_used_timestamp.tv_sec;
	if(elapsed < 0) {
	    elapsed = 0;
	}
    }
    if(elapsed >= WINDOW_SIZE) {
	elapsed = WINDOW_SIZE;
	zero = TRUE;
    }
    index = lottery.window_time_used_loc;
    count = elapsed;
    while(count) {
	lproc->window_time_used[index] = 0;
	index--;
	if(index < 0) {
	    index = WINDOW_SIZE - 1;
	}
	count--;
    }
    if(zero == FALSE) {
	if(index != lproc->last_window_loc) {
	    lproc->window_time_used[index] = 0;
	}
	lproc->window_time_used[index] += lproc->last_time_used;
	lproc->last_window_loc = index;
    }

/* compute time over window */
    time_used_over_window_usec = 0;
    for(i = 0; i < WINDOW_SIZE; i++) {
	time_used_over_window_usec += lproc->window_time_used[i];
    }

    /* by this time we have a time used over window interval...  now
       compute utilization...  first see how long it should have run
       for over the interval.  */

    luser = lproc->luser;
    if(zero) {
	lproc->utilization_f32 = lottery.quantum_usecs_f32;
    } else {
	time_deserved_over_window_f64 = 0;
	for(i = 0; i < WINDOW_SIZE; i++) {
	    /* code assumes that lproc->num_tickets and
               luser->base_tickets_f32 change less than once every
               WINDOW_SIZE seconds. */
	    if(luser->window_all_tickets[i] == 0) {
		continue;
	    }
	    exchange_rate_f32 = luser->base_tickets_f32 /
		luser->window_all_tickets[i];
	    if(lottery.window_all_base[i] == 0) {
		continue;
	    }
	    time_deserved_over_window_f64 += (fix64_t)exchange_rate_f32 /
		(fix64_t)lottery.window_all_base[i];
	}
	time_deserved_over_window_f64 *=
	    (fix64_t)lproc->num_tickets * (fix64_t)USECS_PER_SEC;

	if(time_used_over_window_usec == 0) {
	    printf("huh?3\n");
	    time_used_over_window_usec = 1;
	}
	temp = ((time_deserved_over_window_f64 /** (fix64_t)scale*/) /
		(fix64_t)time_used_over_window_usec)
		    >> (FSHIFT_CNR - FSHIFT_COMP);

	temp *= temp;
	temp >>= FSHIFT_COMP;
	temp *= temp;
	temp >>= FSHIFT_COMP;
	
	if(temp > (1 << FSHIFT_COMP)) {
	    if(temp < (1000 << FSHIFT_COMP)) {
		temp = (1000 << FSHIFT_COMP);
	    }
	}

	if(temp > lottery.quantum_usecs_f32) {
	    temp = lottery.quantum_usecs_f32;
	}
	lproc->utilization_f32 = temp;
	if(lproc->utilization_f32 < (1 << FSHIFT_COMP)) {
	    lproc->utilization_f32 = (1 << FSHIFT_COMP);
	}
    }

    lproc->time_used_over_window_usec_rinfo =
	time_used_over_window_usec;
    lproc->time_deserved_over_window_rinfo =
	time_deserved_over_window_f64 >> FSHIFT_CNR;

#ifdef LOTT_DIAG
    if(lottery.print_stats) {
	if((lottery.pid_stats == -1) || (lottery.pid_stats == lproc->pid)) {
	    printf("%s: pid: %d, util32: %d, tused: %d, tdesv: %d\n",
		   __FUNCTION__, lproc->pid, lproc->utilization_f32,
		   time_used_over_window_usec,
		   time_deserved_over_window_f64 >> FSHIFT_CNR);
	    printf("--elap: %d, last_used: %d, loc: %d, index: %d\n", elapsed,
		   lproc->last_time_used, lottery.window_time_used_loc,
		   index);
	}
    }
#endif /* LOTT_DIAG */
}

void
lott_sleep_util(pid_t pid)
{
    struct lott_proc *lproc;
    int s;

    lproc = proc_find(pid);
    CHECK_LPROC(lproc, pid, __FUNCTION__);

    s = splhigh();
    if(lproc->proc_state == LOTT_UNSCHED) {
	lproc->is_sleeping_window = TRUE;
	lproc->luser->all_tickets -= lproc->num_tickets;
	if(lproc->luser->all_tickets == 0) {
	    lottery.all_base -= lproc->luser->base_tickets_f32 >> FSHIFT_CNR;
	}
    }
    splx(s);
}

void
lott_do_util(void)
{    
    int i, j, count, index;
    struct lott_proc *lproc;
    struct lott_user *luser;
    unsigned int time_used;

/* don't think i need synchronization, since i'm going through all
   users, and this list only changes on add_user, dec_ref, which
   aren't called from ints */

/* update time_loc location */
    lottery.window_time_used_loc++;
    if(lottery.window_time_used_loc == WINDOW_SIZE) {
	lottery.window_time_used_loc = 0;
    }
    microtime(&lottery.current_time_used_timestamp);

/* update total base in system */
    lottery.window_all_base[lottery.window_all_base_loc] =
	lottery.all_base;
    lottery.window_all_base_loc++;
    if(lottery.window_all_base_loc == WINDOW_SIZE) {
	lottery.window_all_base_loc = 0;
    }

/* do the same for each user */
    for(i = 0; i <= lottery.luser_hash_value; i++) {
	for(luser = lottery.luser_hash_head[i].lh_first; luser != 0;
	    luser = luser->luser_hash_entries.le_next) {

	    luser->window_all_tickets[luser->window_all_tickets_loc] =
		luser->all_tickets;
	    luser->window_all_tickets_loc++;
	    if(luser->window_all_tickets_loc == WINDOW_SIZE) {
		luser->window_all_tickets_loc = 0;
	    }
	}
    }
}
/*--*/

int
lott_setuid(pid_t pid, uid_t uid)
{
    struct lott_proc *lproc;
    int s;
    
    s = splhigh();
    lproc = proc_find(pid);
    CHECK_LPROC(lproc, pid, __FUNCTION__);

    user_decref(lproc);
    lproc->uid = uid;
    add_user(lproc);

    splx(s);
    return 0;
}

int
lott_trust_time(void)
{
    lottery.time_untrusted = FALSE;
    microtime(&lottery.current_time_used_timestamp);

    return 0;
}

int
lott_pseudo_nice(struct proc *process)
{
    struct lott_proc *lproc;
    int s;

    s = splhigh();

    lproc = proc_find(process->p_pid);
    CHECK_LPROC(lproc, process->p_pid, __FUNCTION__);

    if(process->p_nice == 0) {
	lproc->force_sched = FORCE_NORMAL;
    }

    if(process->p_nice > 0) {
	lproc->force_sched = FORCE_AT_MOST;
    }

    if(process->p_nice < 0) {
	lproc->force_sched = FORCE_AT_LEAST;
    }

    lproc->force_sched_val_f64 = (fix64_t)nice_to_base[process->p_nice +
						      NICE_BIAS] << FSHIFT_64;
    
    lproc->base_tickets_valid = FALSE;

    set_tickets(lproc, nice_to_user[process->p_nice + NICE_BIAS]);

    splx(s);
    return 0;
}

void
lott_loadav(struct loadavg *avg)
{
  /*    int total_base_tickets = 0;*/
    struct lott_user *luser;
    int i;
    int instant_load = 0;
    fix32_t instant_load_f32;
    struct lott_proc *lproc;
    fixpt_t cexp[3] = {
	0.9200444146293232 * FSCALE,	/* exp(-1/12) */
	0.9834714538216174 * FSCALE,	/* exp(-1/60) */
	0.9944598480048967 * FSCALE,	/* exp(-1/180) */
    };

  /* so we iterate through all user structs.  not so bad considering
     that the original loadav() iterated through all processes in the
     system */

    for(i = 0; i <= lottery.luser_hash_value; i++) {
	for(luser = lottery.luser_hash_head[i].lh_first; luser != 0;
	    luser = luser->luser_hash_entries.le_next) {
	    if((luser->runnable_user_tickets > 0) ||
	       (luser->running_proc_in_currency == TRUE)){
	        instant_load++;
	      /*total_base_tickets += luser->base_tickets_f32 >> FSHIFT_CNR; */
	    }
	}
    }

/* make sure no overflow...  it's fine with LOTT_DEFAULT_BASE_PER_USER
   = 1000 and LOAD_SCALE_FACTOR of 10... */

    /* instant_load_f32 = (LOAD_SCALE_FACTOR << FSHIFT) -
       (((LOTT_DEFAULT_BASE_PER_USER * LOAD_SCALE_FACTOR) << FSHIFT) /
       (total_base_tickets + LOTT_DEFAULT_BASE_PER_USER));*/
    instant_load_f32 = instant_load * FSCALE;

    for (i = 0; i < 3; i++) {
	avg->ldavg[i] = (cexp[i] * avg->ldavg[i] +
			 instant_load_f32 * (FSCALE - cexp[i])) >> FSHIFT;
    }    
}

/* locally visible function definitions */
static int
add_user(struct lott_proc *lproc)
{
    struct lott_user *luser;
    int i;

    if((luser = user_find(lproc->uid)) == 0) {
	luser = malloc(sizeof(struct lott_user), M_LOTTERY, M_WAITOK);
	LIST_INSERT_HEAD(LUSER_HASH(lproc->uid), luser, luser_hash_entries);
	luser->uid = lproc->uid;
	luser->runnable_user_tickets = 0;
	luser->base_tickets_f32 = LOTT_DEFAULT_BASE_PER_USER << FSHIFT_CNR;
	luser->allowed_base_tickets = LOTT_DEFAULT_BASE_PER_USER;
	luser->exchange_rate_valid = FALSE;
	luser->running_proc_in_currency = FALSE;
	/* not setting exchange_rate_f32 since it will be later, b4 use... */
	luser->ref_count = 0;

	luser->all_tickets = 0;
	luser->window_all_tickets_loc = 0;
	for(i = 0; i < WINDOW_SIZE; i++) {
	    luser->window_all_tickets[i] = LOTT_DEFAULT_TICKETS;
	}
	
#ifdef LOTT_DIAG
	if(lottery.print_stats == TRUE) {
	    printf("%s: added user %d\n", __FUNCTION__, luser->uid);
	}
#endif /* LOTT_DIAG */
    }

    lproc->luser = luser;

#ifdef LOTT_DIAG
    if(lottery.do_kern_priority) {
#endif /* LOTT_DIAG */
	if((lproc->proc_state == LOTT_SCHED) &&
	   (lproc->kern_priority >= PUSER)) {
	    adjust_user_sched(lproc);
	}
#ifdef LOTT_DIAG
    } else {
	if(lproc->proc_state == LOTT_SCHED) {
	    adjust_user_sched(lproc);
	}
    }
#endif /* LOTT_DIAG */

    luser->ref_count++;

    if(luser->all_tickets == 0) {
	lottery.all_base += luser->base_tickets_f32 >> FSHIFT_CNR;
    }
    luser->all_tickets += lproc->num_tickets;

    return 0;
}

static int
user_decref(struct lott_proc *lproc)
{
    struct lott_user *luser;
    
    luser = lproc->luser;

#ifdef LOTT_DIAG
    if(lottery.do_kern_priority) {
#endif /* LOTT_DIAG */
	if((lproc->proc_state == LOTT_SCHED) &&
	   (lproc->kern_priority >= PUSER)) {
	    adjust_user_unsched(lproc);
	}
#ifdef LOTT_DIAG
    } else {
	if(lproc->proc_state == LOTT_SCHED) {
	    adjust_user_unsched(lproc);
	}
    }
#endif /* LOTT_DIAG */

    luser->ref_count--;

    if(lproc->is_sleeping_window == FALSE) {
	luser->all_tickets -= lproc->num_tickets;
	if(luser->all_tickets == 0) {
	    lottery.all_base -= luser->base_tickets_f32 >> FSHIFT_CNR;
	}
    }

    if(luser->ref_count == 0) {
	LIST_REMOVE(luser, luser_hash_entries);
	free(luser, M_LOTTERY);
#ifdef LOTT_DIAG
	if(lottery.print_stats == TRUE) {
	    printf("%s: removed user %d\n", __FUNCTION__, lproc->uid);
	}
#endif /* LOTT_DIAG */
    }

    return 0;
}

/* syscall function definitions */
int
lott_sched(struct proc *p, struct lott_sched_args *uap, int *retval)
{
    int rval;

    switch(uap->which) {
    case LOTT_SET_USER_TICKETS:
	rval = lott_set_user_tickets(p, uap->a1, uap->a2, retval);
	break;
#ifdef LOTT_DIAG
    case LOTT_STAT:
	rval = lott_stat(p, uap->a1, uap->a2, uap->a3, uap->a4, uap->a5,
			 retval);
	break;
    case LOTT_CTL:
	rval = lott_ctl(p, uap->a1, uap->a2, retval);
	break;
    case LOTT_RUN_ORDER:
	rval = lott_run_order(p, (struct lott_rorder *)uap->a1, uap->a2,
			      retval);
	break;
#endif /* LOTT_DIAG */
    case LOTT_CHUSER:
	rval = lott_chuser(p, uap->a1, uap->a2, retval);
	break;
    case LOTT_SET_BASE_TICKETS:
	rval = lott_set_base_tickets(p, uap->a1, uap->a2, retval);
	break;
    case LOTT_SET_FORCE:
	rval = lott_set_force(p, uap->a1, uap->a2, uap->a3, retval);
	break;
    case LOTT_INFO:
	rval = lott_info(p, uap->a1, (char *)uap->a2, uap->a3, retval);
	break;
    case LOTT_HANDOFF:
	rval = lott_handoff(p, uap->a1, uap->a2, retval);
	break;
    default:
	rval = -1;
	psignal(p, SIGSYS);
	*retval = EINVAL;
	break;
    }

    if(rval == -1) {
	return *retval;
    } else {
	return 0;
    }
}

int
lott_set_user_tickets(struct proc *p, pid_t pid, ticket_t num_tickets,
		      int *retval)
{
    struct lott_proc *lproc;
    ticket_t save_num_tickets;
    int s;

    s = splhigh();

    if((lproc = proc_find(pid)) == 0) {
	*retval = ESRCH;

	splx(s);
	return -1;
    }
	
    if((suser(p->p_cred->pc_ucred, 0) != 0) &&
       (p->p_cred->pc_ucred->cr_uid != lproc->uid)) {
	*retval = EPERM;

	splx(s);
	return -1;
    }

    if((num_tickets < MIN_USER_TICKETS) || (num_tickets > MAX_USER_TICKETS)) {
	*retval = EDOM;

	splx(s);
	return -1;
    }

    save_num_tickets = lproc->num_tickets;

    set_tickets(lproc, num_tickets);
    
    *retval = save_num_tickets;

    splx(s);
    return 0;
}

#ifdef LOTT_DIAG
int
lott_stat(struct proc *p, bool print_stats, bool proc_stats, bool cycle_stats,
	  bool location_stats, pid_t pid, int *retval)
{
    if(suser(p->p_cred->pc_ucred, 0) != 0) {
	*retval = EPERM;

	return -1;
    }

    if(pid != -1) {
	if(pfind(pid) == 0) {
	    *retval = ESRCH;
	    return -1;
	}
    }
    lottery.pid_stats = pid;

/* paranoia ON */
    if(print_stats) {
	lottery.print_stats = TRUE;
    } else {
	lottery.print_stats = FALSE;
    }

    if(proc_stats) {
	lottery.proc_stats = TRUE;
    } else {
	lottery.proc_stats = FALSE;
    }

    if(cycle_stats) {
	lottery.cycle_stats = TRUE;
    } else {
	lottery.cycle_stats = FALSE;
    }

    if(location_stats) {
	lottery.location_stats = TRUE;
    } else {
	lottery.location_stats = FALSE;
    }
/* paranoia OFF */

    if(lottery.print_stats || lottery.proc_stats || lottery.cycle_stats ||
       lottery.location_stats) {
	printf("%s: --- lottery logging <on> ---\n", __FUNCTION__);
    }

    *retval = 0;
    return 0;
}

int
lott_ctl(struct proc *p, bool do_abbrev_quanta, bool do_kern_priority,
	 int *retval)
{
    if(suser(p->p_cred->pc_ucred, 0) != 0) {
	*retval = EPERM;

	return -1;
    }

/* paranoia ON */
    if(do_abbrev_quanta) {
	lottery.do_abbrev_quanta = TRUE;
    } else {
	lottery.do_abbrev_quanta = FALSE;
    }

/*  before we can use this code, we have to write something to
    move procs from the kern list to the standard list...
    if(do_kern_priority) {
	lottery.do_kern_priority = TRUE;
    } else {
	lottery.do_kern_priority = FALSE;
    }
    */
/* paranoia OFF */

    if(lottery.do_abbrev_quanta) {
	printf("%s: --- abbreviated quanta on ---\n", __FUNCTION__);
    } else {
	printf("%s: --- abbreviated quanta off ---\n", __FUNCTION__);	
    }

    /*    if(lottery.do_kern_priority) {
	printf("%s: --- kernel priorities on ---\n", __FUNCTION__);
    } else {
	printf("%s: --- kernel priorities off ---\n", __FUNCTION__);	
    }*/

    *retval = 0;
    return 0;
}

int
lott_run_order(struct proc *p, struct lott_rorder *rorder_user,
	       int rorder_request, int *retval)
{
    int error;

    if(suser(p->p_cred->pc_ucred, 0) != 0) {
	*retval = EPERM;
	return -1;
    }

    if((lottery.cycle_stats == FALSE) && (lottery.proc_stats == FALSE) &&
       (lottery.location_stats == FALSE)) {
	*retval = EAGAIN;
	return -1;
    }

    if(rorder_request > MAX_RUN_ORDER) {
	rorder_request = MAX_RUN_ORDER;
    }

    if(rorder_request < 1) {
	*retval = EINVAL;
	return -1;
    }

    if(lottery.do_rorder == TRUE) {
	*retval = EBUSY;
	return -1;
    }

    lottery.do_rorder = TRUE;

    /* *** if there's an interrupt here that inserts something into the
       rinfo struct and then determines that it's time to wake us up, we
       experience the lost-wakeup problem...  the right thing to do is
       splhigh() here, then splx() after the tsleep()...  confirm this. *** */

    lottery.rorder_request = rorder_request;

    if((error = TSLEEP(lottery.rorder, PUSER | PCATCH, "r_order", 0)) != 0) {
	lottery.current_rorder = 0;
	lottery.do_rorder = FALSE;

	*retval = error;
	return -1;
    }

    if((error = copyout(lottery.rorder, rorder_user,
			sizeof(struct lott_rorder) * rorder_request)) != 0) {
	*retval = error;
	return -1;
    }
    
    *retval = rorder_request;
    return 0;
}

static void
check_finish_rorder(void)
{
/* callers to this function must be serialized */
    lottery.current_rorder++;
    if(lottery.current_rorder == lottery.rorder_request) {
	lottery.current_rorder = 0;
	lottery.do_rorder = FALSE;
	wakeup(lottery.rorder);
    }
}

int
store_rinfo_idle(void)
{
    int s;

    if(lottery.do_rorder == FALSE) {
	return 0;
    }

    if(lottery.proc_stats == FALSE) {
	return 0;
    }

    s = splhigh();

    if((lottery.current_rorder > 0) &&
       (lottery.rorder[lottery.current_rorder - 1].run_info == RINFO_IDLE)) {
	splx(s);
        return 0;
    }

    lottery.rorder[lottery.current_rorder].run_info = RINFO_IDLE;

    check_finish_rorder();
 
    splx(s);
    return 0;
}

int
lott_store_rinfo_quantum_expire(void)
{
    int s;

    if(lottery.do_rorder == FALSE) {
	return 0;
    }
    
    if(lottery.proc_stats == FALSE) {
	return 0;
    }

    s = splhigh();

    lottery.rorder[lottery.current_rorder].run_info = RINFO_QUANTUM_EXPIRE;

    check_finish_rorder();

    splx(s);
    return 0;
}

int
store_rinfo_proc(struct lott_proc *lproc)
{
    int s;

    if(lottery.do_rorder == FALSE) {
	return 0;
    }
    
    if(lottery.proc_stats == FALSE) {
	return 0;
    }

    if((lottery.pid_stats != -1) && (lottery.pid_stats != lproc->pid)) {
	return 0;
    }

    s = splhigh();

    lottery.rorder[lottery.current_rorder].run_info = RINFO_PROC;
    lottery.rorder[lottery.current_rorder].rinfo_proc.pid = lproc->pid;
    lottery.rorder[lottery.current_rorder].rinfo_proc.stat =
	lproc->process->p_stat;
    lottery.rorder[lottery.current_rorder].rinfo_proc.kern_priority =
	lproc->kern_priority;
    lottery.rorder[lottery.current_rorder].rinfo_proc.uid = lproc->uid;
    if(lproc->process->p_comm != 0) {
	strcpy(lottery.rorder[lottery.current_rorder].rinfo_proc.comm,
	       lproc->process->p_comm);
    } else {
	strcpy(lottery.rorder[lottery.current_rorder].rinfo_proc.comm, "<?>");
    }
    lottery.rorder[lottery.current_rorder].rinfo_proc.time_used =
	lproc->time_used;
    lottery.rorder[lottery.current_rorder].rinfo_proc.num_tickets =
	lproc->num_tickets;
/* the following values are not calculated until CNR now, so they are stale */
    lottery.rorder[lottery.current_rorder].rinfo_proc.eff_tickets =
	lproc->eff_tickets_f32 >> FSHIFT_COMP;
    lottery.rorder[lottery.current_rorder].rinfo_proc.base_tickets =
	lproc->base_tickets_f64 >> FSHIFT_64;

    lottery.rorder[lottery.current_rorder].rinfo_proc.utilization_f32 =
	lproc->utilization_f32;
    lottery.rorder[lottery.current_rorder].rinfo_proc.time_used_over_window_usec =
	lproc->time_used_over_window_usec_rinfo;
    lottery.rorder[lottery.current_rorder].rinfo_proc.time_deserved_over_window =
	lproc->time_deserved_over_window_rinfo;

    lottery.rorder[lottery.current_rorder].rinfo_proc.runtime_sec =
	runtime.tv_sec;
    lottery.rorder[lottery.current_rorder].rinfo_proc.runtime_usec =
	runtime.tv_usec;
    lottery.rorder[lottery.current_rorder].rinfo_proc.dispatch_time =
	lproc->dispatch_time;

    check_finish_rorder();

    splx(s);
    return 0;
}

int
lott_store_rinfo_cycles(char *function, struct proc *p, long long cycles)
{
    int s;

    if(lottery.do_rorder == FALSE) {
	return 0;
    }
    
    if(lottery.cycle_stats == FALSE) {
	return 0;
    }

    if((lottery.pid_stats != -1) && (lottery.pid_stats != p->p_pid)) {
	return 0;
    }

    s = splhigh();

    lottery.rorder[lottery.current_rorder].run_info = RINFO_CYCLES;
    strncpy(lottery.rorder[lottery.current_rorder].rinfo_cycles.function,
	    function, FUNCTION_STRLEN);
    /* need the next line in case __FUNCTION__ is greater than 31... */
    lottery.rorder[lottery.current_rorder].
	rinfo_cycles.function[FUNCTION_STRLEN] = 0;
    lottery.rorder[lottery.current_rorder].rinfo_cycles.pid = p->p_pid;
    lottery.rorder[lottery.current_rorder].rinfo_cycles.cycles = cycles;    
    lottery.rorder[lottery.current_rorder].rinfo_cycles.priority =
	p->p_priority;

    check_finish_rorder();

    splx(s);

    return 0;
}

int
lott_store_rinfo_location(void *chan, int pri, char *wmesg, int timo,
			  char *file, char *function, int line)
{
    long long cycles_start, cycles_end;
    int ts_ret;
    int s;

    cycles_start = rdtsc();

    ts_ret = TSLEEP(chan, pri, wmesg, timo);

    if(lottery.do_rorder == FALSE) {
	return ts_ret;
    }

    if(lottery.location_stats == FALSE) {
	return ts_ret;
    }

    cycles_end = rdtsc();

    s = splhigh();

    lottery.rorder[lottery.current_rorder].run_info = RINFO_LOCATION;
    lottery.rorder[lottery.current_rorder].rinfo_location.pid = curproc->p_pid;
    if(curproc->p_comm != 0) {
	strcpy(lottery.rorder[lottery.current_rorder].rinfo_location.comm,
	       curproc->p_comm);
    } else {
	strcpy(lottery.rorder[lottery.current_rorder].rinfo_location.comm,
	       "<?>");
    }
    lottery.rorder[lottery.current_rorder].rinfo_location.chan = chan;
    lottery.rorder[lottery.current_rorder].rinfo_location.pri = pri;
    strncpy(lottery.rorder[lottery.current_rorder].rinfo_location.wmesg,
	    wmesg, WMESGLEN);
    lottery.rorder[lottery.current_rorder].rinfo_location.wmesg[WMESGLEN] = 0;
    lottery.rorder[lottery.current_rorder].rinfo_location.timo = timo;
    strncpy(lottery.rorder[lottery.current_rorder].rinfo_location.function,
	    function, FUNCTION_STRLEN);
    lottery.rorder[lottery.current_rorder].rinfo_location.
	function[FUNCTION_STRLEN] = 0;
    strncpy(lottery.rorder[lottery.current_rorder].rinfo_location.file,
	    file, FILE_STRLEN);
    lottery.rorder[lottery.current_rorder].rinfo_location.
	file[FILE_STRLEN] = 0;
    lottery.rorder[lottery.current_rorder].rinfo_location.line_num = line;
    lottery.rorder[lottery.current_rorder].rinfo_location.cycles_start =
	cycles_start;
    lottery.rorder[lottery.current_rorder].rinfo_location.cycles_end =
	cycles_end;

    check_finish_rorder();

    splx(s);

    return ts_ret;
}
#else /* LOTT_DIAG */
int
lott_store_rinfo_location(void *chan, int pri, char *wmesg, int timo,
			  char *file, char *function, int line)
{
    return TSLEEP(chan, pri, wmesg, timo);   
}
#endif /* LOTT_DIAG */

int
lott_chuser(struct proc *p, pid_t pid, uid_t uid, int *retval)
{
    if(suser(p->p_cred->pc_ucred, 0) != 0) {
	*retval = EPERM;

	return -1;
    }

    if(pfind(pid) == 0) {
	*retval = ESRCH;
	return -1;
    }

    lott_setuid(pid, uid);

    *retval = 0;
    return 0;
}

int
lott_set_base_tickets(struct proc *p, uid_t uid, ticket_t base_tickets,
		      int *retval)
{
    struct lott_user *luser;
    ticket_t save_base_tickets;
    bool super_user;
    int s;

    s = splhigh();

    if((luser = user_find(uid)) == 0) {
	*retval = ESRCH;

	splx(s);
	return -1;
    }
	
    if(suser(p->p_cred->pc_ucred, 0) == 0) {
	super_user = TRUE;
    } else {
	super_user = FALSE;
    }

    if((super_user == FALSE) && (p->p_cred->pc_ucred->cr_uid != luser->uid)) {
	*retval = EPERM;

	splx(s);
	return -1;
    }

    if((base_tickets < MIN_BASE_TICKETS) ||
       (base_tickets > MAX_BASE_TICKETS)) {
	*retval = EDOM;

	splx(s);
	return -1;
    }

    if((super_user == FALSE) && (base_tickets > luser->allowed_base_tickets)) {
	*retval = EACCES;

	splx(s);
	return -1;	
    }

    save_base_tickets = luser->base_tickets_f32 >> FSHIFT_CNR;

    luser->base_tickets_f32 = base_tickets << FSHIFT_CNR;
    luser->exchange_rate_valid = FALSE;

    if(luser->all_tickets != 0) {
	lottery.all_base -= save_base_tickets;
	lottery.all_base += luser->base_tickets_f32 >> FSHIFT_CNR;
    }

    if(base_tickets > luser->allowed_base_tickets) {
	luser->allowed_base_tickets = base_tickets;
    } else {
	if(super_user == TRUE) {
	    luser->allowed_base_tickets = base_tickets;
	}
    }

    *retval = save_base_tickets;

    splx(s);
    return 0;
}

static int
lott_set_force(struct proc *p, pid_t pid, force_sched_t force_sched,
	       ticket_t force_sched_val, int *retval)
{
    struct lott_proc *lproc;
    ticket_t save_force_sched_val;
    bool super_user;
    int s;

    s = splhigh();

    if((lproc = proc_find(pid)) == 0) {
	*retval = ESRCH;

	splx(s);
	return -1;
    }

    if(suser(p->p_cred->pc_ucred, 0) == 0) {
	super_user = TRUE;
    } else {
	super_user = FALSE;
    }

    if((super_user == FALSE) && (p->p_cred->pc_ucred->cr_uid != lproc->uid)) {
	*retval = EPERM;

	splx(s);
	return -1;
    }

    if((force_sched_val < MIN_BASE_TICKETS) ||
       (force_sched_val > MAX_BASE_TICKETS)) {
	*retval = EDOM;

	splx(s);
	return -1;
    }

    if((force_sched == FORCE_AT_LEAST) && (super_user == FALSE)) {
	*retval = EPERM;

	splx(s);
	return -1;
    }

    save_force_sched_val = lproc->force_sched_val_f64 >> FSHIFT_64;

    lproc->force_sched = force_sched;
    lproc->force_sched_val_f64 = (fix64_t)force_sched_val << FSHIFT_64;

    lproc->base_tickets_valid = FALSE;

    *retval = save_force_sched_val;

    splx(s);
    return 0;
}

static int
lott_info(struct proc *p, lott_info_t lott_info, char *buffer,
	  int num_elements, int *retval)
{
    struct lott_proc *lproc;
    struct lott_user *luser;
    int count_elements = 0;
    int error = 0;
    int i;

    if(lott_info == LPROC_INFO) {
	for(i = 0; i <= lottery.lproc_hash_value; i++) {
	    for(lproc = lottery.lproc_hash_head[i].lh_first; lproc != 0;
		lproc = lproc->lproc_hash_entries.le_next) {
		if(buffer != 0) {
		    if((error = copyout(lproc, buffer +
			    (count_elements * sizeof(struct lott_proc)),
			    sizeof(struct lott_proc))) != 0) {
			goto FINISH_LOTT_INFO;
		    }
		    if(count_elements == num_elements) {
			goto FINISH_LOTT_INFO;
		    }
		}
		count_elements++;
	    }
	}
    } else {
	for(i = 0; i <= lottery.luser_hash_value; i++) {
	    for(luser = lottery.luser_hash_head[i].lh_first; luser != 0;
		luser = luser->luser_hash_entries.le_next) {
		if(buffer != 0) {
		    if((error = copyout(luser, buffer +
			    (count_elements * sizeof(struct lott_user)),
			    sizeof(struct lott_user))) != 0) {
			goto FINISH_LOTT_INFO;
		    }
		    if(count_elements == num_elements) {
			goto FINISH_LOTT_INFO;
		    }
		}
		count_elements++;
	    }
	}
    }

  FINISH_LOTT_INFO:
    
    if(error != 0) {
	*retval = error;
	return -1;
    } else {
	*retval = count_elements;
	return 0;
    }
}

int
lott_handoff(struct proc *p, pid_t pid_from, pid_t pid_to, int *retval)
{
    int s;
    struct lott_proc *lproc_from;

    printf("from: %d, to: %d\n", pid_from, pid_to);

    s = splhigh();

    if((lproc_from = proc_find(pid_from)) == 0) {
	*retval = ESRCH;

	splx(s);
	return -1;
    }

    lproc_from->handoff_pid = pid_to;

    splx(s);
    return 0;
   
}

/* debugging function definitions */
#ifdef LOTT_DIAG
void
lott_debug(void)
{
    struct lott_proc *lproc;
    struct lott_user *luser;
    int i;
    int s;
    
    /* *** SHOULD NEVER BE CALLED BY USER (via syscall...)  This is because
           the printf will call setrunqueue eventually which will screw up
           a lottery data structure *** */

    s = splhigh();

    printf("pid\tuid\tproc\t\tstate\ttick\teff\ttime\tbase\n");
    for(i = 0; i <= lottery.lproc_hash_value; i++) {
	for(lproc = lottery.lproc_hash_head[i].lh_first; lproc != 0;
	    lproc = lproc->lproc_hash_entries.le_next) {
	    printf("%d\t%d\t%08x\t%d\t%d\t%d\t%d\t%d\n", lproc->pid,
		   lproc->uid, (int)lproc->process, lproc->proc_state,
		   lproc->num_tickets, lproc->eff_tickets_f32 >> FSHIFT_COMP,
		   lproc->time_used,
		   (int)(lproc->base_tickets_f64 >> FSHIFT_64));
	}
    }

    printf("\nuid\trun\tbase\tref_count\n");
    for(i = 0; i <= lottery.luser_hash_value; i++) {
	for(luser = lottery.luser_hash_head[i].lh_first; luser != 0;
	    luser = luser->luser_hash_entries.le_next) {
	    printf("%d\t%d\t%d\t%d\n", luser->uid,
		   luser->runnable_user_tickets,
		   luser->base_tickets_f32 >> FSHIFT_CNR,
		   luser->ref_count);
	}
    }

    splx(s);
}
#endif /* LOTT_DIAG */

#else /* LOTTERY */
/* I want just this commented code after I remove scheduler profiling code
   interspersed throughout the kernel...
int
lott_sched(struct proc *p, struct lott_sched_args *uap, int *retval)
{
    int rval;

    psignal(p, SIGSYS);

    *retval = EINVAL;
    return *retval;
}*/

#include <sys/lottery.h>

#ifdef LOTT_DIAG
static int lott_run_order(struct proc *p, struct lott_rorder *rorder_user,
			  int num_entries, int *retval);
#endif /* LOTT_DIAG */

int
lott_sched(struct proc *p, struct lott_sched_args *uap, int *retval)
{
    int rval;

    switch(uap->which) {
#ifdef LOTT_DIAG
    case 4: /* *** severe hack... (shouldn't use a constant) *** */
	rval = lott_run_order(p, (struct lott_rorder *)uap->a1, uap->a2,
			      retval);
	break;
#endif /* LOTT_DIAG */
    default:
	rval = -1;
	psignal(p, SIGSYS);
	*retval = EINVAL;
	break;
    }

    if(rval == -1) {
	return *retval;
    } else {
	return 0;
    }
}

#ifdef LOTT_DIAG
int lott_do_rorder = FALSE;
int lott_rorder_request = 0;
struct lott_rorder lott_rorder[MAX_RUN_ORDER];
int lott_current_rorder = 0;

int
lott_run_order(struct proc *p, struct lott_rorder *rorder_user,
	       int rorder_request, int *retval)
{
    int error;

    if(suser(p->p_cred->pc_ucred, 0) != 0) {
	*retval = EPERM;
	return -1;
    }

    if(rorder_request > MAX_RUN_ORDER) {
	rorder_request = MAX_RUN_ORDER;
    }

    if(rorder_request < 1) {
	*retval = EINVAL;
	return -1;
    }

    if(lott_do_rorder == TRUE) {
	*retval = EBUSY;
	return -1;
    }

    lott_do_rorder = TRUE;

    lott_rorder_request = rorder_request;

    if((error = tsleep(lott_rorder, PUSER | PCATCH, "run_order", 0)) != 0) {
	lott_current_rorder = 0;
	lott_do_rorder = FALSE;

	*retval = error;
	return -1;
    }

    if((error = copyout(lott_rorder, rorder_user,
			sizeof(struct lott_rorder) * rorder_request)) != 0) {
	*retval = error;
	return -1;
    }
    
    *retval = rorder_request;
    return 0;
}

static void
check_finish_rorder(void)
{
    lott_current_rorder++;
    if(lott_current_rorder == lott_rorder_request) {
	lott_current_rorder = 0;
	lott_do_rorder = FALSE;
	wakeup(lott_rorder);
    }
}

int
lott_store_rinfo_proc(struct proc *p, struct timeval *tv)
{
    int s;

    if(lott_do_rorder == FALSE) {
	return 0;
    }
    
    s = splhigh();

    lott_rorder[lott_current_rorder].run_info = RINFO_PROC;
    lott_rorder[lott_current_rorder].rinfo_proc.pid = p->p_pid;
    lott_rorder[lott_current_rorder].rinfo_proc.stat = p->p_stat;
    lott_rorder[lott_current_rorder].rinfo_proc.kern_priority = p->p_priority;
    lott_rorder[lott_current_rorder].rinfo_proc.uid = p->p_cred->p_ruid;
    if(p->p_comm != 0) {
	strcpy(lott_rorder[lott_current_rorder].rinfo_proc.comm, p->p_comm);
    } else {
	strcpy(lott_rorder[lott_current_rorder].rinfo_proc.comm, "<?>");
    }
#define USECS_PER_SEC 1000000
    lott_rorder[lott_current_rorder].rinfo_proc.time_used =
	((tv->tv_sec - runtime.tv_sec) * USECS_PER_SEC) +
	(tv->tv_usec - runtime.tv_usec);
    lott_rorder[lott_current_rorder].rinfo_proc.num_tickets = 0;
    lott_rorder[lott_current_rorder].rinfo_proc.eff_tickets = 0;
    lott_rorder[lott_current_rorder].rinfo_proc.base_tickets = 0;

    lott_rorder[lott_current_rorder].rinfo_proc.utilization_f32 =
	lproc->utilization_f32;

    check_finish_rorder();

    splx(s);
    return 0;
}

int
lott_store_rinfo_cycles(char *function, struct proc *p, long long cycles)
{
    int s;

    if(lott_do_rorder == FALSE) {
	return 0;
    }
    
    s = splhigh();

    lott_rorder[lott_current_rorder].run_info = RINFO_CYCLES;
    strncpy(lott_rorder[lott_current_rorder].rinfo_cycles.function,
	    function, FUNCTION_STRLEN);
    /* need the next line in case __FUNCTION__ is greater than 31... */
    lott_rorder[lott_current_rorder].
	rinfo_cycles.function[FUNCTION_STRLEN] = 0;
    lott_rorder[lott_current_rorder].rinfo_cycles.pid = p->p_pid;
    lott_rorder[lott_current_rorder].rinfo_cycles.cycles = cycles;    
    lott_rorder[lott_current_rorder].rinfo_cycles.priority = p->p_priority;

    check_finish_rorder();

    splx(s);
    return 0;
}

int
lott_store_rinfo_quantum_expire(void)
{
    int s;

    if(lott_do_rorder == FALSE) {
	return 0;
    }
    
    s = splhigh();

    lott_rorder[lott_current_rorder].run_info = RINFO_QUANTUM_EXPIRE;

    check_finish_rorder();

    splx(s);
    return 0;
}

int
lott_store_rinfo_location(void *chan, int pri, char *wmesg, int timo,
			  char *file, char *function, int line)
{
    long long cycles_start, cycles_end;
    int ts_ret;
    int s;

    cycles_start = rdtsc();

    ts_ret = TSLEEP(chan, pri, wmesg, timo);

    if(lott_do_rorder == FALSE) {
	return ts_ret;
    }

    cycles_end = rdtsc();

    s = splhigh();

    lott_rorder[lott_current_rorder].run_info = RINFO_LOCATION;
    lott_rorder[lott_current_rorder].rinfo_location.pid = curproc->p_pid;
    if(curproc->p_comm != 0) {
	strcpy(lott_rorder[lott_current_rorder].rinfo_location.comm,
	       curproc->p_comm);
    } else {
	strcpy(lott_rorder[lott_current_rorder].rinfo_location.comm,
	       "<?>");
    }
    lott_rorder[lott_current_rorder].rinfo_location.chan = chan;
    lott_rorder[lott_current_rorder].rinfo_location.pri = pri;
    strncpy(lott_rorder[lott_current_rorder].rinfo_location.wmesg,
	    wmesg, WMESGLEN);
    lott_rorder[lott_current_rorder].rinfo_location.wmesg[WMESGLEN] = 0;
    lott_rorder[lott_current_rorder].rinfo_location.timo = timo;
    strncpy(lott_rorder[lott_current_rorder].rinfo_location.function,
	    function, FUNCTION_STRLEN);
    lott_rorder[lott_current_rorder].rinfo_location.
	function[FUNCTION_STRLEN] = 0;
    strncpy(lott_rorder[lott_current_rorder].rinfo_location.file,
	    file, FILE_STRLEN);
    lott_rorder[lott_current_rorder].rinfo_location.
	file[FILE_STRLEN] = 0;
    lott_rorder[lott_current_rorder].rinfo_location.line_num = line;
    lott_rorder[lott_current_rorder].rinfo_location.cycles_start =
	cycles_start;
    lott_rorder[lott_current_rorder].rinfo_location.cycles_end =
	cycles_end;

    check_finish_rorder();

    splx(s);

    return ts_ret;
}
#else /* LOTT_DIAG */
int
lott_store_rinfo_location(void *chan, int pri, char *wmesg, int timo,
			  char *file, char *function, int line)
{
    return TSLEEP(chan, pri, wmesg, timo);   
}
#endif /* LOTT_DIAG */

#endif /* LOTTERY */
