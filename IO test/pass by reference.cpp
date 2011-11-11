#include <iostream>
using namespace std;

void f1(int x,int* y)//pass by reference with pointer arguments
{
    x=11;
    *y=22;
}    

void f2(int x,int& y)//pass by reference with refernce arguments
{
    x=33;
    y=44;
}    

int main()
{
    int x=1,y=2;
    int* yPtr=&y;
    cout<<x<<"    "<<y<<endl;
    f1(x,yPtr);
    cout<<x<<"    "<<y<<endl;
    f2(x,y);
    cout<<x<<"    "<<y<<endl;
    
    int z;
    int* zPtr=&z;
    z=2;
    cout<<z<<"    "<<zPtr<<endl;
    
    system("pause");
    return 0;
       
}    
