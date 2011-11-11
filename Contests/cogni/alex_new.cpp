#include <iostream>
#include <map>
#include <set>
#include <list>
#include <iterator>
#include <stack>
#include <vector>
using namespace std;

#define INF 99999999

typedef set<string> node_set;
typedef map<string, node_set> Map;
typedef list<string> n_stack;
typedef map<int, vector<int> > Map_scc;
Map node;

int N, R;
string source;

node_set all_nodes;

map<string, int> node_index;
map<string, int> node_lowlink;
list<string> node_stack;

int index;

int scc_count = 1;
vector<node_set> sccs;
Map_scc scc_edge;  // graph of sccs
int scc_source;
list<int> scc_topsort;
int vtime = 0;
struct vertex {
	bool visited;
	int parent;	
	int child;
	int length;
} *scc_node;

/*
struct node_vertex {
	int dist;
	string previous;
	string name;
} *house;
*/
list<int> visit_order;
vector<string> node_order;

map<string, int> node_dist;
map<string, string> node_prev;

void SCC();
void tarjan(string );
void SCC_GRAPH();
void _SCC_SOURCE_();
void _SCC_TOPSORT_();
void visit(int ,int );
void shortest_path(string u, string v);

int min(int ,int );

int main()
{
	int T;
	cin >> T;
	while(T--) {
		cin >> N >> R;

		//house = new struct node_vertex[N];		
		string s1, s2;
		for(int i = 0 ; i < R; ++i) {
			cin >> s1 >> s2;
			node[s1].insert(s2);		
		}

		cin >> source;
		
		for(Map::iterator iter = node.begin(); iter != node.end(); ++iter)
		{
			all_nodes.insert(iter->first);
			node_index[iter->first] = INF;
/*			cout << iter->first << " -> ";
			node_set temp = iter->second;
			for(node_set::iterator iter2 = temp.begin(); iter2 != temp.end(); ++iter2)
				cout << *iter2 << " ";
			cout << endl;				*/
		}		
		
		node_set dummy;
		sccs.push_back(dummy);
		SCC();				
		SCC_GRAPH();
/*		for(Map_scc::iterator iter = scc_edge.begin(); iter != scc_edge.end(); ++iter)
		{
			cout << iter->first << " -> ";
			vector<int> temp = iter->second;
			for(vector<int>::iterator iter2 = temp.begin(); iter2 != temp.end(); ++iter2)
				cout << *iter2 << " ";
			cout << endl; 
		}	
*/
		_SCC_SOURCE_();
//		cout << "source: " << scc_source << endl;
//		cout << "scc_count: " << scc_count << endl;
	
		scc_node = new struct vertex[scc_count];
		scc_node[0].length = 0;
		for(int i = 1; i < scc_count; ++i)
		{
			scc_node[i].length = -1;
			scc_node[i].parent = -1;
			scc_node[i].visited = false;
			scc_node[i].child = -1;
		}
		
		_SCC_TOPSORT_();
		
//		for(int i = 0 ; i < scc_count; ++i) 
//			cout <<  i <<  "  " << scc_node[i].length << "  " << scc_node[i].child << endl; 	
//		cout << "visit order: ";
		node_order.push_back(source);
		while(scc_source != -1) {
//			cout << scc_source << "  ";
			int scc1 = scc_source;
			int scc2 = scc_node[scc1].child;	
			scc_source = scc2;
			if(scc_source != -1) {
				node_set set1 = sccs[scc1];
				node_set set2 = sccs[scc2];
				for(node_set::iterator iter1 = set1.begin(); iter1 != set1.end(); ++iter1)
				{	
					string u = *iter1;
					node_set u_node = node[u];
					bool flag = false;
					for(node_set::iterator iter2 = set2.begin(); iter2 != set2.end(); ++iter2)
					{
						string v = *iter2;
						node_set::iterator iter3 = u_node.find(v);
						if(iter3 != u_node.end()) {
						//	cout << u << " -> " << v << " -> " << endl;
							node_order.push_back(u);
							node_order.push_back(v);
							flag = true;
						}
						if(flag) break;	
					}
					if(flag) break;
				} 

			}
		}
//		cout << endl;
		int size = node_order.size() - 1;
		for(int i = 0 ; i < size; i+=2) {
//			cout << node_order[i] << " -> " << node_order[i+1] << endl;
			cout << node_order[i] << endl;
			shortest_path(node_order[i], node_order[i+1]);			
		}	
		cout << node_order[size] << endl;	
			
		node.clear();
		all_nodes.clear();
		node_index.clear();
		node_lowlink.clear();
		node_stack.clear();
		sccs.clear();
		scc_edge.clear();
		scc_topsort.clear();				
		visit_order.clear();
		node_order.clear();
		node_dist.clear();
		node_prev.clear();
		
	}
	return 0;
}


void SCC()
{
	index = 0;
	for(node_set::iterator iter2 = all_nodes.begin(); iter2 != all_nodes.end(); ++iter2)
	{
		if(node_index[*iter2] == INF)
			tarjan(*iter2);
	}		
}

