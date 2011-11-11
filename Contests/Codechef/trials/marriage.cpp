/*
 * author : Vivek Prakash
 *   date : 31-01-2011   
 *   Code : STABLEMP
 */

#include <iostream>
#include <stdio.h>
#include <map>
#include <iterator>

using namespace std;

typedef map< int,int > Map;

int main()
{
	int T;
	scanf("%d", &T);
	while(T--) {
		int N;
		scanf("%d", &N);
		int w[N+1][N+1];
		int m[N+1][N+1];

		for(int i = 1 ; i <= N ; ++i)
		{
			int w_index;
			scanf("%d", &w_index);
			int t;
			for(int j = 1 ; j <= N ; ++j)
			{
				scanf("%d", &t);
				w[w_index][j] = t; 
			}
		}
	
		for(int i = 1 ; i <= N ; ++i)
		{
			int m_index;
			scanf("%d", &m_index);
			int t;
			for(int j = 1 ; j <= N ; ++j)
			{
				scanf("%d", &t);
				m[m_index][j] = t; 
			}
		}

		Map women;
		
		for(int i = 1 ; i <= N ; ++i)
		{
			for(int j = 1 ; j <= N ; ++j)
			{
				if(!women[m[i][j]]) {
					printf("%d %d\n", i, m[i][j]);
					women[m[i][j]] = 1;
					break;
				}
			}			
		}
	}
}
