template <typename T>class Tree;

template <typename T>

class Node
{
	friend class Tree<T>;
	
    public:
        Node(T value)
	    :data(value),rightPtr(0),leftPtr(0),parent(0),color(0)
	    {
		    
	    }
         
        T getData() const
	{
		return data;
	}		

    private:
       T data;
       Node<T>* leftPtr;
       Node<T>* rightPtr;
       Node<T>* parent;
       int color;       
};
