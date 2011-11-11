#include <iostream>
using namespace std;

template <typename NODETYPE>

class LinkedList
{
    public:
        LinkedList()
        {
            firstPtr=0;
            lastPtr=0;
        }
        
        ~LinkedList();
        
        void createList();
        
        void insertAtBeginning(NODETYPE& );
        void insertAtI(int ,NODETYPE& );
        void insertAtEnd(NODETYPE& );
        
        bool deleteFirst(NODETYPE& );
        bool deleteAtI(int ,NODETYPE& );
        bool deleteLast(NODETYPE& );
        bool deleteNode(int ,NODETYPE& );
        
        void search(const NODETYPE& );
        void displayList();
        bool isEmpty();
        
    private:
        ListNode<NODETYPE>* firstPtr;
        ListNode<NODETYPE>* lastPtr; 
        ListNode<NODETYPE>* getNewNode(const NODETYPE& value)
        {
            return new ListNode<NODETYPE>(value);
        } 
};
template<typename NODETYPE>
void LinkedList<NODETYPE>::create()
{
    
}

template<typename NODETYPE>
void LinkedList<NODETYPE>::insertAtBeginning(NODETYPE& value)
{
    ListNode<NODETYPE>* newPtr=getNewNode(value);
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
    
template<typename NODETYPE>
void LinkedList<NODETYPE>::insertAtI(NODETYPE& value)
{
}
    
template<typename NODETYPE>
void LinkedList<NODETYPE>::insertAtEnd(NODETYPE& value)
{
    ListNode<NODETYPE>* newPtr=getNewNode(value);
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
    
template<typename NODETYPE>
bool LinkedList<NODETYPE>::deleteFirst(NODETYPE& value)
{
    ListNode<NODETYPE>* tempPtr=firstPtr;
    if(firstPtr=lastPtr)
    {
        firstPtr=lastPtr=0;
        delete tempPtr;
    }
    else
    {
        firstPtr=firstPtr->nextPtr;
        
        value=tempPtr->data;
        delete tempPtr;
        
    }
}
    
template<typename NODETYPE>
bool LinkedList<NODETYPE>::deleteAtI(int index,NODETYPE& value)
{
    ListNode<NODETYPE>* tempPtr;
    if(first)
    {
        firstPtr=lastPtr=0;
    }
    else
    {/*
        while(int i=1;i<index;i++)
        {
            tempPtr=firstPtr->nextPtr;
            
        } */
    }
}
    
template<typename NODETYPE>
bool LinkedList<NODETYPE>::deleteLast(NODETYPE& value)
{
    ListNode<NODETYPE>* tempPtr=lastPtr;
    if(firstPtr=lastPtr)
    {
        firstPtr=lastPtr=0;
    }
    else
    {
        ListNode<NODETYPE>* currentPtr;
        
    }
}
    
template<typename NODETYPE>
bool LinkedList<NODETYPE>::
    
template<typename NODETYPE>
void LinkedList<NODETYPE>::
  
template<typename NODETYPE>
void LinkedList<NODETYPE>::
    
template<typename NODETYPE>
void LinkedList<NODETYPE>::    
