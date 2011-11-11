/* CODE: CSEA3 */

#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	while(1) 
	{
		int M;
		scanf("%d", &M);
		if(M == 0)
			return 0;
	
		string s;
		cin >> s;
		int size = s.size();
		int N = size/M;
		if(size%M != 0) ++N;

		char a[N][M];
	
		int k = 0;
		bool flag = true;
		for(int i = 0 ; i < N; ++i)
		{
			if(flag) {
				for(int j = 0; j < M; ++j)
					a[i][j] = s[k++];
				flag = false;
			} else {
				for(int j = (M-1); j >= 0; --j)
					a[i][j] = s[k++];
				flag = true;
			}
		}
		
		for(int i = 0 ; i < M; ++i) 
		{
			for(int j = 0 ; j < N ; ++j)
				printf("%c",a[j][i]);
		}
		printf("\n");
	}
	return 0;
}
