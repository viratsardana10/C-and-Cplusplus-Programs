#include <stdio.h>

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int K;
		scanf("%d", &K);
		if( K <= 25 )
		{
			for(int i = K; i >= 0; --i)
				printf("%c", 'a'+i);
			printf("\n");
			continue;
		}

		int k = K - 25;
		int count = 0;
		while( k > 25)
		{
			++count;
			k -= 25;
		}

		for(int i = k; i >= 0; --i)
			printf("%c", 'a'+i);
		while(count--)
			printf("zyxwvutsrqponmlkjihgfedcba");
		for(int i = 25; i >= 0; --i)
			printf("%c", 'a'+i);

		printf("\n");
	}
	return 0;
}
