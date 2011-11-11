#include <iostream>
using namespace std;
bool r;
int size;
bool testPalindrome(char* ,int ,int);
int main()
{
    char* a=new char;
    cout<<"Enter a string:";
    cin>>a;
    size=strlen(a);
    int i=0;
      
    bool flag=testPalindrome(a,(size-1),i);
    cout<<flag;
    
    cout<<endl;
    system("pause");
    return 0;
    
}

bool testPalindrome(char* a,int s,int i)
{
    if(size%2==0 && s==(size/2))
      return true;
      
   if(s==(size/2))
   {
      if(*(a+s)==*(a+s+1)){
        r=1;    
        return r;
     }  
      else {
        r=0;    
        return r;
    }    
   }  
    else if(*(a+i)==*(a+s))
    {
      testPalindrome(a,(s-1),(i+1));
    }      
}
