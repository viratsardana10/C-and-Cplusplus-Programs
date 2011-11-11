/* Author: Vivek Prakash
 * Date: Aug 6, 2011
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <netdb.h>
#include <err.h>

const char* ip;
extern int h_errno;

int main(int argc, char **argv)
{

	ip = argv[1];
	struct sockaddr_in server;
	struct hostent *host;

	if(inet_aton(ip, &server.sin_addr) == 0)
		warn("Not a valid ip address: %s", ip);

	host = (struct hostent *) gethostbyaddr ((char *)&server.sin_addr.s_addr, sizeof (server.sin_addr.s_addr), AF_INET);
	if (host == NULL)
	{
		switch(h_errno) {
			case HOST_NOT_FOUND:
				printf("The specified host is unknown.\n");
				break;
			case NO_ADDRESS:
				printf("The requested name is valid but does not have an IP address.\n");
				break;
			case NO_RECOVERY:
				printf("A non-recoverable name server error occurred.\n");
				break;
			case TRY_AGAIN:
				printf("A temporary error occurred on an authoritative name server. Try again later.\n");
				break;
			default:
				printf("Unknown error occurred.\n");
				break;
		};
		printf("%s: Available\n", ip);
	} else {
		struct in_addr **iplist;
		iplist = (struct in_addr **) host->h_addr_list;
		int j;
		for (j = 0; iplist[j] != NULL; ++j)
		{
			printf("%s: %s\n", inet_ntoa(*iplist[j]), host->h_name);
		}
	}

	return 0;
}
