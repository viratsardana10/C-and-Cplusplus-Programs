#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int compare(const void *a, const void *b)
{
	return strcmp( *(char**)a, *(char**)b );
}

int main()
{
	int N;
	cin >> N;
	while(N--) {
		int M;
		cin >> M;
		char* s[M];
		for(int i = 0 ; i < M ; ++i)
		{
			s[i] = new char;
			cin >> s[i];
		}
		qsort(s, M, sizeof(char*), compare);	
		for(int i = 0 ; i < M ; ++i)
			cout << s[i];
		cout << endl;
	}
	return 0;
}
