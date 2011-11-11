/*
 * flipping_coins.cpp
 *
 *  Created on: 06-Nov-2010
 *      Author: vivek
 */

#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
#define S(x) scanf("%d", &x)
/*==================code for taking fast integer input==================*/
/*int sign;
int ch;
inline void S( int &x ) {
	x=0;
	while((ch<'0' || ch>'9') && ch!='-' && ch!=EOF)	ch=getchar_unlocked();
	if (ch=='-')
		sign=-1 , ch=getchar_unlocked();
	else
		sign=1;
	do
		x=(x<<3)+(x<<1)+ch-'0';
	while((ch=getchar_unlocked())>='0' && ch<='9');
	x*=sign;
}*/
/*======================================================================*/

int query(int node, int b, int e, int *M, int i, int j);
void update(int node, int b, int e, int *M, int i, int j);

int main()
{
	int N, Q;
	S(N); S(Q);
	int segSize = 2 * pow(2, floor(log2(N) + 1));
    int size = segSize + 1;
	int M[size];

	/* Initialise */
	for(int i = 0; i < size; ++i)
		M[i] = 0;

	while(Q--) {
		int op, i, j;
		S(op); S(i); S(j);

		if(op == 1) {
			int result = query(1, 0, N-1, M, i, j);
			printf("%d\n", result);
		}
		else if(op == 0)
			update(1, 0, N-1, M, i, j);
	}
}

int query(int node, int b, int e, int *M, int i, int j)
{
	int p1, p2;

//if the current interval doesn't intersect the query interval return -1
	if (i > e || j < b)
		return -1;

//if the current interval is included in the query interval return M[node]
    if (b >= i && e <= j)
        return M[node];

//compute the minimum position in the left and right part of the interval
    p1 = query(2 * node, b, (b + e) / 2, M, i, j);
	p2 = query(2 * node + 1, (b + e) / 2 + 1, e, M, i, j);

	if(p1 == -1)
		return p2;
	if(p2 == -1)
		return p1;

	return p1 + p2;
}

void update(int node, int b, int e, int *M, int i, int j)
{
	if (i > e || j < b)
		return ;

	if(b >= i && e <= j) {
		M[node] = e - b + 1 - M[node];
	}

	if(b == e)
		return;

	update( 2 * node, b, (b + e) / 2, M, i, j );
	update( 2 * node + 1, (b + e) / 2 + 1, e, M, i, j );

	M[node] = M[2 * node] + M[2 * node + 1];

	return;
}
