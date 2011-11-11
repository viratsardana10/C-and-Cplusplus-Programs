#include <iostream>
using namespace std;

bool testPalindrome(char[] ,int ,int );
int main()
{
    char* s;
    char confirm;
    
    do
    {
    s=new char;
    cout<<"Enter a string: ";
    cin>>s;
        
    int size=strlen(s); cout<<size;
    int i=0;
    bool flag=testPalindrome(s,size,i); cout<<flag;
    
    if(flag==true)
       cout<<"The string \""<<s<<"\" is a palindromic sequence."<<endl;
    else
       cout<<"The string \""<<s<<"\" is not a palindromic sequence."<<endl;
          
    delete []s;
    cout<<endl<<"Do you want to continue?...Enter 'Y' for yes or 'N' for no :";
        cin>>confirm;
    }
                   
    while(confirm=='y' || confirm=='Y'); 
    
    cout<<endl<<"You have choosen to terminate the program.\n  Have a nice day!"<<endl;
    system("pause");
    return 0;   
    
}

bool testPalindrome(char s[],int size,int i)
{
    if(s[i]==s[(size-1)-i])
    {
        cout<<"entering if "<<i<<endl;
        if(i==(size/2))
        {
           return true; 
           cout<<" true "; 
        }
           
         i++;
         
         cout<<"exiting if "<<i<<endl;    
       // testPalindrome(s,size,(i+1));   
    }
   else
         return false;
         
    cout<<"recursive call"<<endl;             
    testPalindrome(s,size,i);
}    
