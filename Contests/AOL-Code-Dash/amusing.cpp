#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
	string* cache;
	cache = new string[70];
	
	cache[0] = "0";
	cache[1] = "5";
	cache[2] = "6";
	
	for( int i = 2; i <= 4;  ++i)
	{
		long start = pow(2,i) - 1;
		long end = 2*start;
		long mid = (start + end)/2;
		cout << start << "  " << mid << "  " << end << endl;

		int j = i-1;
		long prev1 = pow(2,j) - 1;
		long prev2 = prev1;
	
		for(long k = start; k <= mid; ++k)
		{
			cache[k] = "5";
			cache[k].append(cache[prev1++]);
			cout << cache[k] << "  ";
		}

		for(long k = mid+1; k <= end; ++k )
		{
			cache[k] = "6";
			cache[k].append(cache[prev2++]);
			cout << cache[k] << "  ";
		}
		cout << endl;
	/*	ofstream outfile("output.txt");
		for(int c = start; c <= end; ++c)
			outfile << cache[c] << endl;
	*/
	}

	return 0;
}
