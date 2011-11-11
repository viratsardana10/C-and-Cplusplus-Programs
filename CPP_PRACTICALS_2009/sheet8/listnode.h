template <typename T> class List;
template <typename T> class Tree;
template <typename T>

class Node_list
{
	friend class List<T>;
	friend class Tree<T>;
	
    public:
        Node_list(T value)
	    :data(value),nextPtr(0),prevPtr(0)
	    {
		    
	    }
         
        T getData() const
	{
		return data;
	}		
	T data;
   // private:
     //  T data;
       Node_list<T>* nextPtr;       
       Node_list<T>* prevPtr;
};
