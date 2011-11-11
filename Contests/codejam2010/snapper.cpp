#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream infile("A-large.in");
    ofstream outfile("A-large.out");
	
    int T;
    infile>>T;
    for(int t=1;t<=T;t++)
    {
              
              int N;
              long long K;
              infile>>N>>K;

	      if((K%2)==0)
              {
                  outfile<<"Case #"<<t<<": "<<"OFF"<<endl;
                  continue;
              }  
		
	      long long power=1;
	      while(N)
	      {
		   power=power<<1;
		   N--;
	      } 
//	      cout<<power<<endl;
	      long long power1=power-1;
	      if(K==power1)
		  outfile<<"Case #"<<t<<": "<<"ON"<<endl;
	      else if(K<power1)
		  outfile<<"Case #"<<t<<": "<<"OFF"<<endl;
              else {
		      K=K-power1;
		      if((K%power)==0)
			   outfile<<"Case #"<<t<<": "<<"ON"<<endl;
	              else
			   outfile<<"Case #"<<t<<": "<<"OFF"<<endl;
            }
     }
     return 0;
}
