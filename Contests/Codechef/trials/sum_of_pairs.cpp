// Task to find the longest arithmetic progression

#include <iostream>
using namespace std;

int longestArithProg(int* ,int );

int main()
{
	int N;
	cin >> N;
	int X[N];

	for(int i = 0; i < N; ++i)
		cin >> X[i];
	
	int longest = longestArithProg(X, N);
	cout << longest << endl;

	return 0;
	
}

int longestArithProg(int *a, int n)
{
	int L[n][n];
	for(int i = 0 ; i < n; ++i)
		for(int j = 0 ; j < n ; ++j)	
			L[i][j] = 0;

	int l = 2;

	for(int j = n-2; j >=0; --j)
	{
		int i = j-1;
		int k = j+1;

		while( i >= 0 && k <= (n-1))
		{
			if ( (a[i] + a[k]) < (2*a[j]) )
				++k;
			else if ( (a[i] + a[k]) > (2*a[j]) )
			{
				L[i][j] = 2;
				--i;
			}
			else 
			{
				L[i][j] = L[j][k] + 1;
				l = (l > L[i][j]) ? l : L[i][j];
				--i;
				++k;
			}
		}
		
		while ( i >= 0 ) {
			L[i][j] = 2;
			--i;
		}
//		cout << "asdf: " << L[i][j] << endl;

	}

	for(int i = 0 ; i < n; ++i)
		for(int j = 0 ; j < n ; ++j)	
			cout << L[i][j] << " ";

	cout << endl;
	return l;
}
