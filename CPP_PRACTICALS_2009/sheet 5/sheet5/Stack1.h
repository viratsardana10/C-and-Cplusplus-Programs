#include <iostream>
#include "arr.h"
using namespace std;
template <typename T>

class Stack1
{
    public:
        Stack1();
        
     /*   ~Stack1()
        {
            delete [] ptr;
        }    
       */ 
        bool push(const T& );
        bool pop(T& );
        void print();
        	
        bool isEmpty() const
        {
            return (top==-1);
        }    
        
        bool isFull() const
        {
            return (top==(size-1));
        }    
    private:
       // int size;
        int top;
       // T* ptr;
            
};  

template <typename T>
Stack1<T>::Stack1(int s)
{ 
   /* if(s<1)
       cout<<"Invalid size of stack entered.No stack created.";
    size=(s>0 ? s:0); */
    top=-1;
   // ptr=new T[size];    
}   

template <typename T>
bool Stack1<T>::push(const T& value)
{
    if(!isFull())
    {
        top+=1;
        ptr[top]=value;   
        return true;
    } 
    return false;   
}       

template <typename T>
bool Stack1<T>::pop(T& value)
{
    if(!isEmpty())
    {
        //top-=1;
        value=ptr[top];
        top-=1;
        return true;
    }  
    return false;  
}    
template <typename T>
void Stack1<T>::print()
{
	if(isEmpty())
	{
		cout<<"The Stack is empty.\n";
	}
	else
	{
		cout<<"The Stack is: ";
		for(int i=top;i>=0;i--)
		{
			cout<<ptr[i]<<"  ";

		}
	}
	cout<<endl;
}


















