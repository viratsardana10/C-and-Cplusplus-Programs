#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
  
  while(t--) {
	int N;
	scanf("%d", &N);
	if(N < 6 || N > 36 || N == 33 || N == 35)
		printf("no\n");
	else printf("yes\n");
	
  }
  return 0;
}

