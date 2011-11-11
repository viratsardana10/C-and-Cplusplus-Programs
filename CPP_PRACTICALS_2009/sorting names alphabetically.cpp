#include <iostream>
#include <cstring>
using namespace std;
/*
template<typename T>
void swap(T*& value1,T*& value2)  //this is a robust swaping
{
    T* temp;
    temp=value1;
    value1=value2;
    value2=temp;
}    
*/

void swap(char*& ,char*& );

int main()
{
    char** s;
    int n;
    cout<<"Enter a positive integer:";
    cin>>n;
    
    s=new char*[n];
    cout<<"Enter "<<n<<" names:"<<endl;
    
    for(int k=0;k<n;k++)
    {
        cout<<(k+1)<<": ";
        s[k]=new char;
        cin>>s[k];
        cout<<endl;
    } 
    
    for(int i=1;i<n;i++)
    {
            for(int j=0;j<(n-i);j++)
        {
            int flag=strcmp(s[j],s[j+1]);
            if(flag==1)
                swap(s[j],s[j+1]);
            else if(flag==0)
            {
                if(strlen(s[j])>strlen(s[j+1]))
                   swap(s[j],s[j+1]); 
            }    
        }    
    }
    cout<<" ____________________"<<endl;
    
    for(int i=0;i<n;i++)
    {
        cout<<s[i]<<endl;
    }                        
    system("pause");
    return 0; 
} 

void swap(char*& a,char*& b)
{
    char* temp=a;
    a=b;
    b=temp;
}    
