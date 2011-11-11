//============================================================================
// Name        : page.cpp
// Author      : tarun
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d",&n);
	vector<int> fib;
	vector<int> fibsum;
	vector<int> fibssum;
	int a[n];
	int  max=0;
	for(int i=0;i<n;i++)
	{
		int s;
		scanf("%d",&a[i]);
		if(a[i]>max) max=a[i];
	}
	fib.push_back(0);
	fib.push_back(1);
	fibsum.push_back(0);
	fibsum.push_back(1);
	fibssum.push_back(0);
	fibssum.push_back(1);
	for(int i=2;i<max;i++) {
		fib.push_back(fib[i-1]+fib[i-2]);
		fibsum.push_back(fibsum[i-1]+fib[i]);
		fibssum.push_back(fibssum[i-1]+fibsum[i]);
		if(fibssum[i]>max) break;
	}
	for(int i=0;i<n;i++) {
		int y=a[i];
		int count=0,max=0;
		for(int j=1;j<y;j++) {
			int z=y-fibssum[j];
			if(z<=0) break;
			if(z%(j+1)==0) {
				count++;
				max=j;
			}
		}
		int w=(y-fibssum[max])/(max+1);
		printf("%d %d %d\n",count,w,w+fibsum[max]);
	}
	return 0;
}
