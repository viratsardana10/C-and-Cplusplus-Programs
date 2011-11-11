#include <iostream>
using namespace std;

long mod_exp(int ,int ,int );

int main()
{
	for(int i = 2; i < 561; i++)
	{
		if (mod_exp(i,560,561) == 1)
			cout << i << "  " ;
	}

	cout << endl;

	return 0;
}

long mod_exp(int power, int b, int modulo)
{
   long result=1;
   while(b)
   {
      if(b&1)
          result=(result*power)%modulo;
      
       power=(power*power)%modulo;
       b >>= 1;
   }
   return result;
}
