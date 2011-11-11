#include <iostream>
using namespace std;

int add=0;
int sum(int [],int);
int main()
{
    int a[]={1,2,3,4,5,6};
    int size=sizeof(a)/sizeof(int);
    cout<<"Size of the array is "<<size<<endl;
    cout<<"Sum of the values of array is "<<sum(a,(size-1));
    cout<<endl;
    system("pause");
    return 0;
}    
/*
int sum(int a[],int n)             
{     
    add+=a[n];
    if(n>0)
    {
       //n=(n-1);
       sum(a,(n-1));
    }  
    return add;     
} 
*/
int sum(int a[],int n)
{
    if(n==0)
      return a[0];
    else
      return a[n]+sum(a,(n-1));
}    
