# include <iostream>
using namespace std;

int main()
{
	int a=5;
	int* p=&a;
	
	cout<<p<<a<<sizeof(a)<<"   "<<sizeof(p);
	
	cout<<endl;
	system("pause");
	return 0;
}
