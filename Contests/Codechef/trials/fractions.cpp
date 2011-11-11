/*
 * author : Vivek Prakash
 *   date : 31-01-2011   
 *   Code : ADDFRAC
 */

#include <iostream>
#include <stdio.h>
using namespace std;

long long gcd(long long ,long long );

int main()
{
	int T;
	scanf("%d", &T);
	while(T--) {
		long long N;
		scanf("%lld", &N);
		long long a[N][2];
		for(long long i = 0 ; i < N; ++i)
		{
			char s[50];
			scanf("%s", s);
			long long num = 0;
			int j;
			for(j = 0 ; s[j] != '/' ; ++j) 
				num = 10*num + int(s[j] - '0');
			long long den = 0;		
			for(j++ ; s[j] != '\0' ; ++j) 
				den = 10*den + int(s[j] - '0');
				
			a[i][0] = num;
			a[i][1] = den;	
		}
	
		long long M[N][2];
		M[N-1][0] = a[N-1][0];
		M[N-1][1] = a[N-1][1];	

		for(long long i = N-2; i >= 0 ; --i)
		{
			long long num = a[i][0] + M[i+1][0];
			long long den = a[i][1] + M[i+1][1];	
			long long t = num*a[i][1] - den*a[i][0];
			if(t > 0) {
				M[i][0] = num;
				M[i][1] = den;
			} else {
				M[i][0] = a[i][0];
				M[i][1] = a[i][1];
			}	
		}

		for(long long i = 0 ; i < N; ++i)
		{
			long long x = M[i][0], y = M[i][1];
			long long d = gcd(x, y);
			printf("%lld/%lld\n", M[i][0]/d , M[i][1]/d);
		}
		printf("\n");
	}
	return 0;
}

long long gcd(long long a, long long b)
{
    long long c;
    while(1)
    {
  	c = a%b;
  	if(c == 0)
  	  return b;
  	a = b;
  	b = c;
    }
}
