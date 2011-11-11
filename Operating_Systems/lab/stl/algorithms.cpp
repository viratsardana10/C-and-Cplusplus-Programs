/*
 * algorithms.cpp
 *
 *  Created on: 02-Aug-2010
 *      Author: vivek
 */
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
	const int size = 4;
	int a[size] = {1, 2, 3, 4};

	ostream_iterator<int> output(cout, " ");
	copy(a, a+size, output);
	fill(a, a+size, 1);
	copy(a, a+size, output);
	fill_n(a, 2, 2);
	copy(a, a+size, output);
	return 0;
}
