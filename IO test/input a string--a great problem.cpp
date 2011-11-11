#include <iostream>
using namespace std;

int main()
{
    
    char* s;
    s=new char;   //here it is all right
    cin>>s;
    cout<<s<<endl;
    
    
    //the problem starts here...........
    //u cant input a string greater than 
    //8 character in a dynamically created
    //array of pointers....!!!!! 
    char** a;
    int n;
    cout<<"Enter a positive integer:";
    cin>>n;
    
    a=new char*[n];
    cout<<"Enter "<<n<<" names:"<<endl;
    
    for(int i=0;i<n;i++)
    {
        cout<<(i+1)<<": ";
        a[i]=new char;
        cin>>a[i];
        cout<<endl;
    } 
    
    system("pause");
    return 0;
}    
