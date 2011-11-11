
#include <iostream>
#include <cstring>
using namespace std;

int digits;
int a1[10],a2[10];
int size(int ,int []);
bool perm(int ,int );
int main()
{
    int m,n;
    cout<<"Enter two positive integers:"<<endl;
    cout<<"Integer 1:";
    cin>>m;
    cout<<"Integer 2:";
    cin>>n;
    
    bool flag=perm(m,n);
    if(flag)
    {    
      cout<<"They are permutations of same digits:";
      for(int j=0;j<digits;j++)
    {
        cout<<a1[j]<<"   "; 
    } 
    cout<<endl; 
    }      
    else
      cout<<"They are different integers.";
      cout<<endl;
      system("pause");
      return 0;      
}    

bool perm(int m,int n)
{ 
    int size1,size2; 
    size1=size(m,a1);
    size2=size(n,a2);
  
    if(!(size1==size2))
     return false;
    else if(size1==size2)
    {
        for(int i=0;i<size1;i++)
        {
            if(!(a1[i]==a2[i]))
            return false;
        }    
    }
    else return true;         
} 

int size(int m,int a[])
{
      
    int i=0;
    while(m>0)
    {
        a[i]=(m%10);
        m=(m/10);
        
        digits=i+1;
        i++;
    } 
    for(int j=1;j<digits;j++)
    {
        for(int k=0;k<(digits-j);k++)
        if(a[k]>a[k+1])
        {
            int temp=a[k];
            a[k]=a[k+1];
            a[k+1]=temp;
        }    
    }    
        
    return digits;   
}       








