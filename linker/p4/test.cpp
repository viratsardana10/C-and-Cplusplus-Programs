#include <iostream>
using namespace std;
extern int func(int );
int j=20;

int main()
{
	int num;
	num=func(3);
	cout<<num;

	return 0;
}
