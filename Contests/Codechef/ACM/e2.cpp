#include <iostream>
#include <map>
#include <stdio.h>
#include <iterator>
using namespace std;

typedef map<int , int , less<int> > Map;

int main()
{
	int T;
	fscanf(stdin, "%d", &T);
	while(T--)
	{
		int N,A,B,C;
		Map cache;
		fscanf(stdin, "%d", &N);
		fscanf(stdin, "%d", &A);
		fscanf(stdin, "%d", &B);
		fscanf(stdin, "%d", &C);
	
		long count = 0;
		for(int a = 0 ; a <= A; ++a)
			for(int b = 0; b <= B; ++b)
					if( (a+b) <= N )
					{	
							cache[N-(a+b)]++;
//							++count;
					}

		Map::iterator iter;
		for(iter = cache.begin(); iter != cache.end(); ++iter)
		{	
			int value = iter->first;
			if(C <= value)
				count += (C+1);
			else {
				count += (iter->second + 1);
			}
			count += iter->second;
		}
		fprintf(stdout, "%ld\n", count);

	}
	return 0;
}


