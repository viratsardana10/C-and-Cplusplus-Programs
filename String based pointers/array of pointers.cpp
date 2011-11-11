#include <iostream>
using namespace std;

int main()
{
    char* a[3]={"vivekprakash","anshul","aniket"};
    cout<<*a[0]<<"    "<<a[0]<<"   "<<(a[0]+1)<<"    "<<*(a[0]+1)<<a[0]-(a[0]+1)<<endl;
    cout<<(a[2])<<"    "<<strlen(a[0]);
    
    cout<<endl;
    system("pause");
    return 0;
    
}    
