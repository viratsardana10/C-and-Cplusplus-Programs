/*
*	CODE: PERMUT2
*/

#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	while( n != 0)
	{
		int a[n+1];
		a[0] = 0;
		for(int i = 1 ; i < (n+1) ; ++i)
			cin >> a[i];

		bool flag = true;
		int limit = (n/2) + 2;
		for(int i = 1; i < limit ; ++i)
		{
			if(a[a[i]] != i)
			{
				cout << "not ambiguous" << endl;
				flag = false;
				break;
			}
		}
		if(flag)
			cout << "ambiguous" << endl;

		cin >> n;
	}
	return 0;
}
