#include <iostream>
using namespace std;

int series(int);

int main()
{
    int m;
    cout<<"Enter a positive integer: ";
    cin>>m;
    cout<<series(m)<<endl;
    
    system("pause");
    return 0;
}

int series(int n)
{
    int sum=0;
    int j=1;
    for(int i=1;i<=n;i++)
    {
        int square=(2*i-1)*(2*i-1);
        if((j%2)==0)
        {
            sum-=square;
        }
        else
          sum+=square;
        
        j++;                        
    } 
    return sum;   
}        
