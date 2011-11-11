typedef int boolean_t; /* is there a better place to put these? */
#define	FALSE	0
#define	TRUE	1

#include <sys/queue.h>
#include <sys/lottery.h>

int lott_set_user_tickets(pid_t pid, ticket_t num_tickets);
int lott_stat(bool print_stats, bool proc_stats, bool cycle_stats, bool location_stats, pid_t pid);
int lott_ctl(bool do_currency, bool do_abbrev_quanta, bool do_kern_priority);
int lott_chuser(pid_t pid, uid_t uid);
int lott_run_order(struct lott_rorder *rorder, int num_entries);
int lott_set_base_tickets(pid_t pid, ticket_t base_tickets);
int lott_set_force(pid_t pid, force_sched_t force_sched,
		   ticket_t force_sched_val);
int lott_info(lott_info_t lott_info, void *buffer, int num_elements);
int lott_handoff(pid_t pid_from, pid_t pid_to);
