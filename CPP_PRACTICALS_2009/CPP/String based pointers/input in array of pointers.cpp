#include <iostream>
using namespace std;

int main()
{
    char *a[2];
    a[0]=new char;
    a[1]=new char;
    cout<<"Enter two names:";
    cin>>a[0]>>a[1];
    cout<<"_____________________";
    cout<<endl;
    cout<<a[0]<<" "<<a[1]<<endl; 
    system("pause");
    return 0;
}    
