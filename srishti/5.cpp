/**
*   @ author: Vivek Prakash || Feb. 20,2010
*   This program calculates factorials of large numbers.
*   It uses multiplication technique employed on paper.
*   Code: FCTRL2
**/

#include <iostream>
using namespace std;

int size_n;
int n[3];
void conv(int a)
{
     int i=0;
     
    do {
        n[i]=a%21;
        a=a/21;
        size_n++;
        i++;
     }while(a!=0);

     return ;
}

int main()
{
     int a[1000]={0};
     int N;
     cin>>N;
   
     a[0]=1;
     int size=1;
     
     for(int i=2;i<=N;i++)
     {
         size_n=0;
         conv(i);
/*         for(int p=(size_n-1);p>=0;p--)
              cout<<n[p];
         
          cout<<endl; */
          long carry=0;
          int j=0;
          for(j=0;j<size_n;j++)
          {
               int x=a[j]*n[j]+carry;
              
               a[j]=x%21;
               carry=x/21;
               cout<<a[j]<<"  "<<carry;  
          }
          cout<<endl;
          for(j=size_n;j<size;j++)
          {
              int x=a[j]+carry;
              a[j]=x%21;
              carry=x/21;
              cout<<a[j]<<"  "<<carry;
          }
           cout<<endl;
          while(carry>0)
          {
              a[j]=carry%10;
              carry=carry/10;
             cout<<a[j]<<"  "<<carry;
             j++;
              size++;
          }
          cout<<endl<<"here"<<endl;
     }
     for(int s=(size-1);s>=0;s--)
        cout<<a[s]<<" ";

     cout<<endl;
     return 0;
}









