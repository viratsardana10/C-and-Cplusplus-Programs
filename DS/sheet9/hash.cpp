#include <iostream>
using namespace std;
void insert(int );
void search(int );
int h(int ,int);
void print();
int* a;
int m;
int NIL=-99999;

int main()
{
	cout<<"Enter the size of hash table: ";
        cin>>m;

	a=new int[m];
	for(int i=0;i<m;i++)
	{
		a[i]=NIL;
	}

	int choice;
	int value;
	cout<<"Enter one of the following choices:\n"
		<<" 1 to insert. \n"
		<<" 2 to search. \n"
		<<" 0 to end Hash Table testing.\n";

	do
	{
		cout<<"Enter choice: ";
		cin>>choice;

		switch(choice)
		{
			case 1:
				cout<<"Enter integer to insert: ";
				cin>>value;
				insert(value);
				print();
				break;
			case 2:
				cout<<"Enter integer to search: ";
				cin>>value;
				search(value);
				print();
				break;
			default:
				//
				break;
				
		}
	}while(choice!=0);
	cout<<"Hash Test Ended.\n";

	system("pause");
	return 0;
}

void insert(int k)
{
	int i=0;
	while(i<m)
	{
		int j=h(k,i);
		if(a[j]==NIL)
		{
			a[j]=k;
			return;
		}
		else
			i+=1;
	}
	cout<<"\nError: Hash Table Overflow.\n";

}
int h(int k,int i)
{
	int h_k=k%m;
	return ((h_k+i)%m);
}

void search(int k)
{
	int i=0;
        while(i<m)
	{
		int j=h(k,i);
		if(a[j]==k)
		{
			cout<<k<<" found at "<<i<<" position.\n";
			return;
		}
		else if(a[j]==NIL)
		{
			cout<<k<<" not present in Hash Table.\n";
			return;
		}
		else
			i+=1;
	}
}

void print()
	{
        cout<<endl;
		int j=0;
		cout<<"The Hash Table is: ";
		while(j<10)
		{
			cout<<a[j]<<"  ";
			j++;
		}
  cout<<endl;
	}











