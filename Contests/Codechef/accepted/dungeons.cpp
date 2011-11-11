/* CODE: NDUNGEON */

#include <iostream>
#include <stdio.h>
#include <list>
#include <iomanip>
using namespace std;

#define s(x) scanf("%d", &x)
#define sl(x) scanf("%ld", &x)
#define FOR(A,B,C) for(int i = A; i < B; i += C)

int main()
{
	int M,N;
	s(M); s(N);
	
	M = M*N;
	int A[M], dist[M];
	typedef list<int> List;
	List Q;		// list of all nodes
	List::iterator iter;

	s(A[0]);
	Q.push_back(0);
	dist[0] = 0;

	FOR(1,M,1) 
	{
		s(A[i]);
		dist[i] = 9999999;
		Q.push_back(i);
	}
	
	int a, b, T;
	s(a); s(b); s(T);
	int dest = N*(a-1) + (b-1);

	int _dist;
/*	int cache[4];
	FOR(0,4,1)
		cache[i] = -1;
*/
	while(!Q.empty())
	{
		int temp = 9999999;
		int u;

		// find node in list with smallest distance
		for(iter = Q.begin(); iter != Q.end(); ++iter)
		{
			if(dist[(*iter)] < temp) {
				u = *iter;
				temp = dist[u];
			}
		}
//		cout << u << " ->  " << dist[u] << " \n ------ \n ";

		if( u == dest) {
			_dist = dist[u] + A[u];
			break;
		}
		
		Q.remove(u);  // remove node with smallest distance
			
		int adjacent[4] = { (u%N == 0) ? -1 : u-1, u+1, u+N, u-N };
		FOR(0,4,1)
		{
			int v = adjacent[i];
			if(v >= 0 and v < M)
			{
				int alt = dist[u] + A[u]; 
				if( alt < dist[v] )
					dist[v] = alt;
//				cout << setw(7) << v << " -> " << dist[v] << endl;
			}
		}
	} // end while
	int T_left = T - _dist;
	( T_left >= 0) ? printf("YES\n%d\n", T_left) : printf("NO\n");	
	return 0;	

}
