/*
 * test.cpp
 *
 *  Created on: 06-Jul-2010
 *      Author: vivek
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int io()
{
	ofstream outfile("input.txt");
	for(long i=1;i<=1000000;i++)
	{
		if(rand()%2==0)
			outfile << ".";
		else outfile << "X";

		if((i%1000) == 0)
			outfile << "\n";
	}
}
