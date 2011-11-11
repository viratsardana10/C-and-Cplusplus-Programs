#include <iostream>
using namespace std;

int main()
{
    int a=1;
    int b=2;
    int c=++a;
    cout<<c<<"   "<<a<<endl;
    int d=b++;
    cout<<d<<"   "<<b<<endl;
    cout<<++(a);  //this is correct.
    // cout<<++(a+1);  is a syntax error.operator can only be used on a variable name or reference.
    cout<<endl;
    system("pause");
    return 0;
}    
    
    
