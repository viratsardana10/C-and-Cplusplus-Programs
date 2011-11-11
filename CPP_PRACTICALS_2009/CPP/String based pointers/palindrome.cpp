#include <iostream>
using namespace std;

int main()
{
    char confirm;
    char* s[1];
    
    do
    {
    s[0]=new char;
    cout<<"Enter a string: ";
    cin>>s[0];
        
    int size=strlen(s[0]);
    for(int i=0;i<=(size/2);i++)
    {
        if(*(s[0]+i)==*(s[0]+size-i-1))
        {
            if(i=(size/2))
              cout<<endl<<"The string \""<<s[0]<<"\" you entered is a palindromic sequence."<<endl;
        }       
        
        else
         {
             cout<<endl<<"The string \""<<s[0]<<"\" you entered is not a palindromic sequence."<<endl;
             break;
         
         }       
    }
    delete []*s;
    //do
    //{
        //confirm[0]=new char;
        cout<<"Do you want to continue?..Enter 'Y' for yes or 'N' for no :";
        cin>>confirm;
      /*  if(!(confirm=='y'||confirm=='Y'||confirm=='n'||confirm=='N'))
        {
           cout<<"This is not a valid response.";
        }
    }
     while(!(confirm=='y'||confirm=='Y'||confirm=='n'||confirm=='N'));*/
    }            
    while(confirm=='y' || confirm=='Y');     
       
    cout<<endl<<"You have choosen to terminate the program.\n  Have a nice day!"<<endl;
    system("pause");
    return 0;
}   
 
