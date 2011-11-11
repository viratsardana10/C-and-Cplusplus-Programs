/*
 * author : Vivek Prakash
 *   date : 01-02-2011   
 *   Code : THREECLR 
 */

#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

/*==================code for taking fast integer input==================*/
int sign;
int ch;
inline void S( int &x ) {
	x=0;
	while((ch<'0' || ch>'9') && ch!='-' && ch!=EOF)	ch=getchar_unlocked();
	if (ch=='-')
		sign=-1 , ch=getchar_unlocked();
	else
		sign=1;
	do
		x=(x<<3)+(x<<1)+ch-'0';
	while((ch=getchar_unlocked())>='0' && ch<='9');
	x*=sign;
}
/*======================================================================*/

class Queue;

class Node
{
	friend class Queue;
	
    public:
        Node(int value)
	    :data(value),nextPtr(0)
	    {
		    
	    }
         
        int getData() const
	   {
		return data;
	   }		

    private:
       int data;
       Node *nextPtr;       
};

class Queue
{
	public:
		Queue()
			: firstPtr(0),lastPtr(0)
			{
				
			}
		
		void enqueue(const int& );             //equivalent to insertAtBack
		bool dequeue(int& );                    //equivalent to removeFromFront
		bool isEmpty() const;

	private:
		Node* firstPtr;
		Node* lastPtr;
		Node* getNewNode(const int& );
};

void Queue::enqueue(const int& value)
{
	Node* newPtr=getNewNode(value);

	if(isEmpty())
	{
		firstPtr=lastPtr=newPtr;
	}
	else
	{
        lastPtr->nextPtr=newPtr;
        lastPtr=newPtr;
	
	}
}

bool Queue::dequeue(int& value)
{
	if(isEmpty())
	{
		return false;
	}
	else
	{
		Node* tempPtr=firstPtr;

		if(firstPtr==lastPtr)
			firstPtr=lastPtr=0;

		else
		{
			Node* currentPtr=firstPtr;
           
            firstPtr=firstPtr->nextPtr;
            
		}
                
		value=tempPtr->data;
		delete tempPtr;
//		cout<<value<<" dequeued from queue.\n";
	}
}

bool Queue::isEmpty() const
{
	return (firstPtr==0);
}

Node* Queue::getNewNode(const int& value)
{
	return new Node(value);
}


#define INF 99999999

struct graph {
	int adj_list[501];
	int color;
	int size;
} *node; 

int n, m;

void BFS(int );

int main()
{
	int T;
	S(T);
	while(T--) {
		S(n); S(m);
	
		node = new struct graph[n+1];
		for(int i = 1 ; i <= n ; ++i) {
			node[i].color = INF;
			node[i].size = 0;
		}
		
		for(int i = 0 ; i < m ; ++i) {
			int u, v;
			S(u); S(v);
			node[u].adj_list[node[u].size] = v;
			node[u].size += 1;
		}

		for(int i = 1 ; i <= n ; ++i) {
			if(node[i].color == INF) 
				BFS(i);		
		}

		for(int i = 1 ; i <= n ; ++i) {
			printf("%d ", node[i].color);
		}
		printf("\n");
	}
}

void BFS(int source)
{
	Queue nodeq;
	nodeq.enqueue(source);
	node[source].color = 1;	
	
	while(!nodeq.isEmpty()) {
		int v;
		nodeq.dequeue(v);
		
		int len = node[v].size;
		for(int i = 0 ; i < len ; ++i) {
			int w = node[v].adj_list[i];
			if( (node[w].color) >= (node[v].color) ) {
					node[w].color = node[v].color + 1;				
					nodeq.enqueue(w);
			}
		}	
	}
}

