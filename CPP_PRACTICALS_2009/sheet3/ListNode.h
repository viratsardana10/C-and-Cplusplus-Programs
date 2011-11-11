template <typename NODETYPE>

class ListNode
{
    //friend class LinkedList;
    
    public:
        ListNode()
        {
            nextPtr=0;
        }
        NODETYPE getData()
        {
            return data;
        }
        
    private:
       NODETYPE data;
       ListNode<NODETYPE>* nextPtr;
        
};

