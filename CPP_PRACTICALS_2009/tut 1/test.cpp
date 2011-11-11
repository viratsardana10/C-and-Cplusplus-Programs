#include <iostream>
using namespace std;

int main()
{
    char* a=new char;
    cin>>a;
    cout<<strlen(a)<<endl;
    cout<<*(a+4);
     
    cout<<endl;
    system("pause");
    return 0;
}
