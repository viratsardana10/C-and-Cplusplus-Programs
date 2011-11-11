#include <iostream>
using namespace std;

#include "listnode.h"

template <typename T>
class List
{
	public:
		List()
			: firstPtr(0),lastPtr(0)
			{
				
			}
		
		~List();
		void insertAtFront(const T& );
		void insertAtBack(const T& );
		bool removeFromFront(T& );
		bool removeFromBack(T& );
		bool isEmpty() const;
		void print() const;
                void search(T );

	private:
		Node<T>* firstPtr;
		Node<T>* lastPtr;
		Node<T>* getNewNode(const T& );
};

template <typename T>
List<T>::~List()
{
	cout<<"Program terminated\n";
	if(!isEmpty())
	{
		cout<<"\nDestroying Nodes ...\n";
		
		Node<T>* currentPtr=firstPtr;
		Node<T>* tempPtr;

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

template <typename T>
void List<T>::insertAtFront(const T& value)
{
	Node<T>* newPtr=getNewNode(value);

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

template <typename T>
void List<T>::insertAtBack(const T& value)
{
	Node<T>* newPtr=getNewNode(value);

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

template <typename T>
bool List<T>::removeFromFront(T& value)
{
	if(isEmpty())
	{
		return false;
	}
	else
	{
		Node<T>* tempPtr=firstPtr;

		if(firstPtr==lastPtr)
			firstPtr=lastPtr=0;
		else
			firstPtr=firstPtr->nextPtr;

		value=tempPtr->data;
		delete tempPtr;
		return true;
	}
}

template <typename T>
bool List<T>::removeFromBack(T& value)
{
	if(isEmpty())
	{
		return false;
	}
	else
	{
		Node<T>* tempPtr=lastPtr;

		if(firstPtr==lastPtr)
			firstPtr=lastPtr=0;

		else
		{
			Node<T>* currentPtr=firstPtr;

			while(currentPtr->nextPtr!=lastPtr)
				currentPtr=currentPtr->nextPtr;

			lastPtr=currentPtr;
			lastPtr->nextPtr=0;
		}
                
		value=tempPtr->data;
		delete tempPtr;
	}
}

template <typename T>
bool List<T>::isEmpty() const
{
	return (firstPtr==0);
}

template <typename T>
Node<T>* List<T>::getNewNode(const T& value)
{
	return new Node<T>(value);
}

template <typename T>
void List<T>::print() const
{
	if(isEmpty())
	{
		cout<<"The list is empty.\n";
	}

	Node<T>* currentPtr=firstPtr;

	cout<<"The List is: ";

	while(currentPtr!=0)
	{
		cout<<currentPtr->data<<"   ";
		currentPtr=currentPtr->nextPtr;
	}

	cout<<endl;
}

template <typename T>
void List<T>::search(T value)
{
      if(isEmpty())
      {
	      cout<<value<<" is not present.\n";
	      return;
      }
      else
      {
	      Node<T>* ptr=firstPtr;
		      while(ptr!=0)
		      {
			      if((ptr->data)==value)
			      {
				      cout<<value<<" is present.\n";
				      return;
			      }
			      ptr=ptr->nextPtr;
		      }
	      cout<<value<<" is not present.\n";

      }


}

















	





















