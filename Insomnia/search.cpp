#include <iostream>
#include <fstream>
using namespace std;

int N;
char** a;
int p,q;
bool array_fwd_down(char** ,int ,int ,char );
bool array_fwd_up(char** ,int ,int ,char );
bool array_back_up(char** ,int ,int ,char );
bool array_back_down(char** ,int ,int ,char );

int main()
{
      ifstream infile("input.txt");
      ofstream outfile("output.txt");
 
      infile >> N;
      a=new char*[N];
     
      for(int i=0;i<N;i++)
      {
          a[i]=new char[N];
          for(int j=0;j<N;j++)
          {
               infile >> a[i][j];
          }
      }
   
     string s;
     infile >> s;

     char d=s[0];

     int size=s.size();

     int count = 0;

     for(int i=0;i<N;i++)
     {
          for(int j=0;j<N;j++)
          {
              bool flag1=true;
              bool flag2=true;
              bool flag3=true;
              bool flag4=true;
              p=i;q=j;
              
              if(s[0]=a[i][j])
              for(int k=0;k<size;k++)
              {
              /*    if(flag1)
                        flag1=array_fwd(a,i,j,s[k]);
                  
                   if(flag2)
   		        flag2=array_back(a,i,j,s[k]); */
                 
                   if()
              }
              if(flag1)
                  count++;
              if(flag2)
                  count++;  
          }
     }
     outfile << count << "\n"; 
     for(int i=0;i<N;i++)
            delete [] a[i];
     delete [] a;

}

bool search(char s)
{
     
}
bool array_fwd_down(char** a,int i,int j,char c)
{
    while(i<N && j<N)
    {
       if(c==a[i][j])
       {
            p=i;q=j; 
            return true;
       }

       i++;
       j++;
    }
    return false;
}

bool array_fwd_up(char** a,int i,int j,char c)
{
    while(i>=0 && j<N)
    {
       if(c==a[i][j])
       {
            p=i;q=j; 
            return true;
       }

       i--;
       j++;
    }
    return false;
}

bool array_back_up(char** a,int i,int j,char c)
{
     while(i>=0 && j>=0)
    {
       if(c==a[i][j])
       {
            p=i;q=j; 
            return true;
       }

       i--;
       j--;
    }
    return false;

}

bool array_back_down(char** a,int i,int j,char c)
{
     while(i<N && j>=0)
    {
       if(c==a[i][j])
       {
            p=i;q=j; 
            return true;
       }

       i++;
       j--;
    }
    return false;

}
