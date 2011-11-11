#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int N, K, P;
	scanf("%d", &N);
	scanf("%d", &K);
	scanf("%d", &P);
	
	int A[N];
	for(int i = 0 ; i < N ; ++i)
		scanf("%d", A+i);

	int M[N];
	int smallest = P;

	M[0] = A[0]%P;
	if(M[0] == K) {
		printf("%d\n", K);
		return 0;
	}
	else if( M[0] > K && M[0] < smallest )
			smallest = M[0];

	
	for(int i = 1; i < N; ++i)
	{
		int x = (M[i-1] + A[i])%P;
		int y = A[i]%P;
		M[i] = ( x < y ) ? x : y;
	
		if(M[i] == K) {
			printf("%d\n", K);
			return 0;
		}
		else if( M[i] > K && M[i] < smallest )
			smallest = M[i];
	}

	printf("%d\n", smallest);
	return 0;
}

