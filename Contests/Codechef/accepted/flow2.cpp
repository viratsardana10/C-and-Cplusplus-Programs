#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

long double points[61][61];

void init()
{
	points[0][0] = 1;

	for(int j = 1 ; j < 61 ; ++j)
		points[0][j] = ((long double)points[0][j-1])/2;	

	for(int i = 1; i < 61 ; ++i)
		points[i][0] = ((long double)points[0][i-1])/2;

	for(int i = 1 ; i < 61 ; ++i)
		for(int j = 1 ; j < 61 ; ++j)
			points[i][j] = ((long double)points[i-1][j])/2 + ((long double)points[i][j-1])/2;	
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
	
	long double flow = ((long double)(points[X][Y]*F));
	printf("%.4Lf\n", flow);  
}
  return 0;
}

