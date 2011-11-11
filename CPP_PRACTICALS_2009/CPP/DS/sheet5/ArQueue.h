#include <iostream>
using namespace std;
template <typename T>

class ArQueue
{
    public:
        ArQueue(int=0);
        
        ~ArQueue()
        {
           delete [] array;
         }    
        
        bool enqueue(const T& );
        bool dequeue( );
        
        bool isEmpty() const
        {
            if(front==0 && end==0) 
               return true;
            else 
               return false;
        }    
        
        bool isFull() const
        {
             if(front==1 && end==size) 
                 return true;
             else 
                 return false;
        }    
    private:
        int size;
        int front;
        int end;
        T *array; 
            
};  

template <typename T>
ArQueue<T>::ArQueue(int s)
{ 
    if(s<1)
       cout<<"Invalid size of stack entered.No stack created.";
    size=(s>0 ? s:0);
    front=0;
    end=0;
    array = new T[size];
}   

template <typename T>

bool ArQueue<T>::enqueue(const T& value)
{
      if(isFull()){
        cout<<"The Queue is full.\n";
    }    
    else{
        if(!isEmpty()){
            end++;
            array[end]=value;
            cout<<"The element pushed is: "<<array[end]<<endl;
        }   
        else{
            front=end=1;
            array[end]=value;
            cout<<"The element pushed is: "<<array[end]<<endl;
        }     
    }    
  /*  if(!isFull())
    {
        if(top==1)
        {
          frontptr[size-1]=value;
          lastptr[size-1]=value;
          top++;   
          return true;
        }
        else
        {
            frontptr[size-top]=value;
            top++;
        }
    } 
    return false;   */
}       

template <typename T>
bool ArQueue<T>::dequeue( )
{
     if(isEmpty()){
        cout<<"The Queue is empty.\n";
    }    
    else{
        cout<<"The element popped is: "<<array[front]<<endl;
        if(front==end){
            front=end=0;
        }    
        else{
            front++;
            T* temp = new T[size];
            int j=0;
            for(int i=front;i<=end;i++,j++){
                temp[j]=array[i];
            }
            for(int i=0;i<j;i++){
                array[i+1]=temp[i];
            }    
            front=1;        
            end=j;
        }    
    }    
    
   /* if(!isEmpty())
    {
        if(top==2)
        {
            cout<<frontptr[size-1]<<" dequeued from Queue.\n Now the Queue is empty.\n";
            delete [] frontptr;
            delete [] lastptr;
        }
        else
        {
           // value=frontptr[size-top-1];
            cout<<frontptr[size-top-1]<<" dequeued from stack;";
            top--; 
        }
            
        return true;
    }  
    return false;   */
}    
