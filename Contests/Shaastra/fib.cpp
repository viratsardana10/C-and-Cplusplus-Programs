#include <map>
#include <stdio.h>
#include <iostream>
#define modulo 10009

typedef map< long,long,less<long> > Map;
Map cache;
long fib(long n);

int main()
{
	int T;
	fscanf(stdin, "%d", &T);

	cache[0] = 0;
	cache[1] = 1;
	cache[2] = 1;

	while(T--)
	{
		long x, y;
		fscanf(stdin, "%ld", &x);
		fscanf(stdin, "%ld", &y);
		long sum = 0;
		for(long i = x; i <= y; ++i)
		{
			
		}
		fprintf(stdout, "%ld\n", sum);
	}
	return 0;
}

long fib(long n)
{
	if(n == 0)
		return 0;

	if(cache.count(n))
		return cache[n];

	cache[n] = (cache[n-1] + cache[n-2])%modulo;
	return cache[n];
}
