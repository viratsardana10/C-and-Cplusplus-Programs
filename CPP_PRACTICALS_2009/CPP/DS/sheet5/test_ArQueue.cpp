#include <iostream>
using namespace std;
#include "ArQueue.h"


int main()
{
    ArQueue<int> test(5);
    int a=0;
    while(test.enqueue(a))
    {
        a=+2;
    }
    
    while(test.dequeue())
    {
        
    }
    
    cout<<endl;
    system("pause");
    return 0;
}
