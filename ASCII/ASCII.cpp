#include <iostream>
using namespace std;

int main()
{
    char s;
    s=66;
    cout<<(s=66)<<endl;
    
    for(int i=0;i<100;i++)
    {
        s=i;
        cout<<i<<"   "<<s<<endl<<"_________"<<endl;
    }    
    
    return 0;
}    
