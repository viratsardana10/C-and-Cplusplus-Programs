#include <iostream>
using namespace std;

int read(char**);
//int compare(char** ,int ,int );
//void swap(char*& ,char*& );
//void sort(char** ,int ,int (*)(char** ,int ,int ),void (*)(char*& ,char*& ));
//void print(char* ,int);

int main()
{
    char** name;
    
    int n=read(name);
    cout<<n;
   //print(name,size);
   // sort(name,size,compare,swap);
   // print(name,size);
   
     
    for(int i=0;i<n;i++)
    {
        cout<<name[i]<<endl;
    }  
                  
    cout<<endl;
    system("pause");
    return 0;
}

int read(char** s)
{
    s=new char*;
    cout<<"Enter the names ,enter 0 to terminate:\n";
    int i=0;
    do
    {
        cout<<(i+1)<<" : ";
        s[i]=new char;
        cin>>s[i];
        i++;
    }
    while(*s[(i-1)]!='0');
    
    return (i-1);        
}
/*
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
/*
void print(char* s,int n)
{
   for(int i=0;i<n;i++)
    {
        cout<<s[i]<<endl;
    }                      
} */                   
