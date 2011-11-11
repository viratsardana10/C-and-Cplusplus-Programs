#include<iostream>

using namespace std;
class bintree
{
      private:
         bintree*lchild;
         bintree*rchild;
         bintree*llist;
         bintree*header;
         bintree*temp;
         int key;
      public:
         bintree*root;
         bintree*temp1;
         bintree*temp2;
         bintree*header1;
         bintree(){header=NULL;header1=NULL;temp2=NULL;lchild=NULL;rchild=NULL;llist=NULL;temp1=NULL;root=NULL;}
         void create()
         {
              if(header==NULL)
              {
                 
                 header=new bintree;
                 root=header;
                 header->lchild=new bintree;
                 header->rchild=new bintree;
                 header->llist=header->lchild;
                 header->lchild->llist=header->rchild;
                 temp=header->rchild;
                 cout<<"Enter root of the tree:"<<endl;
                 cin>>header->key;
                 cout<<"Enter left child:"<<endl;
                 cin>>header->lchild->key;
                 cout<<"Enter right child:"<<endl;
                 cin>>header->rchild->key;
              }
              else
              {
                  header=header->llist;
                  header->lchild=new bintree;
                  cout<<"Enter left child:"<<endl;
                  cin>>header->lchild->key;
                  temp->llist=header->lchild;
                  temp=temp->llist;
                  header->rchild=new bintree;
                  cout<<"Enter right child:"<<endl;
                  cin>>header->rchild->key;
                  temp->llist=header->rchild;
                  temp=temp->llist;
              }
                  
      } 
		int search(int x)
		{
			temp1=root;
			int ret=0;
			while(temp1!=0)
			{
				if(x==temp1->key)
				{	ret=1;
					break;
                }
				else
					temp1=temp1->llist;
			}	
			return ret;
		}
		void delete1 ()
		{
			temp2=root;
			if(header==0)
			{
				cout<<"Tree is Empty."<<endl;
			}
			else
			{
				while(temp2->llist->llist!=temp)
				{
						temp2=temp2->llist->llist;
				}
				if(temp2==root)
				{
					temp1=root->rchild;
					root->rchild=0;
					root->lchild->llist=0;
					delete temp1;
					temp1=root->lchild;
					root->lchild=0;
					root->llist=0;
					delete temp1;
					delete root;
					temp=0;
					root=0;
					header=0;
					cout<<"Tree is Now empty."<<endl;
				}
				else
				{
					header1=header;
					temp1=header1->rchild;
					header1->rchild=0;
					header1->lchild->llist=0;
					delete temp1;
					temp1=header1->lchild;
					header1->lchild=0;
					header1->llist=0;
					delete temp1;
					temp=temp2;
					temp2=root;
					while(temp2->llist!=header)
					{
						temp2=temp2->llist;
					}
					header=temp2;
				}	
			
			}
			
		}
      void inorder(bintree*p)
      {
      	if(p!=NULL)
      	{inorder(p->lchild);
      	cout<<p->key<<"  ";
      	inorder(p->rchild);
      	}
      //	else
      	//	cout<<"tree empty"<<endl;
      }
      void preorder(bintree*p)
      {
      	if(p!=NULL)
      	{
      		cout<<p->key<<"  ";
      		preorder(p->lchild);
      		preorder(p->rchild);
      	}
      	//else
      	//	cout<<"tree empty"<<endl;
      } 
      void postorder(bintree*p)
      {   
			 if(p!=NULL)
			 {
					postorder(p->lchild);
        		  	postorder(p->rchild);
         	  	cout<<p->key<<"  ";
			} 
			//else
      	//	cout<<"tree empty"<<endl;
		}
}; 
               
 int main()
 {   
     int j,ch;
     bintree t;
	  char choice='y';				
     while(choice=='y')
     {
			cout<<"Enter 1 to insert in tree:"<<endl;
			cout<<"Enter 2 to delete from tree:"<<endl;
			cout<<"Enter 3 to search from tree:"<<endl;
			cout<<"Enter choice: "<<endl;
			cin>>ch;
			int ret,sval;
			switch(ch)
			{
				case 1:
					t.create();
					break;
				case 2:
					t.delete1();
					break;
				case 3:
					cout<<"Enter node to search from tree: ";
					cin>>sval;
					ret=t.search(sval);
					if(ret!=0)
					{
						cout<<sval<<" is present."<<endl;
						t.inorder(t.root);
						cout<<endl;
                    }
					else
						cout<<sval<<" is not present."<<endl;
					break;
				default:
					cout<<"wrong choice entered"<<endl;
					break;
			}
			cout<<endl;
			cout<<"do you wish to continue (y/n) : "<<endl;
	//		cout<<"y:yes n:no"<<endl;
			cin>>choice;
		}
		char choicetr='y';
		int cht;
		while(choicetr=='y')
		{
			cout<<"1 for inorder :"<<endl;
			cout<<"2 for preorder :"<<endl;
			cout<<"3 post postorder :"<<endl;
			cin>>cht;
			switch(cht)
			{
				case 1:
					cout<<"Inorder traversal:";
				   t.inorder(t.root);
					cout<<endl;
					break;
				case 2:
					cout<<"preorder traversal: ";
   			   t.preorder(t.root);
  				   cout<<endl;
  				   break;
  				case 3:
     				cout<<"postorder traversal: ";
     				t.postorder(t.root);
     				cout<<endl;
     				break;
     			default:
					cout<<"Wrong choice entered"<<endl;
					break;
			}
			cout<<"do you wish to continue (y/n) : "<<endl;
	//		cout<<"y:yes n:no"<<endl;
			cin>>choicetr;
				
		}
     
     cin.get();
     cin.ignore();
     return 0;
 } 
