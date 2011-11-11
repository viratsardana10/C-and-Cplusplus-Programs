#include <iostream>
using namespace std;

template<typename T1,typename T2>
void print(T1 value1,T2 value2)
{
    T1& value13=value1;
    T2& value24=value2;
    cout<<value13<<"  "<<value1<<endl;
    cout<<++value24<<"  "<<value2<<endl;
}     

template<typename T>
void print(T* a,int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<a[i]<<"  ";
    }    
}    
int main()
{
    int a=1;
    double b=2.3;
    print(a,b);
    
    char array[]="vivek";
    int size=sizeof(array)/sizeof(char);
    print(array,size);
    cout<<endl;
    
    int arr[4]={1,2,3,4};
    print(arr,4);
    cout<<endl;    
    system("pause");
    return 0; 
}    
