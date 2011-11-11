#include <iostream>
using namespace std;

//extern int x;
//int x=1;
//static int x=10;

void func()
{
	extern int x;
	cout<<"In func: x = "<<x<<endl;

}
