#include <iostream>
#include <cstring>
using namespace std;

int compare(char** ,int ,int );
void swap(char*& ,char*& );
void sort(char** ,int ,int (*)(char** ,int ,int ),void (*)(char*& ,char*& ));

int main()
{
    char** name;
    
    name=new char*;
    cout<<"Enter the names ,enter 0 to terminate:\n";
    int n=0;
    do
    {
        cout<<(n+1)<<" : ";
        name[n]=new char;
        cin>>name[n];
        n++;
    }
    while(*name[(n-1)]!='0'); 
    n=n-1;
    
    sort(name,n,compare,swap); 
    
    cout<<"_______________________________________________"<<endl;
    cout<<"The names in alphabetical order are: \n"<<endl;
    for(int i=0;i<(n);i++)
    {
        cout<<(i+1)<<" : "<<name[i]<<endl;
    } 
    
    cout<<endl;                      
    system("pause");
    return 0; 
} 


int compare(char** a,int x,int y)
{
    int flag=strcmp(a[x],a[y]);
    return flag;
}

void swap(char*& a,char*& b)
{
    char* temp=a;
    a=b;
    b=temp;
}

void sort(char** s,int n,int (*compare)(char** ,int ,int),void (*swap)(char*& ,char*&))
{
     for(int i=1;i<n;i++)
    {
            for(int j=0;j<(n-i);j++)
        {
            int flag=compare(s,j,(j+1));
            if(flag==1)
                swap(s[j],s[j+1]);
            else if(flag==0)
            {
                if(strlen(s[j])>strlen(s[j+1]))
                   swap(s[j],s[j+1]); 
            }    
        }    
    }
} 

