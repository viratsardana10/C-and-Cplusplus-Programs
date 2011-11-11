#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    //unsigned seed;
    //cin>>seed;
    //srand(seed);
    srand(time(0));
    
    for(int i=0;i<=10;i++)
    {
        cout<<"   "<<(1+rand()%5);
    }    
    cout<<endl;
    system("pause");
    return 0;
}
