#include <iostream>
using namespace std;

int main()
{
     long N=713485;
     long num=0;
     long count=0;
   
     for(long i=2;i<N;i++)
     {
         long temp=0;
         for(long j=1;j<=(i/2);j++)
         {
             if((i%j)==0)  
               temp++;         
         }
         if(temp>count)
         {
             num=i;
             count=temp;
         }
     }
     cout<<num<<endl;
    
}
