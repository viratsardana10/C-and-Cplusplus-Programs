/**
*   @ author: Vivek Prakash || Feb. 20,2010
*   This program calculates factorials of large numbers.
*   It uses multiplication technique employed on paper.
*   Code: FCTRL2
**/

#include <iostream>
using namespace std;

int main()
{
   int cases;
   cin>>cases;
   for(int i=0;i<cases;i++)
   {
     unsigned short int a[10000];
     int N;
     cin>>N;
     if(N==0 || N==1)
     {
        cout<<1<<endl;
        continue;
     }
   
     a[0]=1;
     int size=1;
     
     for(int i=2;i<=N;i++)
     {
          long carry=0;
          int j=0;
          for(j=0;j<size;j++)
          {
               int x=a[j]*i+carry;
               a[j]=x%10;
               carry=x/10;  
          }
          while(carry>0)
          {
              a[j]=carry%10;
              carry=carry/10;
              j++;
              size++;
          }
     }
     int zero=0;
     for(int s=(size-1);s>=0;s--)
     {
        cout<<a[s];
        if(a[s]==0)
           zero++;
     }

     cout<<endl<<zero<<endl;
   }

}









