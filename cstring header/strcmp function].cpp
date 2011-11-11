#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string s="baba";
    cout<<s.find("ba")<<"   "<<s.rfind("ba")<<"   "<<s.find("hshfshfs")<<endl;
    
    string s_2="bababa";
    if(s_2>s)
        cout<<"s2 > s \n";
    
    char* s1="vivek";
    char* s2="vineet";
    cout<<s1<<endl<<s2<<endl<<"_________"<<endl;
    
    int flag=strcmp(s1,s2);
    if(flag==1)
    {
        char* temp=s1;
        s1=s2;
        s2=temp;
    }    
    
    cout<<s1<<endl<<s2<<endl<<"_________"<<endl;
     
    system("pause");
    return 0; 
} 
