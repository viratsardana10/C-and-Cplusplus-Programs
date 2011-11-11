#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
long  modular_exponentiation(int a,long long b,long n);
string conv(long long decimal);

int main()
{
    ifstream infile("input.txt");
    ofstream outfile("output.txt");
   
    int t;
    long long N;
   
    infile >> t;
    for(int i=0;i<t;i++)
    {
        infile >> N;
        long result=modular_exponentiation(2,(N-1),45632178);
        outfile << result << "\n";     
    }
    
    return 0;
       
}

long  modular_exponentiation(int a,long long b,long n)
{
	long int d=1;
	string binary=conv(b);
	int len=binary.size();

	for(int i=(len-1);i>=0;i--)  // iterate in reverse order to account for inverted binary code
	{
		d=(d*d)%n;
		if(binary[i]=='1')
		{
			d=(d*a)%n;
		}
          // cout<<d<<"   ";
	}
	
//	cout<<endl;
	return d;

}

string conv(long long decimal)
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

//    return string(result.rbegin(), result.rend());// using std::string() constructer with iterators to reverse the string
  
}


