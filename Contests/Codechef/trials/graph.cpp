/*
 * author : Vivek Prakash
 *   date : 01-02-2011   
 *   Code : THREECLR 
 */

#include <iostream>
#include <vector>
#include <stdio.h>

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
void BFS(int );

#define INF 99999999

struct graph {
	int adj_list[501];
	int color;
	int size;
} *node; 

int n, m;

int main()
{
	int T;
	scanf("%d", &T);
	while(T--) {
		S(n); S(m);
	
		node = new struct graph[n+1];
		for(int i = 1 ; i <= n ; ++i) {
			node[i].color = INF;
			node[i].size = 0;
		}

		int u, v;
		for(int i = 0 ; i < m ; ++i) {
			S(u); S(v);
			node[u].adj_list[node[u].size] = v;
			node[u].size += 1;	
		
			node[v].adj_list[node[v].size] = u;
			node[v].size += 1;	
		}
	
		for(int i = 1 ; i <= n ; ++i) {
			if(node[i].color == INF) 
				BFS(i);		
		}


		for(int i = 1 ; i <= n ; ++i)
			printf("%d ", node[i].color);

		printf("\n");
	}
	return 0;
}

void BFS(int source)
{
	int QS = 10000;
	int queue[QS];	
	int rear = 0;
	int front = 0;
	rear = (rear + 1)%QS;
//	++rear;
	queue[rear] = source;

	node[source].color = 1;	
	
	while(front != rear) {
		front = (front + 1)%QS;
//		++front;
		int v = queue[front];
		int len = node[v].size;
		for(int i = 0 ; i < len ; ++i) {
			int w = node[v].adj_list[i];
			if( (node[w].color) >= (node[v].color) ) {
					node[w].color = node[v].color + 1;				
					rear = (rear + 1)%QS;
//					++rear;
					queue[rear] = w;
			}
		}	
	}
}

