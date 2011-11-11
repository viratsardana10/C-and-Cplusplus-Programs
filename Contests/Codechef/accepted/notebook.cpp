#include <stdio.h>
#include <string.h>

int F[27];
int A[27];
int C[27];
char G[27];

void init();
int yes();

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%s", G);
		init();
		if( yes() )
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}

void init()
{
	for(int i = 0 ; i < 26; ++i)
	{
		A[i] = G[i] - 'A';
		F[i] = 1;
		C[i] = 0;
	}
}

int yes()
{
	for(int i = 0 ; i < 26; ++i) if( F[i] )
	{
		int count = 1;
		int j = A[i];
		F[i] = 0;
		while(j != i)
		{
			F[j] = 0;
			j = A[j];
			++count;
		}
		C[count]++;
	}

	for(int i = 2; i < 27; i += 2)
	{
		if( C[i]) {
			if( C[i]%2 )
				return 0;
		}
	}
	return 1;
}
