#include <iostream>
using namespace std;

int main()
{
    int n;
    char** a;
    cout<<"Enter a num:";
    cin>>n;
    a=new char*[n];
    ////////////////////////////////////////////////
    cout<<"Enter "<<n<<" names:";
    for(int i=0;i<n;i++)
    {
        a[i]=new char;
        cin>>a[i];
    } 
    cout<<"________________________________________________"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i];
        cout<<endl;
    }       
    cout<<endl;
    system("pause");
    return 0;
}    
