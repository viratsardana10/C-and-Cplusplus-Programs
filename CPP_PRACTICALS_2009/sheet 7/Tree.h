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
        void del(T );
        void search(T );
      //  T minimum();
      //  T maximum();
      //  T successor(T );
      //  T predecessor(T );
        
        
        void inOrder();
        void preOrder();
        void postOrder();
     //   bool isEmpty();
     
        Node<T>* search(Node<T>* ,T );
        int totalNodes();
        T sum();
        int leafNodes();
        int depth();
        void del(Node<T>* );
        Node<T>* minimum(Node<T>* );
        Node<T>* maximum(Node<T>* );
        Node<T>* successor(Node<T>* );
        Node<T>* predecessor(Node<T>* );
  
    private:
        Node<T>* rootPtr;
        Node<T>* getNewNode(T& );
        void insert(Node<T>* ,Node<T>** ,T& );
        void inOrderT(Node<T>* );
        void preOrderT(Node<T>* );
        void postOrderT(Node<T>* );
        
        void totalNodesT(Node<T>* ,int& );
        void sumT(Node<T>* ,T& );
        void leafNodesT(Node<T>* ,int& );   
        void depthT(Node<T>* ,int& ,int& );
};

template <typename T>
void Tree<T>::insert(T& value)
{
    insert(0,&rootPtr,value);
}

