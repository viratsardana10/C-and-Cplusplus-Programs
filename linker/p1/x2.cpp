#include <iostream>
using namespace std;
static int x=5;
void bar();

void foo()
{
	x=x+10;
//	cout<<"In foo: x = "<<x<<endl;
	bar();
}

void foobar()
{
	extern int x;
	x+=3;
	cout<<"B: "<<x<<endl;
}
