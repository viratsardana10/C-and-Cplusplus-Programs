#include <iostream>
#include <iomanip>
using namespace std;

template <typename T>
void print(const T* const array,int count)
{
    for(int i=0;i<count;i++)
    {
        cout<<array[i]<<setw(3);
    }    
}    

int main()
{
   int a[3]={1,2,3};
   print(a,3);
   cout<<endl;
   system("pause");
   return 0;
}

   
