#include <iostream>
using namespace std;

#include "stackNode.h"

template <typename NODETYPE>
class Stack
{
    public:
		Stack()
			: firstPtr(0),lastPtr(0)
			{
				
			}
		
		~Stack();
		void push(const NODETYPE& );             //equivalent to insertAtFront
		bool pop(NODETYPE& );                    //equivalent to removeFromFront
		bool isEmpty() const;
		void print() const;

	private:
		Node<NODETYPE>* firstPtr;
		Node<NODETYPE>* lastPtr;
		Node<NODETYPE>* getNewNode(const NODETYPE& );
};

template <typename NODETYPE>
Stack<NODETYPE>::~Stack()
{
	cout<<"Program terminated\n";
	if(!isEmpty())
	{
		cout<<"\nDestroying Nodes ...\n";
		
		Node<NODETYPE>* currentPtr=firstPtr;
		Node<NODETYPE>* tempPtr;

		while(currentPtr!=0)
		{
			tempPtr=currentPtr;
			cout<<"node containing value "<<tempPtr->data<<" deleted \n";
			currentPtr=currentPtr->nextPtr;
			delete tempPtr;
		}
	}

	cout<<"All nodes destroyed.\n";
	
}

template <typename NODETYPE>
void Stack<NODETYPE>::push(const NODETYPE& value)
{
	Node<NODETYPE>* newPtr=getNewNode(value);

	if(isEmpty())
	{
		firstPtr=lastPtr=newPtr;
	}
	else
	{
		newPtr->nextPtr=firstPtr;
		firstPtr=newPtr;
	}
}

template <typename NODETYPE>
bool Stack<NODETYPE>::pop(NODETYPE& value)
{
	if(isEmpty())
	{
		return false;
	}
	else
	{
		Node<NODETYPE>* tempPtr=firstPtr;

		if(firstPtr==lastPtr)
			firstPtr=lastPtr=0;
		else
			firstPtr=firstPtr->nextPtr;

		value=tempPtr->data;
		delete tempPtr;
		return true;
	}
}

template <typename NODETYPE>
bool Stack<NODETYPE>::isEmpty() const
{
	return (firstPtr==0);
}

template <typename NODETYPE>
Node<NODETYPE>* Stack<NODETYPE>::getNewNode(const NODETYPE& value)
{
	return new Node<NODETYPE>(value);
}


template <typename NODETYPE>
void Stack<NODETYPE>::print() const
{
	if(isEmpty())
	{
		cout<<"The Stack is empty.\n";
	}
 else{
	Node<NODETYPE>* currentPtr=firstPtr;

	cout<<"The Stack is: ";

	while(currentPtr!=0)
	{
		cout<<currentPtr->data<<"   ";
		currentPtr=currentPtr->nextPtr;
	}
  }
	cout<<endl<<endl;
}































