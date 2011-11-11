#include <iostream>
#include <cstring>
using namespace std;

#include "Tree.h"
void instructions();

template <typename T>
void testTree(Tree<T>& object,const string& type)
{
	cout<<"Testing a tree of "<<type<<" values:\n";
	instructions();

	int choice;
	T value;
     do
     {
        cout<<"\n\nChoice : ";
        cin>>choice;	

	  switch(choice)
	  {
        case 1:
		cout<<"Enter "<<type<<" to insert : ";
		 cin>>value;
		 object.insert(value);
		 object.heapsort();
	/*	cout<<"\n Total Nodes: "<<object.totalNodes();
		cout<<"\n No. of leaf nodes: "<<object.leafNodes();
		cout<<"\n Sum of all nodes: "<<object.sum();
		cout<<"\n Depth of Tree: "<<object.depth();  */
        cout<<"\n Inorder Traversal: ";
        object.inOrder();
        cout<<"\n PreOrder Traversal: ";
        object.preOrder();
        cout<<"\n PostOrder Traversal: ";
        object.postOrder();
		break;

		case 2:
		object.del(value);
	  /*  cout<<"\n Total Nodes: "<<object.totalNodes();
	    cout<<"\n No. of leaf nodes: "<<object.leafNodes();
	    cout<<"\n Sum of all nodes: "<<object.sum();
	    cout<<"\n Depth of Tree: "<<object.depth(); */
        cout<<"\n Inorder Traversal: ";
        object.inOrder();
        cout<<"\n PreOrder Traversal: ";
        object.preOrder();
        cout<<"\n PostOrder Traversal: ";
        object.postOrder();		
		break;
	
      }	
    }while(choice!=0);
     
     cout<<"Tree Test Ended.\n";  
}

void instructions()
{
	cout<<" Enter one of the following choices:\n"
	    <<"  1 to insert in the Tree : \n"                          
		<<"  2 to delete from the Tree : \n"
		<<"  0 to end Tree testing.\n\n";
		
}

int main()
{
    int type;
    cout<<"  Enter the data type of the Tree : \n" 
        <<"    1 for int data type\n"
        <<"    2 for float data type\n"
        <<"    3 for char data type\n"
        <<"    4 for string data type\nEnter: ";
        
    cin>>type;
    if(type==1)
    {
	    Tree<int> intTree;
	    testTree(intTree,"integer");
    }
    else if(type==2)
    {
        Tree<float> floatTree;
	    testTree(floatTree,"float");
    }
    else if(type==3)
    {
        Tree<char> charTree;
	    testTree(charTree,"char");
    }
    else if(type==4)
    {
        Tree<string> strTree;
	    testTree(strTree,"string");
    }

	cout<<endl;
	system("pause");
	return 0;
}


