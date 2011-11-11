/*
 * ripple.cpp
 *
 *  Created on: 24-Jul-2010
 *      Author: vivek
 */

#include <iostream>
#include <cstring>
using namespace std;

string binary(long );

int main()
{
	int cases;
	cin >> cases;
	while(cases--)
	{
		int num;
		string a,b;
		cin >> num >> a >> b;
		long count = 0;

		while(a != b)
		{
			int i = num-1;
			while(a[i]=='1')
			{
				a[i] = '0';
				count++;
				i--;
			}
			a[i] = '1';
			count++;
		}
		cout  << binary(count) << endl;
	}
	return 0;
}

string binary(long decimal)
{
    if(decimal == 0) return "0";
    char NUMS[] = "01"; // Characters that may be used
    string result = ""; // Create empty string ready for data to be appended

    do{
         result.push_back(NUMS[decimal%2]);
        // Append the appropriate character in NUMS based on the equation decimal%base

         decimal /= 2; // Calculate new value of decimal
    }while(decimal != 0); // Do while used for slight optimisation
//    return result;  // it returns the string with binary code in inverted order## care taken in modular_exponentiation() for this## it prevents the following more computationally expensive return.

    return string(result.rbegin(), result.rend());// using std::string() constructer with iterators to reverse the string
}

