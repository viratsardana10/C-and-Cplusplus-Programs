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
    
    cout<<"\n Inorder Traversal: ";
    intTree.inOrder();
    
    cout<<endl;
    system("pause");
    return 0;
}

