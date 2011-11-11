#include <iostream>
using namespace std;

void sieve(int[] ,int);
int main()
{
    int *a,s;
    cout<<"Enter the size of array:";
    cin>>s;
    a=new int[s];
    sieve(a,s);
    
    cout<<endl;
    system("pause");
    return 0;
}

void sieve(int a[],int s)
{
    for(int i=0;i<s;i++)
    {
        a[i]=1;
    }
    
    for(int i=2;i<s;i++)
    {
        if(a[i]==1){
         int k=1;
        for(int j=i;j<s;(j=i*k))
        {
            if(j!=i)
              a[j]=0;
              
             k++;
        }
      } 
    }
    
    int k=0;
    for(int i=s-5;i<s;i++)
    {
        if(a[i]==1)
        {
          cout<<i<<"   ";
          k++;
          if((k%7)==0)
          cout<<endl<<endl;
        }
       // if((k%7)==0)
       // cout<<endl; 
    }
}
