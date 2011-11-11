#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int i = 65536 + 32768 + 7;
	short s = i;
	
	int x = 65536-1;
	short _s = x;
	cout << i << "  " << s << "   " << x << "  " << "  " << _s << endl;
	return 0;
}
