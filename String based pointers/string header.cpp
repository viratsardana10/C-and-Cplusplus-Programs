#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name,_name;
    cout<<"Enter your name:";
    getline(cin,name);
    //name="vivek";
    int size=name.length();
    _name=name.substr(0,6);
    cout<<name<<"     "<<name[0]<<"  "<<name[1]<<"    "<<size<<endl<<_name;
    cout<<endl;
    //////////////////////////////////////////////////////////////////////
    string a[]={"vivek","vineet"};
    cout<<(a[1]);
    cout<<endl;
    system("pause");
    return 0;
}    
