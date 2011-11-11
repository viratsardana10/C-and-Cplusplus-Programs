#include <iostream>
#include <stdio.h>
using namespace std;

int** A;
int main()
{
	int N, K, P;
	scanf("%d", &N);
	scanf("%d", &K);
	scanf("%d", &P);

	int smallest = P;

	A = new int*[N];
	for(int i = 0 ; i < N ; ++i)
	{
		A[i] = new int[N];
		scanf("%d", &A[i][i]);
		A[i][i] %= P;
		if(A[i][i] < smallest && A[i][i] >= K)
			smallest = A[i][i];
	}

	for(int p = 1; p < N ; ++p)
		for(int i = 0; i < N; ++i)
		{
			int j = i+p;
			if(j < N)
			{
				A[i][j] = (A[i][i] + A[i+1][j])%P;
				if(A[i][j] < smallest && A[i][j] >= K)
					smallest = A[i][j];
			}
		}

	printf("%d\n", smallest);
	return 0;
}
