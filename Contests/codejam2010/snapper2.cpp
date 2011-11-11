#include <iostream>
#include <fstream>
using namespace std;

bool isAllPrevON(int );
int* a;

int main()
{
    ifstream infile("A-small.in");
    ofstream outfile("A-small.out");
	
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
              
              a=new int[N];
              for(int i=0;i<N;i++)
                      a[i]=0;
                      
              for(long long i=0;i<K;i++)
              {
                      for(int j=(N-1);j>0;j--)
                      {
                              if(isAllPrevON(j))
                              {
                                    if(a[j]==0)
                                        a[j]=1;
                                    else a[j]=0;
                              }                              
                      }
                      if(a[0]==0)
                          a[0]=1;
                      else a[0]=0;
		      
//		      for(int i=(N-1);i>=0;i--)
//			   cout<<a[i];

//		      cout<<endl;
              }
              if(isAllPrevON(N))
                     outfile<<"Case #"<<t<<": "<<"ON"<<endl;
              else
                     outfile<<"Case #"<<t<<": "<<"OFF"<<endl;    
    }
}

bool isAllPrevON(int j)
{
     for(int i=(j-1);i>=0;i--)
     {
             if(a[i]==0)
                  return false;
     }
     return true;
}
