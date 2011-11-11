#include <iostream>
#include <stdio.h>

unsigned long long C(unsigned long long , unsigned long long );

int main()
{
	int T;
	scanf("%d", &T);
	while(T--) {
		unsigned long long n,k;
		fscanf(stdin, "%lld", &n);
		fscanf(stdin, "%lld", &k);
		fprintf(stdout, "%lld\n", C(n,k));	
		
	}
	return 0;
}

unsigned long long C(unsigned long long n, unsigned long long r)
{
	if(n < r) return 0;
	if(n == r) return 1;

	if( r > n/2 )
		r = n-r;

	unsigned long long product = 1;

	for(unsigned long long i = 1; i <= r; ++i) {
		product = (product*(n+1-i))/i;
	}
	return product;
}
