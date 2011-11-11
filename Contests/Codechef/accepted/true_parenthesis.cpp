#include <iostream>
#include <iomanip>
#include <stdio.h>
using namespace std;
long** T;
long** F;

int main()
{
	string boolean;
	string operators;

	string s;
	cin >> s;
	int n = s.size();
    for(int i = 0 ; i < n; ++i)	
	{
		if(s[i] == 'T' || s[i] == 'F')
			boolean.push_back(s[i]);
		else operators.push_back(s[i]);
	}

	n = boolean.size();
    T = new long*[n];
	F = new long*[n];

	for(int i = 0 ; i < n; ++i)
	{
		T[i] = new long[n];
		F[i] = new long[n];
		T[i][i] = ( boolean[i] == 'T' ) ? 1 : 0;
		F[i][i] = ( boolean[i] == 'F' ) ? 1 : 0;
		for(int j = i+1; j < n; ++j ) 
			T[i][j] = 0;
	}
	
for(int p = 1; p < n; ++p)
	for( int i = 0; i < n-p; ++i)
	{
		int j = i+p;
		
		for( int k = i; k <= (j-1); ++k)
		{
			if( operators[k] == '.' ) {
				T[i][j] += (T[i][k] * T[k+1][j]);
				F[i][j] += ( ( T[i][k] + F[i][k] ) * ( T[k+1][j] + F[k+1][j] ) - ( T[i][k] * T[k+1][j] ) );

			}
			else if( operators[k] == '+' ) {
				T[i][j] += ( ( T[i][k] + F[i][k] ) * ( T[k+1][j] + F[k+1][j] ) - ( F[i][k] * F[k+1][j] ) );
				F[i][j] += ( F[i][k] * F[k+1][j] );
			}
			else if( operators[k] == '*'){
				T[i][j] += ( ( T[i][k] * F[k+1][j] ) + ( F[i][k] * T[k+1][j] ) );
				F[i][j] += ( ( T[i][k] * T[k+1][j] ) + ( F[i][k] * F[k+1][j] ) );
			}
		}
   }
/*	for(int i = 0 ; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
			cout << setw(13) << T[i][j] << " ";
		cout << endl;
	}
*/
	printf("%ld", T[0][n-1]);
	return 0;
}
