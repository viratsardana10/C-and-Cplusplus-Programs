#include <iostream>
using namespace std;

long RecPower(int ,int );
int main()
{
    int n,m;
    do
    {
    cout<<"Enter two positive integers:";
    cin>>n>>m;
    if(n<0||m<0)
    cout<<"This is not a valid input."<<endl;
    }
    while(n<0||m<0);
        
    cout<<n<<"^"<<m<<" is "<<RecPower(n,m)<<endl;
    system("pause");
    return 0;    
}    

long RecPower(int a,int b)
{
    if(b==0)
    return 1;
    else return a*RecPower(a,(b-1));
}    
