#include<iostream>

using namespace std;

struct node
{
int left;
int right;
int key;
};

void heapify(node B[],int i,int size)
{
    int min,temp;
    if(size==2 && B[i].left<=size && B[i].key>(B[B[i].left].key))
    {
            temp=B[B[i].left].key;
            B[B[i].left].key=B[i].key;
            B[i].key=temp;
    }        
    else if(B[i].left<=size && (B[B[i].left].key)<=(B[B[i].right].key) && B[i].key>(B[B[i].left].key))
    {
            temp=B[B[i].left].key;
            B[B[i].left].key=B[i].key;
            B[i].key=temp;
            heapify(B,B[i].left,size);
    }    

    else if(B[i].right<=size && (B[B[i].left].key)>(B[B[i].right].key) && B[i].key>(B[B[i].right].key))
    {
            temp=B[B[i].right].key;
            B[B[i].right].key=B[i].key;
            B[i].key=temp;
            heapify(B,B[i].right,size);
    }    
       
}

void buildheap(node B[],int size)
{
    for(int i=size/2;i>=1;i--)
    {
        heapify(B,i,size);
    }
}

void heapsort(node B[],int size)
{
    buildheap(B,size);
    int temp;
    for(int i=size;i>1;i--)
    {
        temp=B[i].key;
        B[i].key=B[1].key;
        B[1].key=temp;
        size--;
        heapify(B,1,size);
    }
}

int main()
{
int size,i;
i=0;
node in[50];
cout<<"Enter integers, 0 to terminate: ";
do{
++i;
cin>>in[i].key;
//cout<<"\n";
}while(in[i].key!=0);
for(int j=1;(2*j+1)<50;j++)
{
    in[j].left=2*j;
    in[j].right=2*j+1;
}    
size=(--i);
heapsort(in,size);
cout<<"The sorted integers are: ";
for(i=size;i>=1;i--)
{
    cout<<in[i].key<<" ";
}   
cout<<endl; 
system("pause");
}
