#include <iostream>
using namespace std;


//int a[10000];
long count=0;
void sieve(long [] ,long );
int main()
{
    long *a;
    long s;
   
    cout<<"Enter the size of array:";
    cin>>s;
    a=new long [s]; 
    sieve(a,s);
    
    cout<<endl;
    return 0;
}

void sieve(long a[],long s)
{
    for(long i=0;i<s;i++)
    {
        a[i]=1;
    }
    
    for(long i=2;i<s;i++)
    {
        if(a[i]==1){
         long k=1;
        for(long j=i;j<s;(j=i*k))
        {
            if(j!=i)
              a[j]=0;
              
             k++;
        }
      } 
    }
    
    long k=0;
    for(long i=2;i<s;i++)
    {
        if(a[i]==1)
        {
          count++;
          cout<<i<<"   ";
          k++;
        }
    }
}
