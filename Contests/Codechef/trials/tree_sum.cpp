#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

void visit(int ,int );
long long modular_exponentiation(long a, long b);

#define modulo 1000000007
typedef map<int, long, less<int> > Map;

struct vertex {
	int list[2];
	bool visited;
	int length;
	Map cache;
} *node;

int inProgNode;

int main()
{
	int T;
	fscanf(stdin, "%d", &T);
	while(T--)
	{
		int N, K;
		fscanf(stdin, "%d", &N);
		fscanf(stdin, "%d", &K);
		
		++N;
		node = new struct vertex[N];

		node[0].length = 0;

		for(int i = 1 ;i < N; ++i)
		{
			node[i].list[0] = node[i].list[1] = 0;
			node[i].length = 999999;
			node[i].visited = false;
		}
	

		for(int i = 1 ; i < (N-1); ++i)
		{
			int a,b;
			scanf("%d%d", &a, &b);
			++a; ++b;

			if(node[a].list[0] == 0)
				node[a].list[0] = b;
			else node[a].list[1] = b;
		
			if(node[b].list[0] == 0)
				node[b].list[0] = a;
			else node[b].list[1] = a;

		}

		/****** Topological sorting *******/
	
		for(int i = 1 ; i < N; ++i)
		{
				inProgNode = i;
				visit(i,0);
				long long sum = 0;

				for(int i = 1; i < N; ++i)
				{
					sum += modular_exponentiation(node[i].length, K);			
					node[i].length = 999999;
					node[i].visited = false;
				}
				printf("%lld\n", sum);
		}
		printf("\n");
	}
	return 0;
}


void visit(int n, int m)
{
	if(!node[n].visited) {
		if(node[n].cache.count(inProgNode) == 1)
		{
			node[n].length = node[n].cache[inProgNode];
		}

		else if( node[n].length > (node[m].length + 1) )
		{
			node[n].length = node[m].length + 1;
			node[inProgNode].cache[n] = node[n].length;
		}

//		cout << n << " length " << node[n].length << endl;
		node[n].visited = true;
		
		for(int i= 0 ; i < 2; ++i) {
		    int w = node[n].list[i];
			if(!node[w].visited)
				visit(w, n);
		}
	}
	return;
}

long long modular_exponentiation(long a, long b)
{
   long long result = 1;
   long long power = a;
   while(b)
   {
      if(b&1)
          result=(result*power)%modulo;
      
       power=(power*power)%modulo;
       b >>= 1;
   }
   return result;
}