template <typename T>
void Tree<T>::insert(Node<T>* parent=0,Node<T>** ptr,T& value)
{
    if(*ptr==0)
    {
       *ptr=getNewNode(value);
       (*ptr)->parent=parent;
    }
    else
    {
        if(value < (*ptr)->data)
            insert((*ptr),&((*ptr)->leftPtr),value);
        else
        {
            if(value > (*ptr)->data)
                insert((*ptr),&((*ptr)->rightPtr),value);
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
    inOrderT(rootPtr);
}

template <typename T>
void Tree<T>::inOrderT(Node<T>* ptr)
{
    if(ptr!=0)
    {
        inOrderT(ptr->leftPtr);
        cout<<(ptr->data)<<"  ";
        inOrderT(ptr->rightPtr);
    }
}

template <typename T>
void Tree<T>::preOrder()
{
    preOrderT(rootPtr);
}

template <typename T>
void Tree<T>::preOrderT(Node<T>* ptr)
{
    if(ptr!=0)
    {
        cout<<(ptr->data)<<"  ";
        preOrderT(ptr->leftPtr);
        preOrderT(ptr->rightPtr);
    }
}

template <typename T>
void Tree<T>::postOrder()
{
    postOrderT(rootPtr);
}

template <typename T>
void Tree<T>::postOrderT(Node<T>* ptr)
{
    if(ptr!=0)
    {
        postOrderT(ptr->leftPtr);
        postOrderT(ptr->rightPtr);
        cout<<(ptr->data)<<"  ";
    }
}

/** other functions **/
template <typename T>
void Tree<T>::search(T value)
{
   Node<T>* p=search(rootPtr,value);
   if(p==NULL)
        cout<<value<<" not present in tree.\n";
    else
        cout<<value<<" present in the tree.\n";
}

template <typename T>
Node<T>* Tree<T>::search(Node<T>* ptr,T key)
{
      if(ptr==NULL || key==(ptr->data))
            return ptr;
      else if(key<(ptr->data))
            return search(ptr->leftPtr,key);
      else
            return search(ptr->rightPtr,key);      
}

template <typename T>
Node<T>* Tree<T>::minimum(Node<T>* ptr)
{
         while((ptr->leftPtr)!=NULL)
         {
                                 ptr=ptr->leftPtr;
         }
         return ptr;
}
 
template <typename T>
Node<T>* Tree<T>::maximum(Node<T>* ptr)
{
         while((ptr->rightPtr)!=NULL)
         {
                                 ptr=ptr->rightPtr;
         }
         return ptr;
}
         
template <typename T>
Node<T>* Tree<T>::successor(Node<T>* ptr)
{
          Node<T>* y = ptr->parent;
         if((ptr->rightPtr)!=NULL)
                return minimum((ptr->rightPtr));
         else
         {
             while(y!=NULL && ptr==(y->rightPtr))
             {
                            ptr=y;
                            y=y->parent;
             }
         }
         return y;       
}

template <typename T>
Node<T>* Tree<T>::predecessor(Node<T>* ptr)
{
          Node<T>* y = ptr->parent;
         if(ptr->leftPtr!=NULL)
               return maximum(ptr->leftPtr);
         else
         {
             while(y!=NULL && ptr==(y->leftPtr))
             {
                            ptr=y;
                            y=y->parent;
             }
         }
         return y;
}

template <typename T>
void Tree<T>::del(T value)
{
    Node<T>* z=search(rootPtr,value);
    if(z!=NULL)
    {     
         del(z);
         cout<<value<<" deleted from Tree.\n";
    }
    else
    {
        cout<<value<<" not present in tree, so deletion terminated.\n";
    }
}
template <typename T>
void Tree<T>::del(Node<T>* z)
{
    Node<T>* y;
    Node<T>* x;
    if(z->leftPtr==NULL || z->rightPtr==NULL)
          y=z;
    else
         y=successor(z);
         
    if(y->leftPtr==NULL)
          x=y->rightPtr;
    else
          x=y->leftPtr;
          
    if (x!=NULL && (y->parent)!=NULL)
    {
        x->parent=y->parent;
    }
    
    if((y->parent)==NULL)
    {
        rootPtr=x;
    }
    else
    {
        if(y=(y->parent)->leftPtr)
               (y->parent)->leftPtr=x;
        else
                (y->parent)->rightPtr=x;       
    }
    if(y->data != z->data)
          z->data=y->data;
    //return y;      
       
}

template <typename T>
int Tree<T>::totalNodes()
{
    int counter=0;
    totalNodesT(rootPtr,counter);
    return counter;
}

template <typename T>
void Tree<T>::totalNodesT(Node<T>* ptr,int& counter)
{
    if(ptr!=0)
    {
        totalNodesT((ptr->leftPtr),counter);
        counter++;
       // cout<<ptr->data<<"  "<<counter<<" | ";
        totalNodesT((ptr->rightPtr),counter);
    }
}

template <typename T>
T Tree<T>::sum()
{
    T sum=0;
    sumT(rootPtr,sum);
    return sum;
}

template <typename T>
void Tree<T>::sumT(Node<T>* ptr,T& sum)
{
    if(ptr!=0)
    {
        sumT((ptr->leftPtr),sum);
        sum=sum+(ptr->data);
        //cout<<ptr->data<<"  "<<sum<<" | ";
        sumT((ptr->rightPtr),sum);
    }
}

template <typename T>
int Tree<T>::leafNodes()
{
    int counter=0;
    leafNodesT(rootPtr,counter);
    return counter;
}

template <typename T>
void Tree<T>::leafNodesT(Node<T>* ptr,int& counter)
{
    if(ptr!=0)
    {
        if((ptr->leftPtr)==0 && (ptr->rightPtr)==0)
              counter++;
              
        totalNodesT((ptr->leftPtr),counter);
        totalNodesT((ptr->rightPtr),counter);
    }
}

template <typename T>
int Tree<T>::depth()
{
    int height=0;
    int temp=0;
    depthT(rootPtr,height,temp);
    return height;
}

template <typename T>
void Tree<T>::depthT(Node<T>* ptr,int& height,int& temp)
{
     if(ptr==0)
    {
        return;
    }
    else
    {
        temp++;
        if(temp>height){ height=temp; }
        depthT((ptr->leftPtr),height,temp);
        depthT((ptr->rightPtr),height,temp);
        temp--;
        
    }
}
