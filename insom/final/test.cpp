#include <vector>
using namespace std;
 
vector<int> find_lis(vector<int> &a)
{
	vector<int> b, p(a.size());
	int u, v;
 
	if (a.size() < 1) return b;
 
	b.push_back(0);
 
	for (size_t i = 1; i < a.size(); i++) {
		if (a[b.back()] < a[i]) {
			p[i] = b.back();
			b.push_back(i);
			continue;
		}
 
		for (u = 0, v = b.size()-1; u < v;) {
			int c = (u + v) / 2;
			if (a[b[c]] < a[i]) u=c+1; else v=c;
		}
 
		if (a[i] < a[b[u]]) {
			if (u > 0) p[i] = b[u-1];
			b[u] = i;
		}	
	}
 
	for (u = b.size(), v = b.back(); u--; v = p[v]) b[u] = v;
	return b;
}
 
#include <iostream>
#include <fstream>
int main()
{
        ifstream infile("input.txt");
        ofstream outfile("output.txt"); 
        int N;
        infile>>N;
	int a[N];
        for(int i=0;i<N;i++)
            infile>>a[i];

	vector<int> seq(a, a+sizeof(a)/sizeof(a[0]));
      int count=0;     
      while(seq.size()!=0) 
      {
        vector<int> lis = find_lis(seq);
         
/*	for (size_t i = 0; i < lis.size(); i++)
        {
		cout<< seq[lis[i]]<<" ";
        } */ 
        for(int i=0;i<lis.size();i++)
        {
           seq.erase(seq.begin()+lis[i]-i);
        }
/*     	cout<<endl;
        for (size_t i = 0; i < seq.size(); i++)
        {
		cout<< seq[i]<<" ";
        }
        cout<<endl; */
        count++;
      }
      outfile<<count<<endl;
      return 0;
}
