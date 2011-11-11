#include <iostream>
using namespace std;

void copy(char* ,const char* );

int main()
{
    char string3[10];
    char string4[]="vivek";
    //string3++;//this is an attempt to modify constant pointer.//
    copy(string3,string4);
    cout<<string3<<"   "<<string4<<endl;
    
    system("pause");
    return 0;
}    

void copy(char* s1,const char* s2)
{
    for(;(*s1=*s2)!='\0';s1++,s2++)
    ;
}    
