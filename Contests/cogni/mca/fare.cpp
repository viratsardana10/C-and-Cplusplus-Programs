/*
*  Program to calulate minimum fare:
*  It uses all subsets of distance and then determines the sum of each subset.
*  If that sum is equal to the kilometres, it determines the corresponding fare.
*  The minimum fare is choosen from all possible cases.
*/

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
    ifstream infile("input_fare");
    long N;
    infile >> N;
    
    long dist[N];
    long fare[N];
    for(int i=0;i<N;i++)
    {
        infile >> dist[i];
        infile >> fare[i];
    }
    long kilometres;
    infile >> kilometres;

    for(int i=0;i<N;i++)
    {
       dist[i]=pow(2,dist[i]);
    }
    
    long size=pow(2,N);
    
    long min_fare=1111;      // in Q. i<=1000,so a max impossible value is taken.
    for(long i=1;i<size;i++)
    {
         long distance=0;
         long temp_fare=0;
         for(long j=0;j<N;j++)
         {
             if(i & (1<<j))
             {
                  distance+=dist[N-1-j];
                  temp_fare+=fare[N-1-j];
             }
         }
         cout<<endl; 
         if(distance==kilometres)
         {
             if(temp_fare<min_fare)
                     min_fare=temp_fare;
         } 
    }
    cout<<min_fare;
    cout<<endl;
    return 0; 
}



