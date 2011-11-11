#include <iostream>
#include <set>
#include <iterator>
using namespace std;



int main()
{
	int T;
	cin >> T;
	while(T--) {
		string s1, s2;
		cin >> s1 >> s2;

		int len1 = s1.size();
		cout << len1 << endl;
		set<int> U[len1/2 + 2];

		for(int i = 0 ; i < len1 ; ++i)
			for(int j = i+1 ; j < len1 ; ++j)
			{
				if(s1[i] == s1[j]) {
					U[1].insert(i);
					U[1].insert(j);				
				}
			}

		for(int k = 2 ; k <= len1/2 ; ++k)
		{
			set<int>::iterator iter = U[k-1].begin();
			while( iter != U[k-1].end() )
			{
				set<int>::iterator iter2 = U[1].begin();
				while( iter2 != U[1].end() )
				{
					int i_ = *iter2;
					int ik = *iter;
					iter2++;
					iter++;
					int j_ = *iter2;
					int jk = *iter;
					if( i_ > ik && j_ < jk) {
						ik = i_;
						jk = j_;
						
					}
				}			
			}	
		} 	
	}
	return 0;
}
