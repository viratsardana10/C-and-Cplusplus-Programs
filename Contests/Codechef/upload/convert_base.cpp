#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

string conv(int ,int );
int main()
{
    int decimal;
    cin>>decimal;
    cout<<setbase(2)<<decimal<<endl;
    string str=conv(decimal,2);
    cout<<str<<endl;
    
    system("pause");
    return 0;
}
string conv(int decimal, int base)
{
    if(decimal == 0) return "0";
    char NUMS[] = "0123456789ABCDEF"; // Characters that may be used
    string result = ""; // Create empty string ready for data to be appended

    do{
         result.push_back(NUMS[decimal%base]);
        // Append the appropriate character in NUMS based on the equation decimal%base

         decimal /= base; // Calculate new value of decimal
    }while(decimal != 0); // Do while used for slight optimisation
    
    return string(result.rbegin(), result.rend());// using std::string() constructer with iterators to reverse the string
}
