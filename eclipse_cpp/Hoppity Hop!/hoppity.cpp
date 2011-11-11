/*
 * hoppity.cpp
 *
 *  Created on: 20-Jan-2011
 *      Author: vivek
 */
#include<iostream>
#include<fstream>

int main(int argc, char *argv[])
{
	std::ifstream input(argv[1]);

	int num;
	input >> num;

	for(int i = 3 ; i <= num ; ++i)
	{
		bool isdiv3 = (i%3 == 0) ? true : false;
		bool isdiv5 = (i%5 == 0) ? true : false;

		if(isdiv3 && isdiv5)
			std::cout << "Hop\n";
		else if(isdiv3)
			std::cout << "Hoppity\n";
		else if(isdiv5)
			std::cout << "Hophop\n";
	}

	return 0;
}
