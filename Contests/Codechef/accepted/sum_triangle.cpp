#include <iostream>
using namespace std;

int main()
{
   int cases;
   cin >> cases;
   while(cases--)
   {
       int n;
       cin >> n;
       int size=n*(n+1)/2;
       int a[size];
       for(int i=0;i<size;i++)
           cin >> a[i];
        
       int k=size-n-1;
       for(int j=n-1;j>=1;j--)
       {
           for(int i=0;i<j;i++)
           {
              a[k]=a[k]+((a[k+j]>a[k+j+1])?a[k+j]:a[k+j+1]);
              k--;
           }
       }
       cout << a[0]<<endl;
   }
   return 0;
}
