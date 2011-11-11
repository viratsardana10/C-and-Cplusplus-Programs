/* Amusing numbers: 5 6 55 56 65 66 .... 
*  Approach: Find k,n, o, m =(n-1); if(O > 2^m) O-= 2^m; K = 2^m - 1 + O
*/

#include <iostream>
using namespace std;

long compute(long ,long& ,long& ); 

int main()
{
	long k;
	cin >> k;
	
	int cache[30] = {5, 6, 55, 56, 65, 66, 555, 556, 565, 566, 655, 656, 665, 666,
					 5555, 5556, 5565, 5566, 5655, 5656, 5665, 5666, 6555, 6556, 6565, 6566, 6655, 6656, 6665, 6666};
	short a[200];
	int size = 0;

	while(k>30) {
		long offset = 0;
		long power = 0; // 2^(n-1)
		long n = compute(k, offset, power);  /* (2^n-1) <= k */
//		cout << k << "   " << n << "  " << offset << "   " << power << endl;
		long m = n-1;
		if(offset > power) { 
			offset -= power;
			a[size++] = 6;
		}
		else a[size++] = 5;

		k = power - 1 + offset; 
	}
	
	for(int i = 0; i < size; i++)
		cout << a[i];

	cout << cache[k-1];
	return 0;
}

long compute(long k, long& offset, long& power)
{
	if(k == 1) return 1;

	long result = 2;
	long n = 1;
	while((result-1) < k) {
		result *= 2;
		n++;
	}
	
	if((result - 1) == k) 
	{
		offset = 0;
		power = result/2;
		return n;
	}
	
	if(result > k) {
		offset = k - (result/2) + 1 ;
		power = result/4;
	}
	return (result > k) ? n-1 : n;
}
