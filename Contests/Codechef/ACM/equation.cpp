#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int T;
	fscanf(stdin, "%d", &T);
	while(T--)
	{
		int N,A,B,C;
		fscanf(stdin, "%d", &N);
		fscanf(stdin, "%d", &A);
		fscanf(stdin, "%d", &B);
		fscanf(stdin, "%d", &C);
	
		long count = 0;
		for(int a = 0 ; a <= A; ++a)
			for(int b = 0; b <= B; ++b)
				for(int c = 0; c <= C; ++c)
						if( (a+b+c) <= N)
							++count;
		fprintf(stdout, "%ld\n", count);
	}
	return 0;
}


