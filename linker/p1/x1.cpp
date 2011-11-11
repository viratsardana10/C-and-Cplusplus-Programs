#include <iostream>
using namespace std;

int x=2;
void foo();
void foobar();

int main()
{
	int x;
	x=40;
	cout<<"In main: x = "<<x<<endl;
	foo();
	cout<<"A: "<<x<<endl;
}

void bar()
{
	x=2*x;
	cout<<"In bar: x = "<<x<<endl;
	foobar();
}
