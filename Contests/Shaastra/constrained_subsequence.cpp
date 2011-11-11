#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <deque>
using namespace std;
typedef map<int, vector<int> , less<int> > Map;
typedef map<int, int, less<int> > Map2;

Map list;  // adjacency list
Map2 set;	// set of all nodes with no incoming edges
deque<int> topOrder;
void visit(int );
Map2 visited;
Map2 length;

int main()
{
	int T;
	fscanf(stdin, "%d", &T);
	while(T--)
	{
		int N, D;
		fscanf(stdin, "%d", &N);
		fscanf(stdin, "%d", &D);
		int a[N];

		for(int i = 0 ; i < N; ++i)
		{
			cin >> a[i];
			length[i] = 0;
			visited[a[i]] = 0;
			set[a[i]] = 0;  // initialize with no incoming edges
		}


		for(int i = 0 ; i < (N-1); ++i)
		{
			for(int j = (i+1) ; j < N; ++j)
			{
				int diff = a[i]-a[j];
				diff = (diff >= 0) ? diff : -diff;
				if(diff <= D) {
					list[a[i]].push_back(a[j]);
				  	set[a[j]] = 1; // an incoming edge	
				}
			}
		}

		/****** Topological sorting *******/
		Map2::iterator iter2;
//		cout << "set of no incoming edges: \n";
		for(iter2 = set.begin(); iter2 != set.end(); ++iter2)
		{	
//			cout << iter2->first << " ";
			if(iter2->second == 0)
				visit(iter2->first); 
		}
//		cout << endl;
	
//		cout << "Topological sorting: \n";
		int size = topOrder.size();

		for(int i = 0 ; i < size; ++i) 
		{
			int v = topOrder[i];
//			cout << topOrder[i] << " : ";

			vector<int> adjacency_list = list[v];
			int len = adjacency_list.size();
			for(int j = 0; j < len; ++j)
			{
				int w = adjacency_list[j];
//				cout << w << "  ";
				if( length[w] <= (length[v] + 1))
					length[w] = length[v] + 1;
			}
//			cout << endl;
		}
		int longest = 0 ;
		for(iter2 = length.begin(); iter2 != length.end(); ++iter2)
		{
			if( (iter2->second) > longest)
					longest = iter2->second;
		}
		printf("%d\n", longest+1);

//		cout << endl;
//		cout << "Length :" << longest << endl;
		/***********Longest Path***********/
			
		
		/**********************************/
/*		Map::iterator iter;
		for(iter = list.begin(); iter != list.end(); ++iter)
		{
			cout << iter-> first << " -> ";
			vector<int> temp = iter->second;
			int size = temp.size();
			for(int i = 0 ;i < size; ++i)
				cout <<	temp[i] << " ";
			cout << endl;
		}
*/		
	}
	return 0;
}

void visit(int n)
{
	if(visited[n] == 0) {
		visited[n] = 1;
		vector<int> adjacency_list = list[n];
		int size = adjacency_list.size();
		for(int i= 0 ; i < size; ++i)
			visit(adjacency_list[i]);
		topOrder.push_front(n);
	}
	return;
}
