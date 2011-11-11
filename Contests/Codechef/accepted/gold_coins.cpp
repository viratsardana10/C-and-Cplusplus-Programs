/*
*	Author: Vivek Prakash
*	Created on: Sep 21, 2010
* 	CODE : COINS
*/

#include <iostream>
#include <stdio.h>
#include <map>

using namespace std;
typedef map< unsigned long, unsigned long, less<unsigned long> > Cache;

unsigned long compute(unsigned long );
unsigned long max(unsigned long ,unsigned long );
Cache cache;	

int main()
{
	unsigned long n;

	while( cin >> n )
	{
		unsigned long money = compute(n);
		cout << money << endl;
		
		cache.clear();
	}
}

unsigned long compute(unsigned long n)
{
//	cout << n << " : " << cache[n] << endl;
	if ( cache.count(n) )
	{	//cout << n << " : " << cache[n] << endl;
		return cache[n];
	}

	if (n == 0)
		return 0;
	unsigned long n2 = n/2;
	unsigned long n3 = n/3;
	unsigned long n4 = n/4;
	
	unsigned long value = max( n, compute(n2)+compute(n3)+compute(n4) );

	cache.insert(Cache::value_type( n, value) );
	return cache[n];
}

unsigned long max(unsigned long a, unsigned long b)
{
	return ( (a > b) ? a : b );
}
