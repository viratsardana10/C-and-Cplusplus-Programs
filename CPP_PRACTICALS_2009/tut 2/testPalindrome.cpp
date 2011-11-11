#include <iostream>
#include <cstring>
using namespace std;

int n=0;
int size;
bool r=1;
 
bool testPalindrome(char* );

int main()
{
    char* s=new char;
    cout<<"Enter a string: ";
    gets(s);
    size=strlen(s)-1;
    //cout<<size;
    int flag=testPalindrome(s);
    //cout<<flag<<endl;
    if(flag==1)
      cout<<endl<<"The string \""<<s<<"\" is a palindromic sequence.\n";
    else
      cout<<endl<<"The string \""<<s<<"\" is not a palindromic sequence.\n";
        
    cout<<endl;
    system("pause");
    return 0;
}

bool testPalindrome(char* a)
{
 if(n<=size)
 {  if(a[n]==' ')
       n=n+1;
    else if(a[size]==' ') 
       size=size-1;
    else if(a[n]==a[size])
     {
       size=size-1;
       n=n+1;
       testPalindrome(a);
     return r;
    }
    
    else
      {
      r=0;    
      return r;
      }
 }
 else 
 return r;        
}
