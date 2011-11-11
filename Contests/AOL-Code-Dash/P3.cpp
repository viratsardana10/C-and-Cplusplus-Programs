#include <iostream>
using namespace std;

bool findRoute(int ,int );
int** island;
int n;

int main()
{
	int t;
	cin >> t;

	while(t--) {
		int k;
		cin >> n >> k;

		island = new int*[n];
		for(int i = 0 ; i < n; ++i)
			island[i] = new int[n];

		for(int i = 0 ; i < n ; ++i)
			for(int j = 0 ; j < n ; ++j)
				island[i][j] = 1;

		for(int i = 0; i < k; ++i) {
			int s,d;
			cin >> s >> d;
			--s; --d;

			if (island[s][d]) {
				cout << "2 " << s+1 << " " << d+1 << "\n";
				island[s][d] = island[d][s] = 0;
			}
			else 
			{
/*				int temp = s;
				while( temp > 0 )	{
					--temp;
					if(island[temp][d]) {
						break;
						
					}
				} */
		
				findRoute(s, d);
			}
		}
	}
}


bool findRoute(int s, int d)
{
	if(island[s][d]) 
	{
		cout << s << " -> " << d << endl;
		island[s][d] = island[d][s] = 0;
		return true;
	}

	if( s >= 1 )
		return  findRoute(s-1,d); 
		
	if(s <= n-1)
		return findRoute(s+1,d);
	
	return false;
}
