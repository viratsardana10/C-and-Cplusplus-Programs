/*
*	CODE: DCE03
*/

#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

int parenthesis(int );

typedef map< int, int , less<int> > Map;
Map cache;

int main()
{
	int t;
	fscanf(stdin, "%d", &t);

	while(t--)
	{
		int n;
		fscanf(stdin, "%d", &n);

		int count = parenthesis(n); 
		fprintf(stdout, "%d\n", count);

	}
	return 0;
}

int parenthesis(int n)
{
	if(n == 1)
		return 1;
	if( cache.count(n) != 0 )
		return cache[n];
	
	cache[n] = 0;
	for(int k = 0 ; k < n; ++k)
		cache[n] =  cache[n] +  (parenthesis(k) * parenthesis(n-k)) ;
	return cache[n];
}	
