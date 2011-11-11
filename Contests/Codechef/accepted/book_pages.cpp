#include <iostream>
#include <stdio.h>
using namespace std;
#define ll long long 

int main()
{
	
	while(1)
	{
		char c;
		ll N = 0;

		while( (c = getchar()) != '\n') {
			if ( c == '#') return 0;
			if(c >= '0' && c <= '9')
				N = (10*N + (c-'0'));
		}
/*
	ll i = 1;
	ll j = 9;

	ll digits = 0;
	while( digits < 2000000000)
	{
		digits += (i*j);
		
		long pages = 0;
		for(int k = 0 ; k < i ; ++k)
			pages = 10*pages + 9;

		printf("%ld -> %lld\n", pages, digits);

		++i;
		j *= 10;
	}
*/
	if( N <= 9)
	{
		printf("%lld\n", N);
	}
	else if( N <= 189 )
	{
		ll x = N-9;
		if(x%2 == 0)
			printf("%lld\n", 9+(x/2) );
		else 
			printf("Impossible!\n");
	}
	else if( N <= 2889 )
	{
		ll x = N-189;
		if(x%3 == 0)
			printf("%lld\n", 99+(x/3) );
		else 
			printf("Impossible!\n");
	
	}
	else if( N <= 38889 )
	{
		ll x = N-2889;
		if(x%4 == 0)
			printf("%lld\n", 999+(x/4) );
		else 
			printf("Impossible!\n");
	
	}
	else if( N <= 488889 )
	{
		ll x = N-38889;
		if(x%5 == 0)
			printf("%lld\n", 9999+(x/5) );
		else 
			printf("Impossible!\n");
	
	}
	else if( N <= 5888889 )
	{
		ll x = N-488889;
		if(x%6 == 0)
			printf("%lld\n", 99999+(x/6) );
		else 
			printf("Impossible!\n");
	
	}
	else if( N <= 68888889 )
	{
		ll x = N-5888889;
		if(x%7 == 0)
			printf("%lld\n", 999999+(x/7) );
		else 
			printf("Impossible!\n");
	
	}
	else if( N <= 788888889 )
	{
		ll x = N-68888889;
		if(x%8 == 0)
			printf("%lld\n", 9999999+(x/8) );
		else 
			printf("Impossible!\n");
	
	}
	else if( N <= 2000000000 )
	{
		ll x = N-788888889;
		if(x%9 == 0)
			printf("%lld\n", 99999999+(x/9) );
		else 
			printf("Impossible!\n");
	
	}
	}
	return 0;
}

