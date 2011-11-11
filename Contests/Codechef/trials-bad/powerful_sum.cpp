#include <iostream>
#include <cmath>
using namespace std;
//long sum=0;
long sum_k(int ,int );

int main()
{
    int n; 
    int k,p;
    cin>>n>>k>>p;
    
    long sum=0;
    for(int i=1;i<=n;i++)
    {
            float j=static_cast<float>(i);
            sum+=pow(j,k);
         //   cout<<sum<<"  ";
    }
   /* if(k==1)
        sum=(n*(n+1))/2;
    else if(k==2)
        sum=(n*(n+1)*(2*n+1))/6;
    else if(k==3)
        sum=(n*n*(n+1)*(n+1))/2;
    else if(k==4)    */
    //    sum_k(k,n);
//    for(int i)
  
 //   sum=sum_k(k,n);      
    cout<<(sum%p);
    
    cout<<endl;
    system("pause");
    return 0;
}

long sum_k(int k,int N)
{
      if(k==0)
          {
             //   sum+=(N*N);
                return (N*(N+1)*(2*N+1))/6;
          }
          if(k==1)
          {
                return (N*N*(N+1)*(N+1))/4;      
          }
          
     for(int j=1;j<=N;j++)
     {
         
          for(int i=j;i++;i<=N)
          {
                   return (2*j-1)*sum_k((k-2),N);
          }
     }
}
