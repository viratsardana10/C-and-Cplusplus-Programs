#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

void visit(int ,int );

struct vertex {
	vector<int> list;
	bool visited;
	bool set;	// set of all nodes ( with no incoming edges )
	bool inProg;
	int length;
} *node;

bool isCycle = false;

int main()
{
	int T;
	fscanf(stdin, "%d", &T);
	while(T--)
	{
		int N, M;
		fscanf(stdin, "%d", &N);
		fscanf(stdin, "%d", &M);
		
		++N;
		node = new struct vertex[N];

		node[0].length = 0;

		for(int i = 1 ;i < N; ++i)
		{
			node[i].length = 999999;
			node[i].visited = false;
			node[i].set = false;  // initialize with no incoming edges
			node[i].inProg = false;
		}
	

		for(int i = 0 ; i < M; ++i)
		{
			int a,b;
			scanf("%d%d", &a, &b);
			node[a].list.push_back(b);
			node[b].set = true; // incoming edge
		}

		/****** Topological sorting *******/
		bool flag = true;
		for(int i = 1 ; i < N; ++i)
		{	
			if(!node[i].set) {
				flag = false;
				visit(i,0);
			}
		}
		
		if(flag || isCycle)
		{
			printf("IMPOSSIBLE\n");
			isCycle = false;
			continue;
		}

		/***********Longest Path***********/

		int longest = 0 ;
		for(int i = 1; i < N; ++i)
		{
			if( node[i].length > longest)
					longest = node[i].length;
		}
		printf("%d\n", longest);
		
	}
	return 0;
}


void visit(int n, int m)
{
	if(isCycle)
		return;

	if(!node[n].visited) {
		if( node[n].length > (node[m].length + 1) )
			node[n].length = node[m].length + 1;

		node[n].visited = true;
		node[n].inProg = true;

		vector<int> adjacency_list = node[n].list;
		int size = adjacency_list.size();
		
		for(int i= 0 ; i < size; ++i) {
		    int w = adjacency_list[i];
			if(node[w].inProg)
			{
				isCycle = true;
				return;
			}
			if(!node[w].visited)
				visit(w, n);
		}
		
		node[n].inProg = false;
	}
	return;
}
