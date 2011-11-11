#include <iostream>
using namespace std;

int main()
{
    int j=0;
    int k=1;
    
    cout<<"f0 = "<<j<<endl<<"f1 = "<<k<<endl;
    for(int i=2;i<=10;i++)
    {
        int m=(j+k);
        cout<<"f"<<i<<" = "<<m<<endl;
        j=k;
        k=m;
    }    
    system("pause");
    return 0;
}    
