#include <iostream>
#include <string>
using namespace std;

#include "list.h"
void instructions();

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
		listObject.insert(value);
		listObject.print();
		break;

		case 2:
        cout<<"Enter "<<type<<": ";
		cin>>value;    
		if(listObject.remove(value))
			cout<<value<<" removed from list\n";
		listObject.print();
		break;
		
		case 3:
        cout<<"Enter "<<type<<": ";
		cin>>value; 
        listObject.search(value);
        
        case 4:
         cout<<"Enter "<<type<<": ";
		cin>>value; 
         listObject.print(value); 
         break; 
         
         case 5:
                int k;
         cout<<"Enter "<<type<<": ";
		cin>>value;
		cout<<"Enter unit : ";
		cin>>k;
		listObject.printk(value,k); 
               
          
   }	
    }while(choice!=0);
     
     cout<<"List Test Ended.\n";  
}

void instructions()
{
	cout<<"Enter one of the following choices:\n"
		<<" 1 to insert in the List\n"
		<<" 2 to remove from the List\n"
		<<" 3 to search from the List\n"
		<<" 4 to print elements preceding a key\n"
		<<" 5 to print elements within k unit\n"
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


