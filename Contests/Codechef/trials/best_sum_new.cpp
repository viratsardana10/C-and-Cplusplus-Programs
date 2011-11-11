#include <iostream>
#include <stdio.h>
#include <iterator>
#include <map>
using namespace std;

typedef map<int, int, less<int> > Map;

int main()
{
	int N, K, P;
	scanf("%d", &N);
	scanf("%d", &K);
	scanf("%d", &P);

	int smallest = P;
	Map cache;

	for(int i = 0 ; i < N ; ++i)
	{
		int a;
		scanf("%d", &a);
		
		int key = 10*i + i;
		cache[key] = a%P;
		if (cache[key] == K) {
			printf("%d\n", K);
			return 0;
		}
		else if( cache[key] < smallest && cache[key] > K)
			smallest = cache[key];
	}

	for(int r = 1; r < N ; ++r)
	{
		for(int i = 0; i < (N-r); ++i)
		{
			int j = i+r;
			int key = 10*i+j;
		 	cache[key] = (cache[10*i+i] + cache[10*(i+1)+j])%P;
	
			if (cache[key] == K) {
				printf("%d\n", K);
				return 0;
			}
			else if(cache[key] < smallest && cache[key] > K)
				smallest = cache[key];
		}
	}

/*	Map::iterator iter;
	for(iter = cache.begin(); iter != cache.end(); ++iter)
		cout << iter->first << " " << iter->second << endl;
*/
	printf("%d\n", smallest);
	return 0;
}
