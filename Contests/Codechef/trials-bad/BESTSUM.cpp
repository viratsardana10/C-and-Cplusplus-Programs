#include <iostream>
using namespace std;
void merge_sort(int* ,int );
void print(int* ,int );
int* a;

int main()
{
    int N,k,p;
    cin>>N>>k>>p;
    
    a=new int[N];
    for(int i=0;i<N;i++)
         cin>>a[i];
         
    merge_sort(a,N);
    int sum=0;
    for(int i=0;i<N;i++)
    {
           // int partial_sum_modulo_p;
            sum+=a[i];
            
    }
    
    int factor=sum%p;
    
    //print(a,N);     
    
    system("pause");
    return 0;
}

void merge_sort(int* a,int n)
{
     for(int j=1;j<n;j++)
     {
             int key=a[j];
             int i=j-1;
             while(i>=0 && a[i]>key)
             {
                        a[i+1]=a[i];
                        i--;
             }
             a[i+1]=key;
     }
}

void print(int* a,int n)
{
     for(int i=0;i<n;i++)
     {
             cout<<a[i]<<"  ";
     }
     cout<<endl;
}
