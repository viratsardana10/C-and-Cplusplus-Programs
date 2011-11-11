#include <thread>
#include <iostream>
using namespace std;

void write_sum(int x,int y)
{
    cout<<x<<" + "<<y<<" = "<<(x+y)<<endl;
}

int main()
{
    thread t(write_sum,123,456);
    t.join();
    return 0;
}

