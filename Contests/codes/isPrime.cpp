#include <iostream>
#include <cstdlib>
using namespace std;

void compute(int& t, unsigned long& u, unsigned long n); // n-1 = (2^t)u
bool witness(unsigned long a, unsigned long n, int t, unsigned long u);
bool isPrime(unsigned long n, unsigned long s);
unsigned long modular_exponentiation(unsigned long a, unsigned long b, unsigned long modulo);

int main()
{
	unsigned long i;
	cin >> i;
	cout << i << ( isPrime(i, 20) ? " is prime." : " not prime." ) << endl;

	return 0;
}

bool isPrime(unsigned long n, unsigned long s)
{
	if ( n == 2 )
		return true;
	else if( !(n%2) || n == 1 )
		return false;

	int t = 0;
	unsigned long u = 0;
	compute(t, u, n-1); // n-1 = 2^t * u
	cout << t << "   " << u << endl;
	
//	int a[3] = {2, 7, 61};
//	bool flag = true; // is composite

	for(int i = 0; i < s; ++i)
	{
		srand(i);
		int a = rand()%(n-1) + 1;
		if(witness(a, n, t, u))
		{
			cout << a << " is witness to composite.\n";
		//	return false;
		}
//			flag = false;	 // not composite	
	}
	cout << endl;
//	return (!flag);
	return true;
}

bool witness(unsigned long a, unsigned long n, int t, unsigned long u)
{
	unsigned long x[t+1];
	x[0] = modular_exponentiation(a, u, n);
	cout << "x0 : " << x[0] << endl;	
	for(int i = 1; i <= t; ++i)	
	{
		x[i] = (x[i-1]*x[i-1])%n;
//		cout << x[i] << "  " << x[i-1] << endl; 
		if( x[i] == 1 && x[i-1] != 1 && x[i-1] != (n-1) )
			return true;
	}
	if( x[t] != 1)
		return true;

	return false;
}

void compute(int& t, unsigned long& u, unsigned long n) 
{
	t = 0;
	while(!(n&1))
	{
		n >>= 1;
		++t;
	}
	u = n;

	return ;
}

unsigned long modular_exponentiation(unsigned long a, unsigned long b, unsigned long modulo)
{
   unsigned long result = 1;
   unsigned long power = a;
   while(b)
   {
      if(b&1)
          result=(result*power)%modulo;
      
       power=(power*power)%modulo;
       b >>= 1;
   }
   return result;
}
