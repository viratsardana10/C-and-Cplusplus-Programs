#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream outfile("slopesum.txt");
	int T;
	cin>>T;
	while(T--)
	{
		long long n1;
		long long n2;
		cin>>n1>>n2;
		
		long long count=0;
		for(long long i=n1;i<=n2;i++)
		{
//			if(isDecreasing(i) || isIncreasing(i))
//				continue;
//			else 
//				outfile<<i<<endl;
			long long k=i;
			int a[15];
			int j=0;
			while(k)
			{
				a[j]=k%10;
				k=k/10;
				j++;
			}
			for(int p=1;p<(j-1);p++)
			{
				if((a[p]>a[p-1] && a[p]>a[p+1]) || (a[p]<a[p-1] && a[p]<a[p+1]))
				{
					outfile<<i<<endl;
					break;	
		//			count++;
				}
			} 
		}
	//	cout<<count<<endl;
	} 
}
/*
bool isDecreasing(long long i)
{
	long long k=i;
	bool flag=true;
	while(k)
	{
		int prev=k%10;
		k=k/10;
		int next=k%10;
		if(next>=prev)
	}	
}
*/
