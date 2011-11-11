#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin>>N;
        vector<int> a(N);
	for(int i=0;i<N;i++)
	   cin>>a[i];
     
     int count=0;
     while(a.size()!=0)
     {  
        int n=a.size(); 
	int longest=1;
        int index=101;
	for(int i=0;i<(n-1);i++)
	{
		int temp=1;
		int last=a[i];
		for(int j=(i+1);j<N;j++)
		{
			if(a[j]>last)
			{
				last=a[j];
				temp++;
			}
		}
		if(temp>longest)
                {
		     longest=temp;
                     index=i;
                     cout<<index<<"   ";
                }
	}
      cout<<"index is "<<index<<endl;
      if(index<101)
      {
         int last=a[index];
         a.erase(a.begin()+index);
         for(int j=index;j<a.size();j++)
         {
            if(a[j]>last)
            {
                last=a[j];
                a.erase(a.begin()+j);
            }
         }
       }
        count++;
//	cout<<longest<<" , index is "<<index<<endl;
      }
        cout<<count<<endl;
        return 0;
}
