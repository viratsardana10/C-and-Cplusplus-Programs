#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
using namespace std;

long double* a;

int main()
{
    int cases=1;
   // cin>>cases;
    for(int p=0;p<cases;p++)
    {
        int count=400;
       // cin>>count;
        int x[count];
        int y[count];
        
        for(int i=0;i<count;i++)
        {
          srand(time(0));
          x[i]=rand()%10000;
          srand(time(0));
          y[i]=rand()%10000;
         //   cin>>x[i]>>y[i];    
        }
    long time1=clock();
            
    int size=count-1;
    long double radius[count][size];
    int d=0;
    for(int i=0;i<size;i++)
    {
        int k=i;
        for(int j=(i+1);j<count;j++)
        {
            long double rad=(double)(sqrt(((x[i]-x[j])*(x[i]-x[j]))+((y[i]-y[j])*(y[i]-y[j]))));
            radius[i][k]=rad;
            radius[j][d]=rad;
            k++;
        }
        d++;
    }
    double time_a=0.0;   
    for(int n=0;n<count;n++)
    {
        long time_a1=clock();
        a=new long double[size];
        for(int i=0;i<size;i++)
               a[i]=radius[n][i];   
               
        long time_a2=clock();
        time_a+=static_cast<double>(time_a2-time_a1)/1000;       
      
        long double smallest=a[0];
        for(int i=1;i<size;i++)
        {
            if(a[i]<smallest)
                     smallest=a[i];
        }    
        int effective_count=0;
        long double effective_rad=2*smallest;
        
        for(int i=0;i<size;i++)
        {
            if(a[i]<=effective_rad)
                  effective_count++;
                 
        }
      //  cout.precision(2);
       // cout<<fixed<<a[0]<<" "<<effective_count<<endl; 
    }
    long time2=clock();
    double time_t=static_cast<double>(time2-time1)/1000;
    cout<<time_t<<" seconds time taken. In a: "<<time_a;
    cout<<endl;
  }
    system("pause");
    return 0;
}
   
