#include <iostream>
using namespace std;

int j=0,k=1;
int Recfibo(int );

int main()
{
    for(int i=0;i<=10;i++)
    {
        cout<<"f"<<i<<" = "<<Recfibo(i)<<endl; 
    }    
    system("pause");
    return 0;
}    

int Recfibo(int n)
{
    if(n==0 || n==1)
    return n;
    else return Recfibo(n-1)+Recfibo(n-2);
}    
