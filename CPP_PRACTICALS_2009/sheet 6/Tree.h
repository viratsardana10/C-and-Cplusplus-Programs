#include <iostream>
#include "TreeNode.h"
using namespace std;

template <typename T>
class Tree
{
    public:
        Tree()
        :rootPtr(0)
        {
                
        }
        void insert(T& );
        bool del(T& );
        void search(T& );
        
        void inOrder();
        bool isEmpty();
  
    private:
        Node<T>* rootPtr;
        Node<T>* getNewNode(T& );
        void insert(Node<T>** ,T& );
        void inOrder(Node<T>* );
           
};

template <typename T>
void Tree<T>::insert(T& value)
{
    insert(&rootPtr,value);
}

template <typename T>
void Tree<T>::insert(Node<T>** ptr,T& value)
{
    if(*ptr==0)
       *ptr=getNewNode(value);
    else
    {
        if(value < (*ptr)->data)
            insert(&((*ptr)->leftPtr),value);
        else
        {
            if(value > (*ptr)->data)
                insert(&((*ptr)->rightPtr),value);
            else
                cout<<value<<" duplicate found in tree.\n";    
        }    
        
    }
}

template <typename T>
Node<T>* Tree<T>::getNewNode(T& value)
{
    return new Node<T>(value);
}

template <typename T>
void Tree<T>::inOrder()
{
    inOrder(rootPtr);
}

template <typename T>
void Tree<T>::inOrder(NOde<T>* ptr )
{
    if(ptr!=0)
    {
        inOrder(ptr->leftPtr);
        cout<<ptr->data<<"  ";
        inOrder(ptr->rightPtr);
    }

}