void tarjan(string v)
{
	node_index[v] = index;
	node_lowlink[v] = index;		
	index += 1;
	node_stack.push_back(v);

	node_set temp = node[v];
	for(node_set::iterator iter2 = temp.begin(); iter2 != temp.end(); ++iter2)
	{	
		string v1 = *iter2;
		if(node_index[v1] == INF)
		{
			tarjan(v1);
			node_lowlink[v] = min(node_lowlink[v], node_lowlink[v1]);
			
		}
		else { 
			bool flag = false;
			for(n_stack::iterator iter3 = node_stack.begin(); iter3 != node_stack.end(); ++iter3)
			{
				if(*iter3 == v1) { flag = true; break; }
			}				
			if(flag)
				node_lowlink[v] = min(node_lowlink[v], node_index[v1]);	
		}
	}
	if(node_lowlink[v] == node_index[v])
	{
//		cout << "SCC: ";
		string v1;
		node_set temp;
		do {
			if(!node_stack.empty()) {
				v1 = node_stack.back();
				node_stack.pop_back();
				temp.insert(v1);
//				cout << v1 << " ";
			}
		} while(!(v1 == v));
		sccs.push_back(temp);
		++scc_count;
//		cout << endl; 
	}	

}

void SCC_GRAPH()
{
	int size = sccs.size();
	for(int i = 0 ; i < size; ++i)
	{
		node_set scc1 = sccs[i];
		for(int j = 0 ; j < i; ++j)
		{	
			bool flag = false;
			node_set scc2 = sccs[j];
			for(node_set::iterator iter1 = scc1.begin(); iter1 != scc1.end(); ++iter1)
			{
				node_set temp = node[*iter1];
				for(node_set::iterator iter2 = scc2.begin(); iter2 != scc2.end(); ++iter2)
				{
					node_set::iterator iter3 = temp.find(*iter2);
					if(iter3 != temp.end()) {
						scc_edge[i].push_back(j);
						flag = true;
						break;
					}
				}
				if(flag) break;
			}	
		}

		for(int j = i+1 ; j < size; ++j)
		{
			bool flag = false;
			node_set scc2 = sccs[j];
			for(node_set::iterator iter1 = scc1.begin(); iter1 != scc1.end(); ++iter1)
			{
				node_set temp = node[*iter1];
				for(node_set::iterator iter2 = scc2.begin(); iter2 != scc2.end(); ++iter2)
				{
					node_set::iterator iter3 = temp.find(*iter2);
					if(iter3 != temp.end()) {
						scc_edge[i].push_back(j);
						flag = true;
						break;
					}
				}
				if(flag) break;
			}	

		}
	}
}


int min(int a,int b)
{
	int m = (a < b) ? a : b;
	return m;
}

void _SCC_SOURCE_()
{
	int size = sccs.size();
	for(int i = 0 ; i < size; ++i)
	{
		node_set scc1 = sccs[i];
		bool flag = false;
		for(node_set::iterator iter1 = scc1.begin(); iter1 != scc1.end(); ++iter1)
		{
			if(*iter1 == source) {
				scc_source = i;
				flag = true;
				break;
			}	
		}
		if(flag) break;
	}
}

void _SCC_TOPSORT_()
{

	visit(scc_source, 0);

}

void visit(int u, int x)
{
//	if(!scc_node[u].visited) {
		if(scc_node[u].length < (scc_node[x].length+1)) {
			scc_node[u].length = scc_node[x].length+1;
			scc_node[x].child = u;	
		}
		
		scc_node[u].visited = true;
	
		vector<int> temp = scc_edge[u];
		int size = temp.size();
		for(int i = 0; i < size; ++i) 
		{
			int v = temp[i];
//			if(scc_node[v].visited) {
				visit(v, u);
//			}
		}	
	
//	}
}


void shortest_path(string src, string dest)
{
	for(node_set::iterator iter2 = all_nodes.begin(); iter2 != all_nodes.end(); ++iter2)
	{
		node_dist[*iter2] = INF;
		node_prev[*iter2] = "UDF";	
	}	

	node_dist[src] = 0;

	string u;	
	while(!all_nodes.empty()) {
		int min = INF; 
		for(node_set::iterator iter2 = all_nodes.begin(); iter2 != all_nodes.end(); ++iter2)
		{
			if(node_dist[*iter2] <= min) {
				min = node_dist[*iter2];
				u = *iter2;
			}
		}
		if(u == dest) break;		
		all_nodes.erase(all_nodes.find(u));
	
		node_set temp = node[u];
		for(node_set::iterator iter2 = temp.begin(); iter2 != temp.end(); ++iter2)
		{
			string v = *iter2; 
			int alt = node_dist[u] + 1;
			if(alt < node_dist[v]) {
				node_dist[v] = alt;
				node_prev[v] = u;
			}	
		}
	}
	if(u != dest ) return; 		
	list<string> seq;
	u = dest;
	while(node_prev[u] != "UDF") {
		seq.push_front(u);
		u = node_prev[u];
	}
	for(list<string>::iterator iter = seq.begin(); iter != seq.end() ; ++iter)
		cout << *iter << endl;
}	
