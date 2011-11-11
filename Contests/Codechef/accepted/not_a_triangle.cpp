#include <iostream>
#include <cstdlib>
#include <stdio.h>
using namespace std;

long* bsearch(long *key, long* a, long min, long max);
int compare (const void * a, const void * b)
{
	return ( *(long*)a - *(long*)b );

}
int main()
{
	int n;
	fscanf(stdin, "%d", &n);

	while(n)
	{
		long a[n];
		for(int i = 0 ; i < n; ++i)
			fscanf(stdin, "%ld", &a[i]);
		
		qsort(a, n, sizeof(long), compare);

		long count = 0;
		for(int i = 0;  i <= (n-3) ; ++i)
		{
			for(int j = i+1; j <= (n-2); ++j)
			{
				long sum = a[i] + a[j];
				long* index = (long*)bsearch(&sum, a, j+1, n-1);
				if(index == NULL)
					continue;
				else {
					int offset = index - a;
					count += (n - offset);
				}
			}
		}
		fprintf(stdout, "%ld\n", count);
		fscanf(stdin, "%d", &n);
	}
}

long* bsearch(long *key, long* a, long min, long max)
{
	long low = min, high = max;

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
	if( a[low] <= *key)
		return NULL;

	return &a[low];
}
