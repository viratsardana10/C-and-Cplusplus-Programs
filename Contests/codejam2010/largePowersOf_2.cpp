/**
*   @ author: Vivek Prakash || Feb. 20,2010
*   This program calculates large powers of 2.
*   It uses multiplication technique employed on paper.
*   Code: FCTRL2
**/

#include <iostream>
using namespace std;

int main()
{
   int cases=1;
//   cin>>cases;
   for(int i=0;i<cases;i++)
   {
     unsigned short int a[10000];
     int N;  // power of 2 raised to N
     cin>>N;
     if(N==0)
     {
        cout<<1<<endl;
        continue;
     }
   
     a[0]=1;
     int size=1;
     
     for(int i=1;i<=N;i++)
     {
          long carry=0;
          int j=0;
          for(j=0;j<size;j++)
          {
               int x=a[j]*2+carry;
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
     for(int s=(size-1);s>=0;s--)
     {
        cout<<a[s];
     }
     cout<<endl;
   }

}









