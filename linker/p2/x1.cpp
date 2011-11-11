#include <iostream>
using namespace std;

int x=5;
void func();

int main()
{
	extern int x;
	cout<<"In main: x= "<<x<<endl;
        func();
	return 0;
}
