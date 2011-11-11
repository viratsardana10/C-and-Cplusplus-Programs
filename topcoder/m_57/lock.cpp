#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  ifstream infile("input");
  int k=0;
  for(long t=0;t<720*7*8*9*10;t++)
{
  int a;
  infile>>a;
  int size=10;
  int b[size];
  int d=a;

  for(int i=(size-1);i>=0;i--)
  {
  b[i]=a%10;
  a=a/10;
  }
  
  int j=b[0];
  if(j==0)
     continue;
  int i;
  for(i=1;(i<size-1);i++)
  {
     if(b[j]==0)
         break;
     else j=b[j];
  }
  if(i==(size-1))
  {
//     cout<<d<<"\n";
     k++;
  } 
}
  cout<<k<<endl;
 return 0;  
}
