template <typename T>

class ArStack
{
    public:
        ArStack(int=0);
        
        ~ArStack()
        {
            delete [] Ptr;
        }    
        
        bool push(const T& );
        bool pop(T& );
        
        bool isEmpty() const
        {
            return (top==-1);
        }    
        
        bool isFull() const
        {
            return (top==(size-1));
        }    
    private:
        int size;
        int top;
        T* ptr;
            
};  

template <typename T>
ArStack<T>::ArStack(int s)
{ 
    if(s<1)
       cout<<"Invalid size of stack entered.No stack created.";
    size=(s>0 ? s:0);
    top=-1;
    ptr=new T[size];    
}   

template <typename T>
bool ArStack<T>::push(const T& value)
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
bool ArStack<T>::pop(T& value)
{
    if(!isEmpty())
    {
        top-=1;
        value=ptr[top];
        return true;
    }  
    return false;  
}    