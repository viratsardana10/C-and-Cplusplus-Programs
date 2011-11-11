#include <iostream>
using namespace std;

int a[300];

void init()
{
	int fib1 = 1;
	int fib2 = 1;
	int index = 4;
	while(index < 250)
	{
		int j = 1;
		for(int k = 0; k < fib1; ++k)
		{
			a[index] = j;
			cout << index << " : " << a[index] << endl;
			j++; index++;
		}
		index++;
		int temp = fib2;
		fib2 = fib1;
		fib1 = fib1 + temp;

	}	
}

int main()
{
	init();

	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		cout << a[N] << endl;	
	}
}
