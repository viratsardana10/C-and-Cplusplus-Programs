#include <iostream>
#include "arr.h" 
using namespace std;
template <typename T>

class Stack2
{
    public:
        Stack2();
        
/*        ~Stack2()
        {
            delete [] ptr;
        }    
  */      
        bool push(const T& );
        bool pop(T& );
        void print();
        	
        bool isEmpty() const
        {
            return (top==(size-1));
        }    
        
        bool isFull() const
        {
            return (top==0);
        }    
    private:
    //    int size;
        int top;
    //    T* ptr;
            
};  

template <typename T>
Stack2<T>::Stack2()
{ 
/*    if(s<1)
       cout<<"Invalid size of stack entered.No stack created.";
    size=(s>0 ? s:0); */
    top=size-1;
   // ptr=new T[size];    
}   

template <typename T>
bool Stack2<T>::push(const T& value)
{
    if(!isFull())
    {
        ptr[top]=value;
        top-=1;	
        return true;
    } 
    return false;   
}       

template <typename T>
bool Stack2<T>::pop(T& value)
{
    if(!isEmpty())
    {
        //top-=1;
        value=ptr[top];
        top+=1;
        return true;
    }  
    return false;  
}    
template <typename T>
void Stack2<T>::print()
{
	if(isEmpty())
	{
		cout<<"The Stack is empty.\n";
	}
	else
	{
		cout<<"The Stack is: ";
		for(int i=top;i>size;i++)
		{
			cout<<ptr[i]<<"  ";

		}
	}
	cout<<endl;
}



















