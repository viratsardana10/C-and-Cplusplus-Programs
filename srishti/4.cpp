#include <iostream>
#include <fstream>
using namespace std;
  long a[57570];
  int b[57570]={0};
void fact(long ,int );
int main()
{
    ifstream infile("prime");
  
    for(int i=0;i<57570;i++)
        infile >> a[i];

    long N;
    cin >> N;
    fact(N,0);
    long num=0;
    long count=1; 
 /*   for(int i=2;i<N;i++)
    {
      int k=i;
      fact(k,0);
      
      cout<<endl;
      long temp=1;
       for(int p=0;p<57570;p++)
       {
           if(b[p]>0)
           {
                temp*=b[p]+1;
           }
                
       }       
       if(temp>count)
       {
            count=temp;
             num=i; 
       }
    }
    cout<<num<<endl; */
}

void fact(long n,int count)
{
   if(n==1)
       return;

   int j;
   for(j=count;a[j]<=(n/2);j++)
   {
      if(n%a[j]==0)
      {
         cout<<a[j]<<"  ";
         b[j]++;
         break; 
      }
   }
   fact((n/a[j]),0); 
}
