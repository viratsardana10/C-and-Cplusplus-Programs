#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int x;
	double y;
	cin >> x >> y;

	cout << fixed;

	if ( x > (y - 0.5) || (x%5) != 0)
		cout << setprecision(2) << y;
	else
	{
		double balance = (y - 0.5) - x;
		cout << setprecision(2) << balance;
	}
	return 0;

}
