/*
*    @ author: Vivek Prakash || Feb. 17,2010
*    This program finds the subset of a set whose elements sum
*    to give a predefined value;
*    It evaluates the power set and then examines all its elements;
*/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while(t--) 
  {
    int M,N;
    cin >> M >> N;
    
    int candy[N];
    for(int i=0;i<N;i++)
        cin >> candy[i];

    
    long long size=pow(2,N);
  
	int difference = 99999999;
	long long total = 0;
	long long count = 0;

    for(long long i=1;i<size;i++)
    {
         int value=0, packets = 0;
         for(int j=0;j<N;j++)
         {
             if(i & (1<<j)) {
                  value+=candy[N-1-j];
				  ++packets;
			}
         }
         
		 if(value >= M)
         {
			 if ( (value-M) < difference) {
			 	 difference = (value-M);
				 total = value;
				 count = packets;
			}
         }
    }

	cout << total << " " << count << endl;
   }
    return 0; 
}



