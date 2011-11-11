#include <iostream>
using namespace std;

void tripleByValue(int);
void tripleByReference(int&);

int main()
{
    int count;
    cout<<"Enter a positive integer:";
    cin>>count;
    
    cout<<"count = "<<count<<endl;
    tripleByValue(count);
    cout<<"After pass by value, count = "<<count<<endl;
    tripleByReference(count);
    cout<<"After pass by Reference, count = "<<count<<endl;
    
    system("pause");
    return 0;
}

void tripleByValue(int a)
{
     a*=3;
}

void tripleByReference(int& a)
{
     a*=3;
}
