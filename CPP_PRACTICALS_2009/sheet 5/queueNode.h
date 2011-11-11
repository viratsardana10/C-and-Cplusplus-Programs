template <typename NODETYPE> class Queue;

template <typename NODETYPE>

class Node
{
	friend class Queue<NODETYPE>;
	
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
