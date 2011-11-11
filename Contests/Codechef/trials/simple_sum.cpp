#include <stdio.h>
#include <iostream>
using namespace std;

int modular_exponentiation(long long a, long long b, int modulo);

int main()
{
	int T;
	fscanf(stdin, "%d", &T);

	long long n;
	int m;
	while(T--) {
		scanf("%lld", &n);
		scanf("%d", &m);
	
		long sum = 0;
		
		if( n&1 ) {
			for(long long i = 1; i <= (n/2); ++i) {
				sum = ( sum + modular_exponentiation(i,i,m) )%m;
				sum = ( sum + modular_exponentiation(n-i, n-i, m) )%m;
			}
			sum = ( sum + modular_exponentiation(n, n, m) )%m;
		}
		else {
			for(long long i = 1; i <= (n/2); ++i) {
				sum = ( sum + modular_exponentiation(i,i,m) )%m;
				sum = ( sum + modular_exponentiation(n-i+1, n-i+1, m) )%m;
			}
		}
	
		fprintf(stdout, "%ld\n", sum);
	}
	return 0;
}

int modular_exponentiation(long long a, long long b,int modulo)
{
   int result = 1;
   long long power = a;
   while(b)
   {
      if(b&1)
          result=(result*power)%modulo;
      
       power=(power*power)%modulo;
       b >>= 1;
   }
   return result;
}
