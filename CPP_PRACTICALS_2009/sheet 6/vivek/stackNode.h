template <typename NODETYPE> class Stack;

template <typename NODETYPE>

class Node
{
	friend class Stack<NODETYPE>;
	
    public:
        Node(NODETYPE value)
	    :data(value),nextPtr(0)
	    {
		    
	    }
         
        NODETYPE getData() const
	{
		return data;
	}		

    private:
       NODETYPE data;
       Node<NODETYPE>* nextPtr;       
};
