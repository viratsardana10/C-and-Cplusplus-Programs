#include <iostream>
using namespace std;

int main()
{
  
  int a[500];
  a[0]=2;
  int size=1;
 
  int b[500];
  b[0]=1;
  int size_last=1;  
  int temp[500];

  while(true)
  {
   int k;
   for(k=0;k<size;k++)
   {
      temp[k]=a[k];
   }
     for(int l=(size-1);l>=0;l--)
        cout<<a[l];
       
     cout<<endl;

   long carry=0;
   int j=0;
   for(j=0;j<size;j++)
   {
        int x=a[j]+b[j]+carry;
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
   if(size>100)
   {
      for(int l=(size-1);l>=0;l--)
        cout<<a[l];
       
     cout<<endl;
     return 0; 
   } 
   for(int p=0;p<k;p++)
         b[p]=temp[p];    
  } 
  return 0;
}
/**
void print(int a[],int n)
{
   for(int i=0;i<n;i++)
      cout<<a[i];

  cout<<endl;
}
**/
