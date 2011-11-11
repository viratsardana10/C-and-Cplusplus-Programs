template <typename T> class List;

template <typename T>

class Node
{
	friend class List<T>;
	
    public:
        Node(T value)
	    :data(value),nextPtr(0),prevPtr(0)
	    {
		    
	    }
         
        T getData() const
	{
		return data;
	}		

    private:
       T data;
       Node<T>* nextPtr;       
       Node<T>* prevPtr;
};
