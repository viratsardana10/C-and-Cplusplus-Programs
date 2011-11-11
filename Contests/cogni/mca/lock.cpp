#include <iostream>
#include <cstring>
using namespace std;

class lock_num
{
  public:
    lock_num(int len)
    {
      size=len;
    }
    int size;
    int perm[size];
};

lock_num perms[100000];

void print(int [],int );
int main()
{
  string lock;
  cin>>lock;

  int size=lock.size();
  int size_num=(size-1)/2;

  int num[size_num];
  for(int i=1;i<size;i+=2)
    {
      num[(i-1)/2]=lock[i]-48;
    }
  print(num,size_num);

  return 0;

}

void permutation(int a[],int size)
{
  for(int i=1;i<size-1;i++)
    {
      perms[0].perm[0]=i;
      for(int j=0;j<size-1;j)
    }
}

int* determineNext(int present_perm[],int present_size)
{
    int j=present_perm[0];
    
    int next_count=N-present_size;
    int next[count]; 
    for(int i=0,j=0;i<N;i++)
    {

    }     
    for(int i=1;i<present_size;i++)
    {
        j=a[j];
    }
    if(j==present_size)    // 0 can't be next element
    {
    }    
}

bool search(int present_perm[],int present_size,int next)
{
    for(int i=0;i<present_size;i++)
    {
        if(present_perm[i]==next)
               return false;
    }
    return true;
}
void print(int a[],int size)
{
  for(int i=0;i<size;i++)
    cout<<a[i]<<" ";

  cout<<endl;
}
