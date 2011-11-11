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
		
		void insert(const NODETYPE& );
		bool remove(NODETYPE& );
		bool search(NODETYPE );
		bool isEmpty() const;
		void print() const;
		void print(NODETYPE );
		void printk(NODETYPE ,int );
		
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
void List<NODETYPE>::insert(const NODETYPE& value)
{
	Node<NODETYPE>* newPtr=getNewNode(value);

	if(isEmpty())
	{
		firstPtr=lastPtr=newPtr;
	}
	else
	{
        if(firstPtr==lastPtr)
        {
            if(value>firstPtr->data)
            {
                 firstPtr->nextPtr=newPtr;
                 lastPtr=newPtr;
                 newPtr->prevPtr=firstPtr;
            }
            else{
                firstPtr=newPtr;
                newPtr->nextPtr=lastPtr;
                lastPtr->prevPtr=newPtr;
            }
        }
        else{
        Node<NODETYPE>* currentPtr=firstPtr;
        Node<NODETYPE>* indexPtr=0;
        cout<<"in insert\n";
        if(value<(currentPtr->data))
        {
            
            newPtr->nextPtr=firstPtr;
            firstPtr->prevPtr=newPtr;
            firstPtr=newPtr;
        }
         else if(value>lastPtr->data)
        {
            lastPtr->nextPtr=newPtr;
            newPtr->prevPtr=lastPtr;
            lastPtr=newPtr;
        }
        else{
        while(currentPtr!=0 && value>(currentPtr->data))
        {
            currentPtr=currentPtr->nextPtr;
            
        }
        cout<<"after while\n";
        if(currentPtr==0)
        {
            cout<<"at the end of list\n";
        }
        
        indexPtr=currentPtr->prevPtr;
        indexPtr->nextPtr=newPtr;
        newPtr->prevPtr=indexPtr;
        newPtr->nextPtr=currentPtr;
        currentPtr->prevPtr=newPtr;   
        cout<<"after completion\n"; 
        }
        }
     }
}

template <typename NODETYPE>
bool List<NODETYPE>::remove(NODETYPE& value)
{
	if(isEmpty())
	{
		return false;
	}
	else
	{
      Node<NODETYPE>* tempPtr=0;
        
      if(value==firstPtr->data)
      {
          tempPtr=firstPtr;  
          firstPtr=firstPtr->nextPtr;   
      }
      else if(value==lastPtr->data)
      {
            tempPtr=lastPtr;
            lastPtr=lastPtr->prevPtr;
      }  
	  else{	

		if(firstPtr==lastPtr)
		{
            firstPtr=lastPtr=0;
            tempPtr=firstPtr;
        }

		else
		{
			Node<NODETYPE>* currentPtr=firstPtr;
			Node<NODETYPE>* rightPtr=0;
			Node<NODETYPE>* leftPtr=0;

			while(value!=(currentPtr->data))
				currentPtr=currentPtr->nextPtr;
				
			tempPtr=currentPtr;
            rightPtr=currentPtr->nextPtr;
            leftPtr=currentPtr->prevPtr;	

            leftPtr->nextPtr=rightPtr;
            rightPtr->prevPtr=leftPtr;
			//lastPtr=currentPtr;
			//lastPtr->nextPtr=0;
		}
       }         
		//value=tempPtr->data;
		delete tempPtr;
		return true;
	}
}

template <typename NODETYPE>
bool List<NODETYPE>::search(NODETYPE value)
{
    if(value==firstPtr->data)
    {
        cout<<value<<"present at front.\n";
        return true;
    }
    else if(value==lastPtr->data)
    {
        cout<<value<<"present at end of list.\n";
        return true;
    }
    else
    {
        int i=1;
        Node<NODETYPE>* currentPtr=firstPtr;
        
        while(currentPtr!=0 && value!=(currentPtr->data))
        {
			currentPtr=currentPtr->nextPtr;
			i++;
        }
        if(currentPtr!=0){
        cout<<value<<" present at "<<i<<"th position from front.\n";
        return true;
        }
        else{
            cout<<value<<" is not present in the list.\n";
            return false;
        }
    }
    return false;
    
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

template <typename NODETYPE>
void List<NODETYPE>::print(NODETYPE value)
{
	if(isEmpty())
	{
		cout<<"The list is empty.\n";
	}
    
	Node<NODETYPE>* currentPtr=firstPtr;
    
	cout<<"The List before "<<value<<" is: ";

	while(value!=currentPtr->data)
	{
		cout<<currentPtr->data<<"   ";
		currentPtr=currentPtr->nextPtr;
	}

	cout<<endl;
}
		
template <typename NODETYPE>
void List<NODETYPE>::printk(NODETYPE value,int k)
{
	if(isEmpty())
	{
		cout<<"The list is empty.\n";
	}
    
	Node<NODETYPE>* currentPtr=firstPtr;
    
	cout<<"The List before "<<value<<" is: ";
    int i=0;
	while(value!=currentPtr->data )
	{
		//cout<<currentPtr->data<<"   ";
		currentPtr=currentPtr->nextPtr;
		//i++;
	}
	Node<NODETYPE>* ptr=currentPtr;
	
		while(i<k && currentPtr!=0)
	{
		currentPtr=currentPtr->prevPtr;
		if(currentPtr!=0){
		cout<<currentPtr->data<<"   ";
        }
		i++;
	}

	cout<<endl;
	cout<<"The List after "<<value<<" is: ";
	int j=0;
		while(j<k && ptr!=0)
	{
		ptr=ptr->nextPtr;
		if(ptr!=0){
		cout<<ptr->data<<"   ";
        }
		j++;
	}
	cout<<endl;
}
