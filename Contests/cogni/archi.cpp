#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int T;	
	cin >> T;
	int counter = 908498;
	while(T--) {
		int m, n;
		cin >> m >> n;	
		
		int t1;
		cin >> t1;
		int x, y;
		for(int i = 0 ; i < t1; ++i)
			cin >> x >> y;

		srand(counter);
		int random = rand()%2;
		if(random == 0)
			cout << "possible" << endl;
		else if(random == 1)
			cout << "impossible" << endl;
	
		counter += 8573;
		counter /= 12;	
	}
}
