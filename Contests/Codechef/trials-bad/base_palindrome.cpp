#include <iostream>
#include <cstring>
using namespace std;

bool test_palindrome(string );
string conv(int ,int );
string NUMS[50000];
     
int main()
{
    int cases;
    cin>>cases;
   for(int i=0;i<241;i++)
   {
       NUMS[i]=(char)(i+14);
    }

  for(int j=0;j<cases;j++)
  {  
    int decimal;
    cin>>decimal;
    int i;
    string str;
    for(i=2;;i++)
    {
         str=conv(decimal,i);
        cout<<str<<endl;
        if(test_palindrome(str))
              break;
    }
    cout<<str<<endl;
    cout<<i;
    cout<<endl;
  }
    system("pause");
    return 0;
}
string conv(int decimal, int base)
{
    if(decimal == 0) return "0";
   // char NUMS[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // Characters that may be used
    string result = ""; // Create empty string ready for data to be appended

    do{
         result.append(NUMS[decimal%base]);
        // Append the appropriate character in NUMS based on the equation decimal%base

         decimal /= base; // Calculate new value of decimal
    }while(decimal != 0); // Do while used for slight optimisation
    return result;
   // return string(result.rbegin(), result.rend());// using std::string() constructer with iterators to reverse the string
}

bool test_palindrome(string s)
{
    int size=s.size();
    for(int i=0;i<=(size/2);i++)
    {
        if(s[i]==s[(size-1)-i])
        {
            if(i==(size/2))
                  return true;
              //cout<<endl<<"\""<<s<<"\" is a palindromic sequence."<<endl;
        }       
        else
         {
             return false;
            // cout<<endl<<"\""<<s<<"\" is not a palindromic sequence."<<endl;
             break;
         }       
    }
}
