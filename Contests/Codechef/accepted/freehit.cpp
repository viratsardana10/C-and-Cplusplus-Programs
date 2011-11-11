#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

int a[4] = {1, 2, 4, 6};
int balls = 0;
int sum = 0;
int N;
bool flag = false;

void score(int );

int main()
{
  int t;
  cin >> t;
  
  while(t--) {
	scanf("%d", &N);

	for(int i = 0 ; i < 4; ++i)
	{
		if(flag) break; 
			balls = 0;
			sum = 0;
			score(a[i]);
		
	}	 
	
	if(flag) printf("yes\n");
	else printf("no\n");
	flag = false;
  }
  return 0;
}

void score(int u)
{
	if(flag) return;
	sum += u;
//	cout << balls << " : " << u << " : " << sum << endl;
	balls++;
	if(balls == 6 ){
		if(sum == N) flag = true;
		balls--;
		sum -= u;
		return;
	}
		
	for(int i = 0 ; i < 4; ++i)
	{
		if(flag) break;
		score(a[i]);	
	}

	sum -= u;
	balls--;
}
