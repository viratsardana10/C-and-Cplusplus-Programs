#include <iostream>
using namespace std;

int main()
{
    char confirm;
    char* s;
    
    do
    {
    s=new char;
    cout<<"Enter a string: ";
    cin>>s;
        
    int size=strlen(s);
    for(int i=0;i<=(size/2);i++)
    {
        if(s[i]==s[(size-1)-i])
        {
            if(i==(size/2))
              cout<<endl<<"\""<<s<<"\" is a palindromic sequence."<<endl;
        }       
        else
         {
             cout<<endl<<"\""<<s<<"\" is not a palindromic sequence."<<endl;
             break;
         }       
    }
    delete []s;
        cout<<endl<<"Do you want to continue?..Enter 'Y' for yes or 'N' for no :";
        cin>>confirm;
    }
                   
    while(confirm=='y' || confirm=='Y');     
       
    cout<<endl<<"You have choosen to terminate the program.\n  Have a nice day!"<<endl;
    system("pause");
    return 0;
}   
 
