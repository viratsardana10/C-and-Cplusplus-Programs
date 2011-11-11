#include <iostream>
#include "ArStack.h"
using namespace std;

int main()
{
	ArStack<int> intStack(10);
	int choice;
	cout<<"Enter 1 to push and 2 to pop:\n & 0 to end the stack testing.";
	//cin>>choice;
	
     do{
          cout<<"? ";
          cin>>choice;               
	switch(choice)
	{
		case 1:
			int value;
			cout<<"Enter the value:";
			cin>>value;
			if(intStack.push(value))
				intStack.print();
			break;
		case 2:
		//	int value;
			if(intStack.pop(value))
				cout<<value<<" popped from Stack.\n";
			 intStack.print();
		         break;
		default:
			 ;
             
	}
     }while(choice!=0);

	return 0;

           
  
}
