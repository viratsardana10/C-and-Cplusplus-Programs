#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int x=11;
    int* y=&x;
    
    char* c=reinterpret_cast<char*>(y);
    cout<<c<<endl;
    cout<<(*c)<<endl;
    cout<<*(c+1)<<endl;
    
    int size=strlen(c);
    cout<<size<<endl;
    
    int p=static_cast<int>(*c);
    cout<<p<<endl;
    system("pause");
    return 0;
}    
