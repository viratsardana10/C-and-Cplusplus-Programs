#include <iostream>
using namespace std;

int main()
{
    int a=5;
    int b=3;
    double c;
    c=a/b; //without casting
    cout<<c<<endl;
    c=static_cast<double>(a)/b;//see the difference in output//
    cout<<c<<endl;                                           //both are 
                                                             // same
    c=static_cast<double>(a)/static_cast<double>(b);         // 
    cout<<c<<endl;                                           // 
    system("pause");
    return 0;
}    
