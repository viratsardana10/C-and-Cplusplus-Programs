#include <iostream>
#include <string>
using namespace std;

#include "list.h"

template <typename T>
void testList(List<T>& listObject,const string& type)
{
	cout<<"Testing a list of "<<type<<" values:\n";
	instructions();

	int choice;
	T value;
     do
     {
        cout<<"? ";
        cin>>choice;	

	switch(choice)
	{
		case 1:
		cout<<"Enter "<<type<<": ";
		cin>>value;
		listObject.insertAtFront(value);
		listObject.print();
		break;

		case 2:
		cout<<"Enter "<<type<<": ";
		cin>>value;
		listObject.insertAtBack(value);
		listObject.print();
		break;

		case 3:
		if(listObject.removeFromFront(value))
			cout<<value<<" removed from list\n";
		listObject.print();
		break;

		case 4:
		if(listObject.removeFromBack(value))
			cout<<value<<" removed from list\n";
		listObject.print();
	}
     }
     while(choice!=0);
     
     cout<<"List Test Ended.\n";     
}

void instructions()
{
	cout<<"Enter one of the following choices:\n"
		<<" 1 to insert at beginning of List\n"
		<<" 2 to insert at end of List\n"
		<<" 3 to delete from beginning of List\n"
		<<" 4 to delete from end of List\n"
		<<" 0 to end List testing\n";
}

int main()
{
	List<int> integerList;
	testList(integerList,"integer");

	cout<<endl;
	system("pause");
	return 0;
}

























