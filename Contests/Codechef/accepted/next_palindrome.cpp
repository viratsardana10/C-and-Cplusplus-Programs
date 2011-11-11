#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <stdio.h>

using namespace std;

bool comp(const vector<int>& ,const vector<int>& );
void work (vector<int>& ,int ,int );

ostream_iterator<int> output(cout, "");

int main()
{
	int t;
	cin >> t;

	while(t--) {
		vector<int> v1;
		string s;
		cin >> s;

		int size = s.size();
		int mid = size/2;
		
		for(int i = 0 ; i < size ; i++)
			v1.push_back(s[i] - '0');

		vector<int> v2(v1.begin(), v1.end());
		for(int i = 0 ; i < mid ; i ++)
		{
			 v2[size-1-i] = v2[i];
		}
		
		int param1 = (size%2) == 0 ? mid-1 : mid;
		if(!comp(v1,v2)) 
			work(v2, param1 , mid);

		copy(v2.begin(), v2.end(), output);
		cout << endl;	
	}
	return 0;
}

bool comp(const vector<int>& v1, const vector<int>& v2) {
	if (v1.size() != v2.size()) 
		return v1.size() < v2.size();

	for (int i = 0; i < v1.size(); i++)
		if (v1[i] != v2[i])
			return v1[i] < v2[i];

	return false;
}


void work(vector<int>& num, int pos1, int pos2) {
	if (pos1 < 0) {
			num[num.size()-1] = 1;
			num.insert(num.begin(), 1);
			return;
   	} else if (num[pos1] < 9) {
    		num[pos1] = num[pos2] = num[pos1] + 1;
     		return;
   	} else {
     		num[pos1] = num[pos2] = 0;
      		work(num, pos1-1, pos2+1);
     		return;
   	}
}

