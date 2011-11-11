#include <iostream>
#include <iomanip>
using namespace std;

template<typename T>
void sort( T* a,int count)
{
    for(int i=1;i<count;i++)
    {
        for(int j=0;j<(count-i);j++)
        {
            if(a[j]>a[j+1])
            {
              T temp=a[j];
              a[j]=a[j+1];
              a[j+1]=temp;  
            }    
        }    
    }    
}

template<typename A>
void print(const A* const array,int count)
{
    for(int i=0;i<count;i++)
    {
        cout<<array[i]<<setw(3);
    }    
}  
      
int main()
{
   // int a[7]={1,3,5,4,9,2,7};
    char a[]="vivek";
    //int size=strlen(a);
    int size=sizeof(a)/sizeof(char);
    print(a,size);
    cout<<endl;
    sort(a,size);
    print(a,size);
    cout<<endl;
    system("pause");
    return 0;
}  

