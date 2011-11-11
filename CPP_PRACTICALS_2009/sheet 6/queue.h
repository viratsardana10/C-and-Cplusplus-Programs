#include "queueNode.h"

template <typename NODETYPE>
class Queue
{
	public:
		Queue()
			: firstPtr(0),lastPtr(0)
			{
				
			}
		
		~Queue();
		void enqueue1(const NODETYPE& );
        void enqueuef(const NODETYPE& );             
		bool dequeue(NODETYPE& );                    
		bool isEmpty() const;
		void print() const;

	private:
		Node<NODETYPE>* firstPtr;
		Node<NODETYPE>* lastPtr;
		Node<NODETYPE>* getNewNode(const NODETYPE& );
};

template <typename NODETYPE>
Queue<NODETYPE>::~Queue()
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
void Queue<NODETYPE>::enqueue1(const NODETYPE& value)
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
void Queue<NODETYPE>::enqueuef(const NODETYPE& value)
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
bool Queue<NODETYPE>::dequeue(NODETYPE& value)
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
		{
			Node<NODETYPE>* currentPtr=firstPtr;
           
            firstPtr=firstPtr->nextPtr;
            
		}
                
		value=tempPtr->data;
		delete tempPtr;
		cout<<value<<" removed from deque.\n";
	}
}

template <typename NODETYPE>
bool Queue<NODETYPE>::isEmpty() const
{
	return (firstPtr==0);
}

template <typename NODETYPE>
Node<NODETYPE>* Queue<NODETYPE>::getNewNode(const NODETYPE& value)
{
	return new Node<NODETYPE>(value);
}

template <typename NODETYPE>
void Queue<NODETYPE>::print() const
{
	if(isEmpty())
	{
		cout<<"The deque is empty.\n";
	}
   else
   {
        
	Node<NODETYPE>* currentPtr=firstPtr;

	cout<<"The deque is: ";

	while(currentPtr!=0)
	{
		cout<<currentPtr->data<<"   ";
		currentPtr=currentPtr->nextPtr;
	}
  }
	cout<<endl;
}
