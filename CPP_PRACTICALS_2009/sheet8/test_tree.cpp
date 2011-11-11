#include <iostream>
#include "Tree.h"
using namespace std;

int main()
{
    Tree<int> intTree;
    int value;
    
    cout<<"Enter 5 integer values: ";
    for(int i=0;i<5;i++)
    {
        cin>>value;
        intTree.insert(value);
    }
    //intTree.build_max_heap();
    intTree.heapsort();
    cout<<"\n Inorder Traversal: ";
    intTree.inOrder();
    cout<<"\n PreOrder Traversal: ";
    intTree.preOrder();
    cout<<"\n PostOrder Traversal: ";
    intTree.postOrder();
    
    cout<<"Enter a value to search from tree: ";
    cin>>value;
    intTree.search(value);
    
    cout<<"Enter a value to delete from tree: ";
    cin>>value;
    intTree.del(value);
    cout<<endl;
    system("pause");
    return 0;
}

