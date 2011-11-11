/*
 * team_selection.cpp
 *
 *  Created on: 06-Nov-2010
 *      Author: vivek
 */

#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

#define S(x) scanf("%d", &x)
#define K 450
#define max(a,b) (a > b ? a : b)
#define diff(a,b) (a > b ? a-b : b-a)

int main()
{
	int T;
	while(T--)
	{
		int N;
		S(N);
		int A[N];
		for(int i = 0 ; i < N ; ++i)
			S(A[i]);

		int P[N][N*K+1];
		int S[N*K+1];

		for(int j = 1; j < N*K+1; ++j)
		{
			P[1][j] = (A[0] == j ? 1 : 0);
			S[j] = P[1][j];
		}

		for(int j = 0; j < N*K+1; ++j)
					cout << j << " : " << S[j] << endl;

		for(int i = 1; i < N; ++i)
			for(int j = 1; j < N*K+1; ++j)
			{
				P[i][j] = max(P[i-1][j],P[i-1][j-A[i]]);

				if(P[i-1][j-A[i]] == 1)
					S[j] = S[j-A[i]] + 1;
			}
	/*	for(int j = 0; j < N*K+1; ++j)
			cout << j << " : " << S[j] << endl;
*/
		int sum = 0;
		for(int i = 0 ; i < N; ++i)
			sum += A[i];

//		int s = sum/2;
		int j = 1, min = N*K+1, min_j;
		while(j <= sum/2)
		{
			if(P[N][j] == 1)
				if((sum - 2*j) < min && diff(S[j],S[sum-j]) == 1) {
					min = sum - 2*j;
					min_j = j;
				}
			++j;
		}
		printf("%d %d", min_j, sum - min_j);
	}
	return 0;
}
