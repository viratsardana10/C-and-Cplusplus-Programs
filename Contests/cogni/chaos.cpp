#include <iostream>
#include <map>
#include <set>
#include <list>
#include <iterator>
#include <stack>
#include <vector>
using namespace std;

#define INF 99999999
void shortest_path(string src, string dest);

int V, R, TR;
int **weight;

struct rail {
	string orig;
	string dest;
	int speed;
	set<string> path;
} *train;

map<string, int> node_to_int;

typedef set<string> node_set;
typedef map<string, node_set> Map;
Map node;
set<string> all_nodes;
typedef set<string> node_set;
map<string, int> node_dist;
map<string, string> node_prev;


int main()
{
	int T;
	cin >> T;
	while(T--) {
		cin >> V >> R;
		weight = new int*[V];
		for(int i = 0 ; i < V ; ++i)
			weight[i] = new int[V];

		string s1, s2;
		int dist;

		int value = 0;

		for(int i = 0 ; i < R; ++i) {
			cin >> s1 >> s2;
			cin >> dist;
			node[s1].insert(s2);
			if(node_to_int.count(s1) == 0)
				node_to_int[s1] = value++;
			if(node_to_int.count(s2) == 0)
				node_to_int[s2] = value++;
			weight[node_to_int[s1]][node_to_int[s2]] = dist; 
		
			if(all_nodes.count(s1) == 0)
				all_nodes.insert(s1);
			if(all_nodes.count(s2) == 0)
				all_nodes.insert(s2);

		}
	
		cin >> TR;
		train = new struct rail[TR];
		
		int speed;
		for(int i = 0 ; i < TR; ++i) {
			cin >> s1 >> s2;
			cin >> speed;
			train[i].orig = s1;
			train[i].dest = s2;
			train[i].speed = speed;	
		}

		for(Map::iterator iter = node.begin(); iter != node.end(); ++iter)
		{
			all_nodes.insert(iter->first);
			cout << iter->first << " -> ";
			node_set temp = iter->second;
			for(node_set::iterator iter2 = temp.begin(); iter2 != temp.end(); ++iter2)
				cout << *iter2 << " ";
			cout << endl;				

		}
		cout << "here\n";

		long double train_time[V][TR];

		for(int i = 0 ; i < TR ; ++i)
		{
			shortest_path(train[i].orig, train[i].dest, i);	
			long double time = 0;
			set<string>::iterator iter = train[i].path.begin();
			train_time[node_to_int[*iter]][i] = time;
			++iter;
			for(; iter != train[i].path.end() ; ++iter)
			{
				time += ((long double)weight)/train[i].speed; 
				train_time[node_to_int[*iter]][i] = time;
			}
				
		}

		for(Map::iterator iter = node.begin(); iter != node.end(); ++iter)
		{
	
	}
	return 0;
}

void shortest_path(string src, string dest, int t)
{
	cout << src << " -> " << dest << endl;
	train[t].path.insert(t);
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
			int alt = node_dist[u] + weight[node_to_int[u]][node_to_int[v]];
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
	{
		cout << *iter << endl;
		train[t].path.insert(*iter);
	}
}	
