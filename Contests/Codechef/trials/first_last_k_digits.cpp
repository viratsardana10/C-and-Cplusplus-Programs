/* CODE: MARCHA4 */

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iomanip>
using namespace std;

#define s(x) scanf("%d", &x)
#define sll(x) scanf("%lld", &x)
#define p(x) printf("%d", x)
#define pl(x) printf("%ld", x)
#define FOR(A,B,C) for(int i = A; i < B; i += C)
#define ll long long
#define l long

ll modulo;
ll modular_exponentiation(ll );

int main()
{
	int T;
	s(T);
	while(T--)
	{
		long long N; 
		sll(N); 
		int K; 
		s(K);

		modulo = 1;
	  	FOR(0,K,1)
   			modulo *= 10;

		ll first, last;
		last = modular_exponentiation(N);

		long double param = (N * log10(N));
	
		
		l double fract_part = param - floor(param);	

		l double power = pow(10, fract_part);
	
		l double digits;
		digits = power*(modulo/10);

		printf("%lld ", first);	
		cout << right << setw(K) << setfill('0') << last;
		printf("\n");

	} 
	return 0;

}

ll modular_exponentiation(ll n)
{
   ll result = 1;
   ll power = n;

   while(n)
   {
      if(n&1)
	  {
          result = (result*power)%modulo;
	  }
     	 
       power=(power*power)%modulo;
       n >>= 1;
   }

   return result;
}

