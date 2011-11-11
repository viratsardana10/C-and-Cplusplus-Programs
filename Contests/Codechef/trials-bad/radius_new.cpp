#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main()
{
    int cases;
    cin>>cases;
    for(int p=0;p<cases;p++)
    {
        int count;
        cin>>count;
        int x[count];
        int y[count];
        
        for(int i=0;i<count;i++)
        {
            cin>>x[i]>>y[i];    
        }
    
            
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

    for(int n=0;n<count;n++)
    {
        long double a[size];
        for(int i=0;i<size;i++)
               a[i]=radius[n][i];   
               
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
        cout.precision(2);
        cout<<fixed<<smallest<<" "<<effective_count<<endl; 
    }
    cout<<endl;
  }
  //  system("pause");
    return 0;
}
   
