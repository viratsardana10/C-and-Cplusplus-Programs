#include <iostream>
#include <iomanip>
using namespace std;

//template<typename T>
void sort( int* a,int count)
{
    for(int i=1;i<count;i++)
    {
        for(int j=0;j<(count-i);j++)
        {
            if(a[j]>a[j+1])
            {
              int temp=a[j];
              a[j]=a[j+1];
              a[j+1]=temp;  
            }    
        }    
    } 
    return ;   
}

int main()
{
    int a[4]={1,3,4,2};
    sort(a,4);
    cout<<endl;
    system("pause");
    return 0;   
}    

