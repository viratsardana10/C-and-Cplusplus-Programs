/* gcc -Wall -g -c liblott.c
 * ar -rv liblott.a liblott.o
 */

#include <sys/param.h>
#include <sys/syscall.h>
#include <unistd.h>

#include "liblott.h"

int
lott_set_user_tickets(pid_t pid, ticket_t num_tickets)
{
    return syscall(LOTT_SYSCALL_NUM, LOTT_SET_USER_TICKETS, pid, num_tickets);
}

int
lott_stat(bool print_stats, bool proc_stats, bool cycle_stats,
	  bool location_stats, pid_t pid)
{
    return syscall(LOTT_SYSCALL_NUM, LOTT_STAT, print_stats, proc_stats,
		   cycle_stats, location_stats, pid);
}

int
lott_ctl(bool do_currency, bool do_abbrev_quanta, bool do_kern_priority)
{
    return syscall(LOTT_SYSCALL_NUM, LOTT_CTL, do_currency, do_abbrev_quanta,
		   do_kern_priority);
}

int
lott_chuser(pid_t pid, uid_t uid)
{
    return syscall(LOTT_SYSCALL_NUM, LOTT_CHUSER, pid, uid);
}

int
lott_run_order(struct lott_rorder *rorder, int num_entries)
{
    return syscall(LOTT_SYSCALL_NUM, LOTT_RUN_ORDER, rorder, num_entries);
}

int
lott_set_base_tickets(pid_t pid, ticket_t base_tickets)
{
    return syscall(LOTT_SYSCALL_NUM, LOTT_SET_BASE_TICKETS, pid, base_tickets);
}

int
lott_set_force(pid_t pid, force_sched_t force_sched, ticket_t force_sched_val)
{
    return syscall(LOTT_SYSCALL_NUM, LOTT_SET_FORCE, pid, force_sched,
		   force_sched_val);
}

int
lott_info(lott_info_t lott_info, void *buffer, int num_elements)
{
    return syscall(LOTT_SYSCALL_NUM, LOTT_INFO, lott_info, buffer,
		   num_elements);
}

int
lott_handoff(pid_t pid_from, pid_t pid_to)
{
    return syscall(LOTT_SYSCALL_NUM, LOTT_HANDOFF, pid_from, pid_to);
}
