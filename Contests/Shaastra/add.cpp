#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int T;
	fscanf(stdin, "%d", &T);
	while(T--)
	{
		int a,b;
		fscanf(stdin, "%d%d", &a, &b);
		fprintf(stdout, "%d\n", a+b);
	}
	return 0;
}
