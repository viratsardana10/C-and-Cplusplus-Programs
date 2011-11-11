/* CODE: CSEA1 */

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cstring>
using namespace std;

int compare(const void * , const void * );
int LCS(string , string );

int main()
{
	int T;
	scanf("%d", &T);

	for(int t = 1; t <= T; ++t)	
	{
		printf("Case #%d: ", t);

		string a;
		cin >> a;
//		cout << "\n\t" << a << endl;
		if(a == "empty") {
			printf("5\n");
			continue;
		}

		string b;
		cin >> b;
//		cout << "\t" << b << endl;
		int s_a = a.size();
		int s_b = b.size();
		
		char *_a = &a[0];
		char *_b = &b[0];
		qsort(_a, s_a, sizeof(char), compare);
		qsort(_b, s_b, sizeof(char), compare);

		int lcs = LCS(a,b);
		int result = (s_a - lcs) + (s_b - lcs);
		printf("%d\n", result);
	
	}
}

int LCS(string x, string y)
{
	int n = x.size();
	int m = y.size();
	int c[n+1][m+1];
	
	for(int i = 0 ; i <= n ; ++i)
	{
		for(int j = 0 ; j <= m; ++j)
		{
			if ( i == 0 || j == 0)
				c[i][j] = 0;
			else if( x[i-1] == y[j-1] )
				c[i][j] = c[i-1][j-1] + 1;
			else
				c[i][j] = ( c[i-1][j] > c[i][j-1] ) ? c[i-1][j] : c[i][j-1];
		}
	}
	return c[n][m];
}
int compare(const void *c, const void *d)
{
	return ( *(char*)c- *(char*)d );
}
