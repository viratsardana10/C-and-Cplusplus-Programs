/*
 * author : Vivek Prakash
 *   date : 01-02-2011   
 *   Code : MSTONES 
 */

#include <iostream>
#include <queue>
#include <map>
#include <queue>
#include <stdio.h>
using namespace std;

struct coord {
	double x;
	double y;
} *point;

typedef map<long double, int> Map;

int main()
{		
	int T;
	scanf("%d", &T);
	while(T--) {
		int N;
		scanf("%d", &N);
		point = new struct coord[N];
		for(int i = 0 ; i < N; ++i) {
			scanf("%lf", &point[i].x);	
			scanf("%lf", &point[i].y);	
		}	
		
		Map lines;
		for(int i = 0 ; i < N ; ++i) {
			for(int j = i+1 ; j < N ; ++j) {
				cout << point[i].x << "," << point[i].y << "  |  " << point[j].x << "," << point[j].y << endl;
				long double y_ = ((long double)(point[i].y-point[j].y));
				long double x_ = ((long double)(point[i].x-point[j].x));
			
				long double slope;	
				if(x_ == 0)
					slope = (long double)-1;
				else  
					slope = (long double)(y_/x_);
				cout << slope << endl;
				lines[slope]++;		
		
			}
		}
		
		int max = 0;
		for(Map::iterator it = lines.begin(); it != lines.end(); ++it) {
			cout << it->first << " : " << it->second << endl;
			int temp = it->second;
			if(temp > max) 
				max = temp;
		}

		printf("ans: %d\n", max);
	}
	
	return 0;
}	
