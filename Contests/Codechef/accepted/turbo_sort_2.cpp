#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;
typedef map< int, int, less<int> > Map;

int main()
{
	int T;
	fscanf(stdin, "%d", &T);
	Map array;
	
	while(T--)
	{
		int N;
		fscanf(stdin, "%d", &N);
		array[N]++;			
	}

	Map::iterator iter;
	for(iter = array.begin(); iter != array.end(); ++iter)
	{
		int count = iter->second;
		while(count--)
			fprintf(stdout, "%d\n", iter->first);
	}
	return 0;
}
