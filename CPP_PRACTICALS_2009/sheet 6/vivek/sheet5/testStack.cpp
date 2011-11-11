#include <iostream>
#include <cstring>
using namespace std;

#include "stack.h"

void instructions();

template <typename T>
void testStack(Stack<T>& Object,const string& type)
{
	cout<<endl<<"Testing a list of "<<type<<" values:\n";
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
		Object.push(value);
		Object.print();
		break;

		case 2:
		if(Object.pop(value))
		      cout<<value<<" popped from the Stack."<<endl;
		Object.print();
		break;

	}
  }
     while(choice!=0);
     
     cout<<"Stack Test Ended.\n";     
}

void instructions()
{
	cout<<"Enter one of the following choices:\n"
		<<" 1 to push on the Stack : \n"                          
		<<" 2 to pop from the Stack : \n"
		<<" 0 to end List testing\n\n";
}

int main()
{
    int type;
    cout<<"Enter the data type of the Stack : \n" 
        <<"1 for int type\n"
        <<"2 for float type\n"
        <<"3 for char type\n";
        
    cin>>type;
    
    
   switch(type)
    {
       case 1:
            Stack<int> integerStack;
	        testStack(integerStack,"integer");
             break;
             
      
    }
    

	cout<<endl;
	system("pause");
	return 0;
}
