
// A program to compute sum of integers raised to a high power 
// using modular arithmetic and a well known algorithm Modular Exponentiation. 

#include <iostream>
using namespace std;

long int modular_exponentiation(long int ,long int ,long int );
string conv(long int );

int main()
{
	long int n,k,p;
	cin>>n>>k>>p;
        
	long time1=clock();
	long int sum1=0;
	int i;
        for(i=1;i<=n-2;i+=2)
	{
		sum1=(sum1+modular_exponentiation(i,k,p))%p;     // [A]n+n[B]n=[A+B]n : modular arithmetic
		sum1=(sum1+modular_exponentiation((i+1),k,p))%p; // similar to normal addition except except 
	}                                                        // each result x is replaced by (x mod n)
	for(;i<=n;i++)
		sum1=(sum1+modular_exponentiation(i,k,p))%p;

       
	long int result=(sum1)%p;
	long time2=clock();

	cout<<result<<endl;
	cout<<"Time: "<<static_cast<double>(time2-time1)/1000;

	return 0;

}

long int modular_exponentiation(long int a,long int b,long int n)
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

string conv(long int decimal)
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






