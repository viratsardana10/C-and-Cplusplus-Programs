#include <iostream>
using namespace std;

int sum(int (*)(int ),int );
int add(int);
int square(int );
int cube(int );

int main()
{
    cout<<sum(add,4)<<endl;
    cout<<sum(square,4)<<endl;
    cout<<sum(cube,4)<<endl;
    
    system("pause");
    return 0;
}    

int sum(int (*fPtr)(int),int m)
{
    cout<<(*fPtr)<<"   ";
   // (*ptr)()=fPtr;
    int sum=0;
    for(int i=1;i<=m;i++)
    {
        sum+=(*fPtr)(i);
    }
    return sum;       
} 

int add(int n)
{
    return n;
}     
   
int square(int n)
{
    return n*n;
}    

int cube(int n)
{
    return n*n*n;
}    
