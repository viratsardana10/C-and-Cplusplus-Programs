#include <iostream>
using namespace std;

int main()
{
    char* s="abcd";
    cout<<(s[0]+2)<<"  "<<*(s+2)<<endl; // *(s[0]+2) is an error coz s[0]+2 is simply an integer.
    cout<<s<<endl;
    return 0;
}    
