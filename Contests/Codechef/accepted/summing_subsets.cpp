#include <iostream>
using namespace std;

long modular_exponentiation(long long );
#define modulo 8388608

int main()
{
   int cases;
   cin>>cases;

   while(cases--) 
   {
       long long N;
       cin >> N;
       if(N==1)
       {
          cout<<1<<endl;
          continue;
       }

      long sum=(((N*N-N+2)%modulo*modular_exponentiation(N-1)-1+modulo)%modulo);    
       
    /*   long F_N=0;
       long sum=0;
       long factor=1;
       for(long long i=1;i<=N;i++)    
       {
          F_N=((2*F_N)%modulo+(factor*i)%modulo)%modulo;
          sum=(sum+F_N)%modulo;
          factor=(factor*2)%modulo;
       } */ 
       cout<<sum<<endl; 
   }
   return 0;
}

long modular_exponentiation(long long b)
{
   long result=1;
   long power=2;
   while(b)
   {
      if(b&1)
          result=(result*power)%modulo;
      
       power=(power*power)%modulo;
       b >>= 1;
   }
   return result;
}
