#include <iostream>
#include <cmath>
using namespace std;

int compute(long );
string decTobin(long );

int main()
{
	long k;
	cin >> k;


	int n = compute(k+1);
	
	long offset = k - (pow(2,n) - 1);
	string binary = decTobin(offset);

	string num;
	int size = binary.size();

	if(size < n) {
		int len = n - size;
		while(len--)
			num.append("5");
	}
	for(int i = 0 ;i < size ; ++i) {
		num.append( (binary[i] == '1') ? "6" : "5");
	}

	cout << num;
	return 0;
}

int compute(long k)
{
	int count = 0;
	while(k)
	{
		++count;
		k = k >> 1;
	}
	return count-1;
}

string decTobin(long n)
{
	string s = "";
	while(n)
	{
		if(n&1)
			s.append("1");
		else s.append("0");

		n = n >> 1;
	}

	int size = s.size();
	for(int i = 0 ; i < (size/2); ++i)
	{
		char temp = s[i];
		s[i] = s[size - 1 - i];
		s[size - 1 - i] = temp;
	}
	return s;
}
