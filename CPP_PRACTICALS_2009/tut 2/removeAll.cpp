#include <iostream>
using namespace std;

int size;
void removeAll(float [],int& ,float );
void print(float [],int );

int main()
{
    float* a;
    //size;
    float x;
    int n;
    
    cout<<"Enter the size of array: ";
    cin>>size;
    //size;
    
    a=new float[size];
    cout<<"Enter "<<size<<" values:\n";
    for(int i=0;i<size;i++)
    {
        cout<<(i+1)<<": ";
        cin>>a[i];
    }
    cout<<"The array is:\n";
    print(a,size);
    cout<<endl<<endl;
    
    cout<<"Enter the value to be removed:";
    cin>>x;
    cout<<"Enter the size \'n\' up to which the value \'"<<x<<"\' is to be removed:";
    cin>>n;
    
    removeAll(a,n,x);
    //cout<<size;
    print(a,size);
    cout<<endl;
    system("pause");
    return 0;
}

void removeAll(float a[],int& n,float x)
{   
    int counter=0;
    for(int i=(n-1);i>=0;i--)
    {
        if(a[i]==x)
        {
            for(int j=i;j<(size-1);j++)
            {
                a[j]=a[j+1];
            }
            size--;
            counter++;
        }
    }
}

void print(float a[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<a[i]<<"  ";
    }
}
