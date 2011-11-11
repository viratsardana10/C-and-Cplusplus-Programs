#include <iostream>
using namespace std;
long N;
bool isPrime(long );
long mod_exp(int ,long ,long );

int main()
{
      cin >> N;
      cout<<isPrime(N);

     cout<<endl;
}

bool isPrime(long i)
{
          long d =0;
          int n=i-1;
          while(n%2==0)
          {
               d++;
               n=n/2;
          }
          long s=n;
          int a[3]={2,7,61};
          for(int k=0;k<3;k++)
          { 
            if(a[k]<i)
            {
              long x=mod_exp(a[k],d,i);
              if(x==1 || x==(i-1))
                   continue;
           
              for(long r=0;r<s;r++)
              {
                  x=(x*x)%i;
                  if(x==1)
                     return false;
                  if(x==(i-1)) 
                     break;
              }
              return false;
            }
           else 
             break;
          }
          return true;
}

long mod_exp(int a,long b,long modulo)
{
    long result=1;
    long power=a;
    long long temp=b;
     
    for(int i=0;i<N;i++)
    {
        if(temp==0)
              break;
        if(b & (1<<i))
             result=(result*power)%modulo;
        power=(power*power)%modulo;
        temp/=2;
    }
   return result;     
}
