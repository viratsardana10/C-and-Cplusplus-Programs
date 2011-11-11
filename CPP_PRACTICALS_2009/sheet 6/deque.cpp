#include <iostream>
#include <cstring>
using namespace std;

#include "queue.h"
int x;
void instructions_queue();
void instructions_stack();

template <typename T>
void testQueue(Queue<T>& Object,const string& type)
{
  if(x==1) 
  { 
	cout<<"Testing a Stack of "<<type<<" values:\n";
	instructions_stack();

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
		Object.enqueuef(value);
		Object.print();
		break;

		case 2:
		if(Object.dequeue(value))
		     cout<<value<<" popped from the stack."<<endl;
		Object.print();
		break;
	
   }	
    }while(choice!=0);
     
     cout<<"Stack Test Ended.\n";
  }
  else if(x==2)
  {
      cout<<"Testing a Queue of "<<type<<" values:\n";
	instructions_queue();

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
		Object.enqueue1(value);
		Object.print();
		break;

		case 2:
		if(Object.dequeue(value))
		     cout<<value<<" dequeued from the Queue."<<endl;
		Object.print();
		break;
	
   }	
    }while(choice!=0);
     
     cout<<"Queue Test Ended.\n";  
  }     
}

void instructions_queue()
{
	cout<<"Enter one of the following choices:\n"
	    <<" 1 to enqueue in the Queue : \n"                          
		<<" 2 to dequeue from the Queue : \n"
		<<" 0 to end Queue testing.\n\n";
		
}
void instructions_stack()
{
    cout<<"Enter one of the following choices:\n"
	    <<" 1 to push on the Stack : \n"                          
		<<" 2 to pop from the Stack : \n"
		<<" 0 to end Stack testing.\n\n";
}

int main()
{
    int type;
    
    //int x;
    cout<<"If you want to use deque as a stack Enter 1, else \n TO use as queue Enter 2:";
    cin>>x;
    if(x==1){
    cout<<"Enter the data type of the Stack : \n" 
        <<"    1 for int data type\n"
        <<"    2 for float data type\n"
        <<"    3 for char data type\n"
        <<"    4 for string data type\nEnter: ";
        
    cin>>type;
   }
   else if(x==2)
   {
            cout<<"Enter the data type of the Queue : \n" 
        <<"    1 for int data type\n"
        <<"    2 for float data type\n"
        <<"    3 for char data type\n"
        <<"    4 for string data type\nEnter: ";
        
    cin>>type;
    
  } 
    if(type==1)
    {
	    Queue<int> intQueue;
	    testQueue(intQueue,"integer");
    }
    else if(type==2)
    {
        Queue<float> floatQueue;
	    testQueue(floatQueue,"float");
    }
    else if(type==3)
    {
        Queue<char> charQueue;
	    testQueue(charQueue,"char");
    }
    else if(type==4)
    {
        Queue<string> strQueue;
	    testQueue(strQueue,"string");
    }

	cout<<endl;
	system("pause");
	return 0;
}


