#include <iostream>
#include <cstring>
using namespace std;

#include "queue.h"
void instructions();

template <typename T>
void testQueue(Queue<T>& Object,const string& type)
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
		Object.enqueue(value);
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

void instructions()
{
	cout<<"Enter one of the following choices:\n"
	    <<" 1 to enqueue in the Queue : \n"                          
		<<" 2 to dequeue from the Queue : \n"
		<<" 0 to end Queue testing.\n\n";
		
}

int main()
{
    int type;
    cout<<"Enter the data type of the Stack : \n" 
        <<"    1 for int data type\n"
        <<"    2 for float data type\n"
        <<"    3 for char data type\n"
        <<"    4 for string data type\nEnter: ";
        
    cin>>type;
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


