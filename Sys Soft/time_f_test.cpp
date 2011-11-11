#include <iostream>
#include <ctime>
using namespace std;

void function();

int main()
{
	long init_clock=clock();
	long init_time=time(0);
	cout<<time(0)<<endl;

        function();

	long final_time=time(0);
	long final_clock=clock();

        cout<<endl<<init_time<<"     "<<final_time<<endl;
        cout<<"Time difference : "<<(final_time-init_time)<<" seconds."<<endl;
        cout<<init_clock<<"   "<<final_clock<<endl;
        cout<<" Time difference : "<<((double)(final_clock-init_clock)/1000);
        cout<<endl;   	

	return 0;
}
