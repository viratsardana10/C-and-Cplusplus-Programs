#include <iostream>
using namespace std;

int main()
{
    char s1[10];
    char s2[]="vivek";
    while(*s2!='\0')
    {
        *s1=*s2;
         //++s2; this is an error-an attempt to modify constant pointer
    }    
    cout<<s2<<endl;
    /*
    for(;(*s1=*s2)!='\0';s1++,s2++)
    {
        ;
    } */   
    cout<<s1<<endl;
    system("pause");
    return 0;
}    


