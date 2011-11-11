#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	long a=1;
	cout<<a<<endl;

	cout<<clock()<<endl;

	cout<<time(0)<<endl;
    
   	
	for(long i=0;i<10;i++)
	{
            a*=2;
	}
       
	cout<<a<<endl<<time(0);
	cout<<endl;
	return 0;
}
