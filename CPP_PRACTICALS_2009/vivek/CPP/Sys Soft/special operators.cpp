#include <iostream>
using namespace std;

void print(int a,int b)
{
    cout<<a<<"    "<<b<<endl;
}    


int main()
{
    int p=3;
    int q=2;
    print(p,q);
    
    p=p^q;
    print(p,q);
    
    p=p & q;
    print(p,q);
    
    p=p | q;
    print(p,q);
    
    p<<=2;
    q>>=2;
    print(p,q);
    
    cout<<endl;
    system("pause");
    return 0;   
}

    


