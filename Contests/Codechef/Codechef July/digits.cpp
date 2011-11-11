/*
 * digits.cpp
 *
 *  Created on: 11-Jul-2010
 *      Author: vivek
 */

#include <iostream>
using namespace std;
void char_to_int(char* );
int* a;

int main()
{
	char* c;
	char* d;
	cin >> c >> d;

	if((((int)c[0])-48)>=5)
		return 0 ;

	return 0;
}

void char_to_int(char* c)
{
	int size = sizeof(c)-1;
//	cout << size << endl;
	a = new int[size];

	for(int i=(size-2);i>=0;i--)
	{
		a[i] = (((int)c[i])-48);
	}
//	cout << endl << c2 << endl;
}
