#include <iostream>
#include <stdio.h>
using namespace std;

#define s(x) scanf("%d", &x)

int main()
{
	int T;
	s(T);
	for(int t = 1; t <= T; ++t)
	{
		int N;
		s(N);
		int a[N][N];
		
		int count = N/2;
		if(N%2 != 0)
			++count;

		int k = 0;
		while(count--) {
			int i = k;
			int j = k;
			for( ; j < N-k; ++j)
				s(a[i][j]);
			++i; --j;

			for( ; i < N-k; ++i)
				s(a[i][j]);
			--j; --i;
		
			for( ; j >= k; --j)
				s(a[i][j]);
			--i; ++j;
		
			for( ; i > k; --i)
				s(a[i][j]);

			++k;
		}
		
		printf("Case #%d:\n", t);
	
		int Q;
		s(Q);
//		int mem[Q][4];
//		long long cache[Q];

//		int done = 0;
		for(int q = 0; q < Q; ++q)
		{
			int x1,y1,x2,y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
//			mem[q][0] = x1; mem[q][1] = y1; mem[q][2] = x2; mem[q][3] = y2;

/*			bool f = false;
			for(int i = 0; i < done; ++i)
			{
				if( mem[i][0] == x1 && mem[i][1] == y1 && mem[i][2] == x2 && mem[i][3] == y2)
				{
					f = true;
					printf("%lld\n", cache[i]);
					break;
				}
			}
			++done;
			if(f) continue;	
*/			
			long long sum1 = 0;
			long long sum2 = 0;

			for(int i = x1; i <= x2; ++i)
			{
				int flag = (i%2 == 0) ? 0 : 1;

				for(int j = y1; j <= y2; j += 2)
				{
						if(flag)
							sum1 += a[i][j];
						else sum2 += a[i][j];
						 
				}

				for(int j = y1+1; j <= y2; j += 2)
				{
						if(flag)
							sum2 += a[i][j];
						else sum1 += a[i][j];
				}
			}
			long long cache = ( sum1 < sum2 ) ? sum1 : sum2;
			printf("%lld\n", cache);
		}
		printf("\n");
	}
}
