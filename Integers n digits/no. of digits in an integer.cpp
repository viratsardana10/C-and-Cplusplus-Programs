#include <iostream>
using namespace std;

int main()
{
    int m;
    int* a;
    cout<<"Enter a positive integer:";
    cin>>m;
    
    int n=m;
    int i=0;
    while(n>0)
    {
        n=(n/10);
        i++;
    } 
    
    a=new int[i];
    i=0;
    while(m>0)
    {
        a[i]=(m%10);
        m=(m/10);
        i++;
    }
        
    cout<<"No. of digits is "<<i<<endl;
    cout<<"Digits are:  ";
    for(int j=(i-1);j>=0;j--)
    {
        cout<<a[j]<<"   "; 
    } 
    cout<<endl;   
    system("pause");
    return 0;
}        
