/*
*	CODE: INTEST
*/

#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	long T,K;
	fscanf(stdin, "%ld", &T);
	fscanf(stdin, "%ld", &K);

	long count = 0;
	long n = 0;

	while(T--)
	{
		fscanf(stdin, "%ld", &n);
		if( n%K == 0)
			++count;
		n = 0;
	}

	fprintf(stdout, "%ld\n", count);
	return 0;
}
