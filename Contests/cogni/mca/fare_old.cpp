#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
using namespace std;

string conv(long );
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
    
    long min_fare=1111;
    for(long i=1;i<size;i++)
    {
         long distance=0;
         long temp_fare=0;
        
         string binary=conv(i);
         int len=binary.size(); 
         for(long j=0;j<len;j++)
         {
             if(binary[j]=='1')
             {
                  distance+=dist[N-1-j];
                  temp_fare+=fare[N-1-j];
             }
         }
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


string conv(long decimal)
{
    if(decimal == 0) return "0";
    char NUMS[] = "01"; // Characters that may be used
    string result = ""; // Create empty string ready for data to be appended

    do{
         result.push_back(NUMS[decimal%2]);
        // Append the appropriate character in NUMS based on the equation decimal%base

         decimal /= 2; // Calculate new value of decimal
    }while(decimal != 0); // Do while used for slight optimisation
    return result;  // it returns the string with binary code in inverted order## care taken in modular_exponentiation() for this## it prevents the following more computationally expensive return.

  //  return string(result.rbegin(), result.rend());// using std::string() constructer with iterators to reverse the string
}  

