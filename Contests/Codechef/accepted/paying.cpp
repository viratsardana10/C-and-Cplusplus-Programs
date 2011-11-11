/*
*    @ author: Vivek Prakash || Feb. 17,2010
*    This program finds the subset of a set whose elements sum
*    to give a predefined value;
*    It evaluates the power set and then examines all its elements;
*/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int t;
  cin >> t;
  for(int i=0;i<t;i++)
  {
    int N;
    cin >> N;
    
    int M; 
    cin >> M;

    int money[N];
    for(int i=0;i<N;i++)
    {
        cin >> money[i];
    }

    
    long size=pow(2,N);
    bool flag; 
    for(long i=1;i<size;i++)
    {
         flag=false;
         int value=0;
         for(int j=0;j<N;j++)
         {
             if(i & (1<<j))
             {
                  value+=money[N-1-j];
             }
         }
         if(value==M)
         {
             cout<<"Yes"<<endl;
             flag=true;
             break;
         }
    }
    if(flag==false)
    {
       cout<<"No"<<endl;
    }
   }
    return 0; 
}



