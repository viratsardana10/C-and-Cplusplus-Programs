#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while(T--) {
		char *s = new char;
		cin >> s;	
		int count = 0;
		while(*s != '\0') {
			if( *s == 'A' || *s == 'D' || *s == 'O' || *s == 'P' || *s == 'Q' || *s == 'R')
				++count;
			else if ( *s == 'B' )
				count += 2;
			s++;
		}
		printf("%d\n", count);
	}
	return 0;
}
