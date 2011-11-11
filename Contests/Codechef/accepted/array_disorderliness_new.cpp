#include <iostream>
#include <stdio.h>
#include <cstdlib>
using namespace std;
long* bsearch(long*, long* , long );

int main()
{
	long N;
	fscanf(stdin, "%ld", &N);
	
	long a[N];
	long max = 0, j = 0;
	long count = 0;

	for(long i = 0 ; i < N; ++i)
	{
		long h;
		fscanf(stdin, "%ld", &h);
		if( h > max ) {
			a[j++] = max = h;
		}
		else {
			long* index = (long*) bsearch(&h, a, j-1 );
			if(index != NULL) {
				long offset = index - a;
				count += (j - offset);
				for(long p = j; p >= (offset+1); --p)
					a[p] = a[p-1];

				a[offset] = h;
				++j;
			}
		}

	}
	fprintf(stdout, "%ld\n", count);
}

long* bsearch(long *key, long* a, long max)
{
	long low = 0, high = max;

	while( low != high )
	{
		long mid = (low + high)/2;
		if (a[mid] > *key)
		{
			high = mid;
		}
		else
			low = mid+1;
	}
	return &a[low];
}
