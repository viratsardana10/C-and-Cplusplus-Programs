#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream infile("C-large.in");
    ofstream outfile("C-large.out");
	
    int T;
    infile>>T;
    for(int t=1;t<=T;t++)
    {
	long R;
	long K;
	int N;
	
	infile>>R>>K>>N;
	long long all=0;
	long long money=0;
	long a[N];

	for(int i=0;i<N;i++)
	{
		infile>>a[i];
		all+=a[i];
	}

	
	
	if(all<=K) 
		money=all*R;
	else {
	int index=0;

	for(long i=0;i<R;i++)
	{	
		long long sum=0;
		int j;
		for(j=index;j<N;j++)
		{
			if((sum+a[j])<=K)
			{
				sum=sum+a[j];
				index++;
			}
			else 
			{
				money+=sum;
				break;
			}
		}    
		if(j==N)
		{
			index=0;
			for(j=index;j<N;j++)
			{
				if((sum+a[j])<=K)
				{
					sum=sum+a[j];
					index++;
				}
				else 
				{
					money+=sum;
					break;
				}
			}
		}
	} 
	} outfile<<"Case #"<<t<<": "<<money<<endl;
    }
    return 0;
} 
