#include <iostream>
#include <fstream>
using namespace std;
bool isPresent(int );
int a[525];

int main()
{
	ifstream infile("slopesum.txt");
//	ofstream outfile("slopesum.txt");
	int T;
	cin>>T;
	while(T--)
	{
		long long n1;
		long long n2;
		cin>>n1>>n2;
		for(int i=0;i<525;i++)
			infile>>a[i];
	
		long long count=0;
		for(long long i=n1;i<=n2;i++)
		{
			long long k=i;
			while(k>100)
			{
				int temp=k%1000;
				if(isPresent(temp))
					count++;
				k=k/10;
			}	
		}
		cout<<count<<endl;
	}
}

bool isPresent(int x)
{
	int l, r, c;
	int n=525;
    	for (l = 0, r = n-1; l <= r;) 
	{
        	c = l+(r-l) / 2;
	        if (a[c] > x)
        	    r = c - 1;
	        else if (a[c] < x)
        	    l = c + 1;
	        else
        	    return true;
    	}
    return false;
}
