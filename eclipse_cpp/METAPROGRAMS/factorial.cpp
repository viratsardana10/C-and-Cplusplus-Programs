/*
 * factorial.cpp
 *
 *  Created on: 10-Nov-2010
 *      Author: vivek
 */

#include <iostream>
#include "utils.h"
using namespace std;

int main()
{
	STATIC_ASSSERT(sizeof(int) == sizeof(long), SIZEOF_INT_NOT_EQUAL_TO_LONG);
	const int result = Factorial<5>::value;
	const int r1 = Accumulate<5,Square>::value;
	const int r2 = Accumulate<5, Factorial>::value;
	cout << result << endl << r1 << endl << r2 << endl;

	return 0;
}
