template <typename NODETYPE> class List;

template <typename NODETYPE>

class Node
{
	friend class List<NODETYPE>;
	
    public:
        Node(NODETYPE value)
	    :data(value),nextPtr(0),prevPtr(0)
	    {
		    
	    }
         
        NODETYPE getData() const
	{
		return data;
	}		

    private:
       NODETYPE data;
       Node<NODETYPE>* nextPtr;       
       Node<NODETYPE>* prevPtr;
};
