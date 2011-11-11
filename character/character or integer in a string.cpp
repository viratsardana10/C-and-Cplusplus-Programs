#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char* s;
    s=new char;
    cout<<"Enter a string: ";
    cin>>s;
    
    cout<<endl<<s<<endl<<"___________________"<<endl;
    int size=strlen(s);
   /*
    cout<<s[0]<<"   "<<int(s[0]);
    if(int(s[0])>=48 && int(s[0])<=57)
      cout<<" an integer"<<endl;
    cout<<endl;
     */   
    for(int i=0;i<size;i++)
    {
        if(s[i]>=48 && s[i]<=57)
          cout<<s[i]<<" is an integer."<<endl<<"_____________"<<endl;
        else
          cout<<s[i]<<" is a character"<<endl<<"_____________"<<endl;
    }
       
    system("pause");
    return 0;
}    
