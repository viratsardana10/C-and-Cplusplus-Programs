#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream infile("input.txt");
	ofstream outfile("output.txt");

        int N,A,D;
	infile >> N >> A >> D;
	int a[N];
	for(int i=0;i<N;i++)
	   infile >> a[i];
	   
	int inc_count=1;
	int dec_count=1;
        int i;
	for(i=1;i<N;i++)
	{
//           cout<<i<<" : "<<inc_count<<"  "<<dec_count<<endl;
		if(a[i]>a[i-1])
		{
			inc_count++;
			dec_count=1;
			if(inc_count==A)
                        {
			      if((i%2)==0)
                                   outfile<<"jain";
                              else if((i%2)==1)
                                   outfile<<"amul";
	                      outfile<<endl; 
                              return 0; 
                         }
		}
		else if(a[i]<a[i-1])
		{
			dec_count++;
			inc_count=1;
			if(dec_count==D)
		        {    
                              if((i%2)==0)
                                   outfile<<"jain";
                              else if((i%2)==1)
                                   outfile<<"amul";
	                      outfile<<endl; 
                              return 0; 
                         }

                }
		else 
		{
			inc_count=1; dec_count=1;
		}
	}
        if(i==N)
          outfile<<"drawn"<<endl;
	return 0;
}
