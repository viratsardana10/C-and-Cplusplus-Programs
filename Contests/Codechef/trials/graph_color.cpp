/*
 * author : Vivek Prakash
 *   date : 01-02-2011   
 *   Code : THREECLR 
 */

#include <iostream>
#include <queue>
#include <map>
#include <queue>
#include <stdio.h>
using namespace std;
/*==================code for taking fast integer input==================*/
int sign;
int ch;
inline void S( int &x ) {
	x=0;
	while((ch<'0' || ch>'9') && ch!='-' && ch!=EOF)	ch=getchar_unlocked();
	if (ch=='-')
		sign=-1 , ch=getchar_unlocked();
	else
		sign=1;
	do
		x=(x<<3)+(x<<1)+ch-'0';
	while((ch=getchar_unlocked())>='0' && ch<='9');
	x*=sign;
}
/*======================================================================*/

#define INF 99999
//typedef map<int, vector<int> > Map;
struct graph {
	vector<int> adj_list;
	int color;
} *node; 

void BFS(int );
int main()
{
	int T;
	scanf("%d", &T);
	while(T--) {
		int n, m;
		S(n); S(m);

		node = new struct graph[n+1];
		int u, v;
		for(int i = 0 ; i < m ; ++i) {
			S(u); S(v);
			node[u].adj_list.push_back(v);
			node[v].adj_list.push_back(u);
		}

		for(int i = 1 ; i <= n ; ++i)
			node[i].color = INF;

		for(int i = 1 ; i <= n ; ++i)
			if(node[i].color == INF)
				BFS(i);		
		for(int i = 1 ; i <= n ; ++i)
			printf("%d ", node[i].color);
		printf("\n");
	}
}

void BFS(int source)
{
	queue<int> nodes;	
	nodes.push(source);
	node[source].color = 1;	
	
	while(!nodes.empty()) {
		int v = nodes.front();
		nodes.pop();
		vector<int> list = node[v].adj_list;
		int size = list.size();
		for(int i = 0 ; i < size; ++i) {
			int w = list[i];
			if(node[w].color >= node[v].color) {
				node[w].color = node[v].color + 1;	
				nodes.push(w);
			
			}
		}
	}
}

