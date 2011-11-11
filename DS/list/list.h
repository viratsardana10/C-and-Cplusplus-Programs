#include <iostream>
using namespace std;

#include "listnode.h"

template <typename NODETYPE>
class List
{
	public:
		List()
			: firstPtr(0),lastPtr(0)
			{
				
			}
		
		~List();
		void insertAtFront(const NODETYPE& );
		void insertAtBack(const NODETYPE& );
		bool removeFromFront(NODETYPE& );
		bool removeFromBack(NODETYPE& );
		bool isEmpty() const;
		void print() const;

	private:
		Node<NODETYPE>* firstPtr;
		Node<NODETYPE>* lastPtr;
		Node<NODETYPE>* getNewNode(const NODETYPE& );
};

template <typename NODETYPE>
List<NODETYPE>::~List()
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
void List<NODETYPE>::insertAtFront(const NODETYPE& value)
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
void List<NODETYPE>::insertAtBack(const NODETYPE& value)
{
	Node<NODETYPE>* newPtr=getNewNode(value);

	if(isEmpty())
	{
		firstPtr=lastPtr=newPtr;
	}
	else
	{
		lastPtr->nextPtr=newPtr;
		lastPtr=newPtr;
	}
}

template <typename NODETYPE>
bool List<NODETYPE>::removeFromFront(NODETYPE& value)
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
bool List<NODETYPE>::removeFromBack(NODETYPE& value)
{
	if(isEmpty())
	{
		return false;
	}
	else
	{
		Node<NODETYPE>* tempPtr=lastPtr;

		if(firstPtr==lastPtr)
			firstPtr=lastPtr=0;

		else
		{
			Node<NODETYPE>* currentPtr=firstPtr;

			while(currentPtr->nextPtr!=lastPtr)
				currentPtr=currentPtr->nextPtr;

			lastPtr=currentPtr;
			lastPtr->nextPtr=0;
		}
                
		value=tempPtr->data;
		delete tempPtr;
	}
}

template <typename NODETYPE>
bool List<NODETYPE>::isEmpty() const
{
	return (firstPtr==0);
}

template <typename NODETYPE>
Node<NODETYPE>* List<NODETYPE>::getNewNode(const NODETYPE& value)
{
	return new Node<NODETYPE>(value);
}

template <typename NODETYPE>
void List<NODETYPE>::print() const
{
	if(isEmpty())
	{
		cout<<"The list is empty.\n";
	}

	Node<NODETYPE>* currentPtr=firstPtr;

	cout<<"The List is: ";

	while(currentPtr!=0)
	{
		cout<<currentPtr->data<<"   ";
		currentPtr=currentPtr->nextPtr;
	}

	cout<<endl;
}



















	





















