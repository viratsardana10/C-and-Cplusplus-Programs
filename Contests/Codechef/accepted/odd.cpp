/*
*	CODE: DCE05
*/

#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	long T;
	fscanf(stdin, "%ld", &T);
	while(T--)
	{
		long n;
		fscanf(stdin, "%ld", &n);

		long value = 1;
		while( n != 1)
		{
			 n = n >> 1;
			 value <<= 1;
		}
		fprintf(stdout, "%ld\n", value);
	}
	return 0;
}
