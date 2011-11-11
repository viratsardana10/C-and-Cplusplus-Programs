/* gcc -Wall -o lott_chuser lott_chuser.c -L../liblott -llott */

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
    uid_t uid;
    bool got_pid = FALSE, got_uid = FALSE, arg_error = FALSE;
    char c;

    while((c = getopt(argc, argv, "u:p:")) != EOF) {
	switch(c) {
	case 'u':
	    got_uid = TRUE;
	    uid = atoi(optarg);
	    break;
	case 'p':
	    got_pid = TRUE;
	    pid = atoi(optarg);
	    break;
	case '?':
	default:
	    arg_error = TRUE;
	    break;
	}
    }

    if((got_pid == FALSE) || (got_uid == FALSE) || (arg_error == TRUE)) {
	printf("usage: lott_chuser -p<pid> -u<uid>\n");
	return -1;
    }

    if(lott_chuser(pid, uid) == -1) {
	perror("lott_chuser");
	return -1;
    }

    return 0;
}
