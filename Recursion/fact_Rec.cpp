#include <iostream>
using namespace std;
int fact(int);
int main ()
{
    int input;
    cin >>input;
    cout<<"\nfact= "<<fact(input);
    system("pause");
    return 0;
}
int fact (int x)
{
    if (x>1)
    {
    return (x*fact(x-1));
    }
    else
    {
    return 1;    
    }
    ;
}        
