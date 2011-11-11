#include <iostream>
#include "list.h"
using namespace std;


void instructions()
{
	cout<<"Enter one of the following choices:\n"
		<<" 1 to insert. \n"
		<<" 2 to search. \n"
		<<" 0 to end Hash Table testing.\n";
}

template <typename T>
void testHash(List<T> a[],const string& type,int m)
{
	cout<<"Testing a Hash Table of "<<type<<" values:\n";
	instructions();

    int index;
	int choice;
	T value;
     do
     {
        cout<<"Enter choice: ";
        cin>>choice;	

	switch(choice)
	{
		case 1:
		cout<<"Enter "<<type<<": ";
		cin>>value;
		
		index=(value%m);
		(a[index]).insertAtFront(value);

		break;

		case 2:
		cout<<"Enter "<<type<<": ";
		cin>>value;
		index=(value%m);

		a[index].search(value);
		(a[index]).print();
		break;
	}
     }
     while(choice!=0);
     
     cout<<"Hash Test Ended.\n";     
}

int main()
{
	int n;
	cout<<"Enter the size of Hash Table: ";
	cin>>n;

	List<int> a[n];

        testHash(a,"integer",n);

        system("pause");
        return 0;	

}
