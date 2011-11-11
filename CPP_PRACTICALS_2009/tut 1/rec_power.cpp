#include <iostream>
using namespace std;

int power(int,int);

int main()
{
    int base,expo;
    cout<<"Enter base:";
    cin>>base;
    
    cout<<"Enter exponent:";
    cin>>expo;
    cout<<"power("<<base<<","<<expo<<") = "<<power(base,expo)<<endl;
    
    system("pause");
    return 0;
}

int power(int a,int b)
{
    if(b==1)
      return a;
    else
      return a*power(a,(b-1));
}
