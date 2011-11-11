#include <iostream>
using namespace std;

int main()
{
    long a=324791;
    long count=0;
    int sum[100];
    long size=1;
    sum[0]=0;

    
    long j=0;
    for(long i=3;i<a;i++)
    {
       if((i%3)==0 || (i%5)==0)
       {
          if((i%7)!=0)
          {
            int n[5];
            long k=i;
            int s=0;
            while(k>0)
            {
               n[s]=(k%10);
               k=k/10;
               s++;
            }
            long carry=0;
            for(int j=0;j<s;j++)
            {
                int x=sum[j]+n[j]+carry;
                sum[j]=x%10;
                carry=x/10;
            }
            int p;
            for(p=s;p<size;p++)
            {
               int x=sum[p]+carry;
               sum[p]=x%10;
               carry=x/10;
               
            }
            while(carry>0)
            {
               sum[p]=carry%10;
               carry=carry/10;
               p++;
               size++;
            }
            cout<<i<<"      ";
     for(int t=(size-1);t>=0;t--)
         cout<<sum[t];
      
      cout<<endl;      
            count++; 
          }
       }
    }
    cout<<endl;
    for(int t=(size-1);t>=0;t--)
         cout<<sum[t];
    cout<<endl<<count<<endl;
   // cout<<sum<<endl<<count<<endl;
}
