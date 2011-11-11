#include <iostream>
#include "TreeNode.h"
#include "list.h"
using namespace std;

template <typename T>
class Tree
{
    public:
        Tree()
        :rootPtr(0)
        {
                
        }
	void make_queue();
	void build_max_heap();
	void max_heapify(Node<T>* );
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
        void del(Node<T>* );
        Node<T>* minimum(Node<T>* );
        Node<T>* maximum(Node<T>* );
        Node<T>* successor(Node<T>* );
        Node<T>* predecessor(Node<T>* );
  
    private:
        Node<T>* rootPtr;
	Node<T>* getNode(int i);
        Node<T>* getNewNode(T& );
	List<Node<T>*> list;
	Node<T>* array[];
	int size;
    //    void insert(Node<T>* ,Node<T>** ,T& );
        void inOrderT(Node<T>* );
        void preOrderT(Node<T>* );
        void postOrderT(Node<T>* );
        
       
           
};

template <typename T>
void Tree<T>::insert(T& value)
{
                                    // 0:color white      1:color gray       2:color black
	
	if(rootPtr==0)
	{
		rootPtr=getNewNode(value);
		rootPtr->parent=0;
	}
	else
	{
		rootPtr->color=1;
	//	List<Node<T>*> list;

		list.insertAtBack(rootPtr);
		while(!list.isEmpty())
		{
			Node<T>* ptr=0;
			if(list.removeFromFront(ptr)) { //cout<<ptr->data<<"removed."<<endl; 
			}

			if((ptr->leftPtr)==0)
			{
				(ptr->leftPtr)=getNewNode(value);
				(ptr->leftPtr)->parent=ptr;
				return;
			}
			else
			{
				list.insertAtBack(ptr->leftPtr);
			}

			if((ptr->rightPtr)==0)
			{
				(ptr->rightPtr)=getNewNode(value);
				(ptr->rightPtr)->parent=ptr;
				return;
			}
			else
			{
				list.insertAtBack(ptr->rightPtr);
			}

		}

	}



}

template <typename T>
void Tree<T>::make_queue()
{
	cout<<"Inside build_max_heap.....\n";
	if(rootPtr==0)
	{
		cout<<"Heap is empty. Building max heap is meaningless.\n";
		return;
	}
	else
	{
		int i=0;
		list.clear();
		List<Node<T>*> temp;
		list.insertAtBack(rootPtr);
		temp.insertAtBack(rootPtr);
        
		Node<T>* ptr=rootPtr;
		List<T> dataList;
		dataList.insertAtBack(rootPtr->data);
                array[i]=ptr;

		while(!temp.isEmpty())
		{
			temp.removeFromFront(ptr);

			if((ptr->leftPtr)!=0)
			{
				i++;
				array[i]=ptr->leftPtr;
				list.insertAtBack(ptr->leftPtr);
                                dataList.insertAtBack(ptr->leftPtr->data);
				temp.insertAtBack(ptr->leftPtr);
			}
			if((ptr->rightPtr)!=0)
			{
				i++;
				array[i]=ptr->rightPtr;
				list.insertAtBack(ptr->rightPtr);
				dataList.insertAtBack(ptr->rightPtr->data);
				temp.insertAtBack(ptr->rightPtr);
			}
		}

		size=(i+1);
		cout<<"Array: ";
		for(int j=0;j<size;j++)
		{
			cout<<array[j]<<"    ";
		}
		cout<<endl;
//		list.print();
//		dataList.print();
//		cout<<"Exiting build_max_heap.....\n";
	}
}
template <typename T>
void Tree<T>::build_max_heap()
{

	make_queue();
	list.print();
		for(int j=(size/2);j>=1;j--)
		{
			Node<T>* node=0;
			if(j!=1)
			{
				node=getNode(j);
			}
			else
			{
				node=rootPtr;
			}
			cout<<node<<endl;
			max_heapify(node);
		}
	cout<<"vivek here...\n";	
	make_queue();
       list.print();	
                 
}

       	


template <typename T>
void Tree<T>::max_heapify(Node<T>* node)
{
	cout<<"Max_heapify......\n";
	Node<T>* largest=0;
	cout<<"here......\n";
	if((node->leftPtr)!=NULL)
	{
		if(((node->leftPtr)->data) > (node->data))
		{
			largest=(node->leftPtr);
			cout<<largest->data;
		}
		else
			largest=node;
	}
	if((node->rightPtr)!=NULL)
	{
		if(((node->rightPtr)->data) > (largest->data))
		{		largest=(node->rightPtr);
			cout<<largest->data;
		}
	}
   
   if((node->leftPtr)!=NULL || (node->rightPtr)!=NULL) {	
	if((largest->data)!=(node->data))
	{
	//	Node<T>* temp_left=node->leftPtr;
	//	Node<T>* temp_right=node->rightPtr;
		T temp_data=(node->data);

                (node->data)=(largest->data);
		largest->data=temp_data;
		max_heapify(largest);
		cout<<"call...\n";
	}
   }


}
template <typename T>
Node<T>* Tree<T>::getNode(int i)
{
	return array[i-1];
/*	int j=1;
	Node_list<Node<T>*>* ptr=firstPtr;

	while(j<i && ptr!=0)
	{
		ptr=ptr->nextPtr;
		j++;
	}
	return ptr->data;
	*/
}
/*
template <typename T>
void Tree<T>::max_heapify(int i)
{
	cout<<"Inside max_heapify...\n";
	Node<T>* largest=0;
	Node<T>* left=array[i]->leftPtr;
	Node<T>* right=array[i]->rightPtr;
	Node<T>* temp;
	int index;

	if(left!=0)
	{
	     if((left->data)>(array[i]->data))
	     {
		largest=left;
		temp=array[(2*i+1)];
		index=(2*i+1);
	     }
	     else { largest=array[i]; }
	}

	if(right!=0)
	{
		if((right->data) > (largest->data))
		{
			largest=right;
			temp=array[(2*i+2)];
			index=(2*i+2);
		}
	}

	if(largest!=array[i])
	{
		Node<T>* temp;
		int index;
	//	if(largest==left) { temp=array[(2*i+1)]; index=(2*i+1); }
	//	else if(largest==right) { temp=array[(2*i+2)]; index=(2*i+2); }
		
		largest=array[i];
		array[i]=temp;
			for(int j=0;j<(sizeof(array)/sizeof(Node<T>*));j++)
		{
			cout<<array[j]->data<<"   ";
		}
		cout<<endl;

		max_heapify(index);
	}

}*/
/*
template <typename T>
void Tree<T>::insert(Node<T>* parent=0,Node<T>** ptr,T& value,int counter)
{
    if(*ptr==0)
    {
       *ptr=getNewNode(value);
       (*ptr)->parent=parent;
    }
    else if((*ptr)->leftPtr == NULL)
    {
        (*ptr)->leftPtr = getNewNode(value);
       (*ptr)->leftPtr->parent = parent;
    }
    else if((*ptr)->rightPtr==NULL)
    {
         (*ptr)->rightPtr = getNewNode(value);
         (*ptr)->rightPtr->parent = parent;
    }         
    else
        {
                counter++;
                if((counter%2)==0)    
                      insert((*ptr),&((*ptr)->leftPtr),value,counter);
                else
                       insert((*ptr),&((*ptr)->rightPtr),value,counter);      
            
        }    
        
    
}
*/
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
         if(ptr->left!=NULL)
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
    del(z);
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
