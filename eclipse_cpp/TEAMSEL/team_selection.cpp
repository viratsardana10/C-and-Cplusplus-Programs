/*
 * team_selection.cpp
 *
 *  Created on: 06-Nov-2010
 *      Author: vivek
 */

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <set>
#include <iterator>
#include <algorithm>
#include <cstdlib>
using namespace std;

#define S(x) scanf("%d", &x)
#define K 450
#define max(a,b) (a > b ? a : b)
typedef set<int, less<int> > Set;
Set::iterator iter;

bool diff(Set ,Set );
int compare(const void *a, const void *b)
{
	return ( *(int*)a - *(int*)b );
}

int main()
{
	ostream_iterator<int> output(cout, " ");
	int T;
	S(T);
	while(T--)
	{
		int N;
		S(N);
		int A[N];
		for(int i = 0 ; i < N ; ++i)
			S(A[i]);
		
		qsort(A, N, sizeof(int), compare);

		int P[N][N*K+1];
		Set subset[N*K+1];

		for(int j = 0; j <= N*K; ++j)
		{
			P[0][j] = (A[0] == j ? 1 : 0);
			subset[j].insert(P[0][j]);
		}


		for(int i = 1; i < N; ++i)
			for(int j = 0; j <= N*K; ++j)
			{
				if((j - A[i]) >= 0 && (j - A[i]) <= N*K)
				{
					P[i][j] = max(P[i-1][j],P[i-1][j-A[i]]);
			
					if(P[i-1][j-A[i]] == 1) {
						Set temp = subset[j-A[i]];
						for(iter = temp.begin(); iter != temp.end(); ++iter)
								subset[j].insert((*iter)+1);
						subset[j].erase(0);
					}
				}
				else P[i][j] = P[i-1][j];
				if(A[i] == j) {
					P[i][j] = 1;
					subset[j].insert(1);
					subset[j].erase(0);
				}

				/*if(P[i][j] == 1)
					cout << j << " : " << subset[j] << endl;*/
			}
//		cout << "---------------\n";

/*		for(int j = 0; j < N*K+1; ++j)
			if(subset[j].count(0) == 0 )
			{
				cout << j << " : "; 
				copy(subset[j].begin(), subset[j].end(), output);
				cout << endl;
			}
*/
		int sum = 0;
		for(int i = 0 ; i < N; ++i)
			sum += A[i];

		int j = 0, min = N*N*K, min_j = N*K+1;
		while(j <= sum/2)
		{
			if(P[N-1][j] == 1)
			{
//				cout << "j : " << j << endl;	
				if( (sum - 2*j) < min && (j != sum-j) && diff(subset[j],subset[sum-j])) {
					min = sum - 2*j;
					min_j = j;
				}
				else if( (sum - 2*j) < min && (j == sum-j) ) {
					if(subset[j].size() == 2) {
						iter = subset[j].begin();
						int a = *iter;
						++iter;
						int b = *iter;
						int d = a-b;
						d = d > 0 ? d : -d;
						if(d <= 1) {
							min = sum - 2*j;
							min_j = j;
						}
					}
					if( N%2 == 0 && subset[j].count(N/2) == 1) {
						min = 0;
						min_j = j;
						break;
					}
				/*	else {
						printf("ERRORs.\n");
						return 0;
					} 	*/
				}
			}
			++j;
		}
/*		if(min_j > N*K)
			cout << "\nERROR\n";
		else */ printf("%d %d\n", min_j, sum - min_j);
		if(T)
			printf("\n");
	}
	return 0;
}

bool diff(Set s1, Set s2)
{
/*	iter = s1.begin();
	int a = *(iter) + 1;
	iter = s1.end();
	--iter;
	int b = *(iter) +1;

	iter = s2.begin();
	int c = *(iter) - 1 ;
	iter = s2.end();
	--iter;
	int d = *(iter) +1;*/
		
	for(Set::iterator iter1 = s1.begin(); iter1 != s1.end(); ++iter1)
		for(Set::iterator iter2 = s2.begin(); iter2 != s2.end(); ++iter2)
		{
			int d = (*iter1) - (*iter2);
			d = (*iter1) > (*iter2) ? d : -d;
			if(d <= 1)
				return true;
		}

	return false;
}
