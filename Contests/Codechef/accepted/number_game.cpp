#include <iostream>
#include <stdio.h>

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		long N;
		scanf("%ld", &N);
		if(N%2 == 0)
			printf("ALICE\n");
		else printf("BOB\n");
	}
	return 0;
}
