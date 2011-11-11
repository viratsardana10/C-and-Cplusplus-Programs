/*
*	CODE: MARBLES
*/
//#include <iostream>
//#include <stdio.h>
//#include <list>
//using namespace std;

long long C(long , long );

int main()
{
	int T;
	fscanf(stdin, "%d", &T);

	while(T--)
	{
		long N,K;
		fscanf(stdin, "%ld", &N);
		fscanf(stdin, "%ld", &K);
		
		if( N == K)
			fprintf(stdout, "%d\n", 1);
		else
		{
			N = N-K;
			long long value = C(N+K-1, K-1);
			fprintf(stdout, "%lld\n", value);
		}
	}
	return 0;
}

long long C(long n, long r)
{
/*	long long d = n-r;

	long long max = (r > d) ? r : d;
	long long smaller = (r < d) ? r : d; 

	list<long long> values;
	while(n > max) {
		values.push_back(n);
		--n;
	}
	
	list<long long>::iterator iter;
	while(smaller > 1) {
		for(iter = values.begin(); iter != values.end(); ++iter)
		{
			if( (*iter)%smaller == 0)
			{
				long long temp = *iter;
				values.remove(temp);
				values.push_back(temp/smaller);
				break;
			}
		}
		--smaller;
	}
	
	long long product = 1;
	for(iter = values.begin(); iter != values.end(); ++iter)
		product = product * (*iter);
*/
	if( r > n/2 )
		r = n-r;
	long long product = 1;
	for(int i = 1; i <= r; ++i)
		product = (product*(n+1-i))/i;
	return product;
}
