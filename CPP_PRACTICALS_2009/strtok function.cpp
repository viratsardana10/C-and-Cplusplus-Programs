    #include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s[]="MY name is Vivek";
    char* token;
    char* a[30];
    token=new char;
    
    token=strtok(s," ");
    a[0]=token;
    int i=0;
    while(token!=NULL)
    {
        i++;
        cout<<token<<endl;
        token=strtok(NULL," ");
        a[i]=new char;
        a[i]=token;
    }    
    cout<<endl;
     
    for(int j=0;j<i;j++)     
    {                            
        cout<<a[j]<<"  ";
    } 
    cout<<endl;    
  //  cout<<endl<<s<<endl;
    system("pause");
    return 0; 
}    
