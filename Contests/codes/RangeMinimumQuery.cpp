/*
*	Author: Vivek Prakash
*	Created on: Sep 21, 2010
*	SEGMENT TREES
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <iterator>

using namespace std;

void initialize_tree(int node, int b, int e, int *M, int *A, int N);
int query(int node, int b, int e, int *M, int *A, int i, int j);

int main()
{
	ostream_iterator<int> output(cout , " ");
	int n;
	cin >> n;
	int A[n];
	for(int i = 0; i < n ; ++i)
	{
		cin >> A[i];
	}

	int segSize = 2 * pow(2, floor(log2(n) + 1));
	int size = segSize + 1, M[size];

	for(int i = 0 ; i < size; ++i)
		M[i] = -1;
	
	initialize_tree(1, 0, n-1, M, A, n);
	copy(M, M+segSize, output);

	int i,j;
	while (	cin >> i >> j )
	{
		int value = query(1, 0, n-1, M, A, i, j);
		cout << value << endl;
	}
}

void initialize_tree(int node, int b, int e, int *M, int *A, int N)
{
	if ( b == e )
		M[node] = b;
	else 
	{
		  //compute the values in the left and right subtrees
          initialize_tree(2 * node, b, (b + e) / 2, M, A, N);
          initialize_tree(2 * node + 1, (b + e) / 2 + 1, e, M, A, N);
	      //search for the minimum value in the first and second half of the interval
          if (A[M[2 * node]] <= A[M[2 * node + 1]])
                M[node] = M[2 * node];
          else
                M[node] = M[2 * node + 1]; 
	}
}

int query(int node, int b, int e, int *M, int *A, int i, int j)
{
	int p1, p2;
	
	//if the current interval doesn't intersect the query interval return -1
	if (i > e || j < b)
		return -1;

	//if the current interval is included in the query interval return M[node]
    if (b >= i && e <= j)
        return M[node];

	//compute the minimum position in the left and right part of the interval
    p1 = query(2 * node, b, (b + e) / 2, M, A, i, j);
	p2 = query(2 * node + 1, (b + e) / 2 + 1, e, M, A, i, j);
	
    //return the position where the overall minimum is
    if (p1 == -1)
	   return M[node] = p2;
	if (p2 == -1)
       return M[node] = p1;
    if (A[p1] <= A[p2])
       return M[node] = p1;

	return M[node] = p2;
}
