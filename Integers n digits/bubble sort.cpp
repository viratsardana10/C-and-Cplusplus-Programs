#include <iostream>
using namespace std;

int main()
{
    int a[5]={1,3,6,7,2};
    int n=5;
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<(n-i);j++)
        {
            if(a[j]>a[j+1])
            {
               //swap(a[j],a[j+1]);
               int temp=a[j];
               a[j]=a[j+1];
               a[j+1]=temp;
            }
        }
    }
    
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<"   ";
    }    
                  
    cout<<endl;
    system("pause");
    return 0;
}    
