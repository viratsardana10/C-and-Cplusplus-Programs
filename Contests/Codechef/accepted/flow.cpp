#include <iostream>
#include <stdio.h>
using namespace std;

#define ll long double 
long long gcd(long long a, long long b);

struct frac {
	ll n;
	ll d;
} points[61][61];


void init()
{
	for(int i = 0 ; i < 61 ; ++i)
		for(int j = 0 ; j < 61 ; ++j)
		{
			points[i][j].n = 0;
			points[i][j].d = 1;
		}

	points[0][0].n = points[0][0].d = 1;

	for(int j = 1 ; j < 61 ; ++j)
	{
		points[0][j].n = 1;
		points[0][j].d = (points[0][j-1].d)*2;
	}

	for(int i = 1; i < 61 ; ++i)
	{
		points[i][0].n = 1;
		points[i][0].d = (points[0][i-1].d)*2;
	}

	for(int i = 1 ; i < 61 ; ++i)
		for(int j = 1 ; j < 61 ; ++j)
		{
			points[i][j].n = points[i-1][j].n*points[i][j-1].d + points[i][j-1].n*points[i-1][j].d;
			points[i][j].d = 2*points[i-1][j].d*points[i][j-1].d;	
		}

/*	for(int i = 0 ; i < 5 ; ++i)
		for(int j = 0 ; j < 5 ; ++j)
			cout << points[i][j].n << " " << points[i][j].d << endl;
*/
}
int main()
{

  init();  

  long T;
  scanf("%ld", &T);


  while(T--) {
	long long F;
	scanf("%lld", &F);
	int X, Y;
        scanf("%d", &X);
	scanf("%d", &Y);
	
//	cout << points[X][Y].n << " " << points[X][Y].d << endl;	
	long double flow = ((double)(points[X][Y].n*F))/points[X][Y].d;
	printf("%.4Lf\n", flow);  
//	cout << flow << endl;	
  }
  return 0;
}
/*
ll gcd(ll a, ll b)
{
    long long c;
    while(1)
    {
  	c = a%b;
  	if(c == 0)
  	  return b;
  	a = b;
  	b = c;
    }
}*/
