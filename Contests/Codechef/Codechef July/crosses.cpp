/*
 * crosses.cpp
 *
 *  Created on: 06-Jul-2010
 *      Author: vivek
 */

#include <iostream>
#include <cstring>
#include <ctime>
#include <fstream>
using namespace std;
int n;
string* a;
int** h;
int** v;
int** d1;
int** d2;

int max_cross(int , int );
int horizontal(int ,int );
int vertical(int ,int );
int diagonal1(int ,int );
int diagonal2(int ,int );

int main()
{
	long init_clock = clock();
	ifstream infile("input.txt");

	infile >> n;
	a = new string[n];
	h = new int*[n];
	v = new int*[n];
	d1 = new int*[n];
	d2 = new int*[n];

	for(int i=0;i<n;i++)
	{
		infile >> a[i];
	}

    for(int i=0;i<n;i++)
    {
    	h[i] = new int[n];
    	v[i] = new int[n];
    	d1[i] = new int[n];
    	d2[i] = new int[n];
    	for(int j=0;j<n;j++)
    	{
    		max_cross(i,j);
//    		cout << max_cross(i,j) << " ";
//    		m[i][j] = max_cross(i,j);

    	}
//    	cout << endl;
    }
    long final_clock = clock();
    cout<<endl<<" Time difference : "<<((double)(final_clock-init_clock)/1000)<<endl;

    return 0;
}

int max_cross(int i,int j)
{
	h[i][j] = v[i][j] = d1[i][j] = d2[i][j] = 0;

	if (a[i][j] == '.')
		return 0;

	int p = h[i][j] = horizontal(i,j);
	int q = v[i][j] = vertical(i,j);
	int r = d1[i][j] = diagonal1(i,j);
	int s = d2[i][j] = diagonal2(i,j);
	int x = (p>q)?p:q ;
	int y = (r>s)?r:s ;
	int max = (x>y)?x:y ;

	return max;
}

int horizontal(int i,int j)
{
	if((j-1)>=0)
	{
		if(a[i][j-1] == 'X')
			return h[i][j-1];
	}

	int count = 0;
    for (int k=j;k>=0;k--)
    {
    	if (a[i][k] == 'X')
    			count ++;
    	else
    		break;
    }

    for(int k=j+1;k<n;k++)
    {
    	if (a[i][k] == 'X')
    			count ++;
    	else
    		break;
    }

    return count;

}

int vertical(int i,int j)
{
	if ((i-1) >= 0)
	{
		if(a[i-1][j] == 'X')
			return v[i-1][j];
	}

	int count = 0;
    for (int k=i;k>=0;k--)
    {
    	if (a[k][j] == 'X')
    			count ++;
    	else
    		break;
    }

    for(int k=i+1;k<n;k++)
    {
    	if (a[k][j] == 'X')
    			count ++;
    	else
    		break;
    }

    return count;

}

int diagonal1(int i,int j)
{
	if((i-1)>=0 && (j-1)>=0)
	{
		if (a[i-1][j-1] == 'X')
			return d1[i-1][j-1];
	}
	int count = 0;
	int p = i;
	int q = j;
	while(p >=0 && q>=0)
	{
		if (a[p][q] == 'X')
				count++;
		else
			break;
		p--;
		q--;
	}

	p = i+1;
	q = j+1;
	while(p<n && q<n)
	{
		if (a[p][q] == 'X')
				count++;
		else
			break;
		p++;
		q++;
	}

	return count;
}

int diagonal2(int i,int j)
{
	if((i-1)>=0 && (j+1)<n)
	{
		if (a[i-1][j+1] == 'X')
			return d2[i-1][j+1];
	}

	int count = 0;
	int p = i;
	int q = j;
	while(p >=0 && q<n)
	{
		if (a[p][q] == 'X')
			count++;
		else
			break;
		p--;
		q++;
	}

	p = i+1;
	q = j-1;
	while(p<n && q>=0)
	{
		if (a[p][q] == 'X')
			count++;
		else
			break;
		p++;
		q--;
	}

	return count;

}
