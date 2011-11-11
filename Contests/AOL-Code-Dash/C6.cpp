#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for(int i = 0 ; i < (n-1); ++i)
		cout << i << " " << i+1 << endl;
	cout << n-1 << " " << 0 << endl;

	return 0;
}
