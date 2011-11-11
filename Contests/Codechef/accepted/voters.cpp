/*
* CODE: VOTERS
*/

#include <iostream>
#include <map>
#include <iterator>
using namespace std;

typedef map< int, int , less<int> > Map;

int main()
{
	Map id;
	int N1, N2, N3;
	cin >> N1 >> N2 >> N3;
	long total = N1 + N2 + N3;

	int key; long count = 0;

	for(int i = 0 ; i < total; ++i)
	{
		cin >> key;
		if(id[key] == 1)
			count++;

		id[key]++;
	}
	
	cout << count << endl;

	Map::iterator iter;
	for (iter = id.begin(); iter != id.end(); iter++ )
	{
		if ( (iter->second) >= 2)
			cout << iter->first << endl;
	}
	return 0;
}
