#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

long double* radius;
void qsort(long double a[],int ,int );
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
            cin>>x[i]>>y[i];    
            
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
    for(int i=0;i<count;i++)
    {
        for(int j=0;j<size;j++)
            cout<<radius[i][j]<<"  ";
            
        cout<<endl;    
    }    
 /*   for(int n=0;n<count;n++)
    {    
        int size=count-1;
        radius=new long double[size];
        
        int k=0;
        for(int i=0;i<n;i++ )
        {
         
                long double rad=(double)(sqrt(((x[i]-x[n])*(x[i]-x[n]))+((y[i]-y[n])*(y[i]-y[n]))));
                radius[k]=rad;         
                k++;
         
        }
        for(int i=(n+1);i<count;i++)
        {
                long double rad=(double)(sqrt(((x[i]-x[n])*(x[i]-x[n]))+((y[i]-y[n])*(y[i]-y[n]))));
                radius[k]=rad;
                k++;
        }
       //////doing quicksort now////
       qsort(radius,0,size-1);
       //////quicksort ended///////     
        int effective_count=0;
        long double effective_rad=2*radius[0];
      */  
     /*   for(int i=0;i<size;i++)
        {
            if(radius[i]>effective_rad)
                  break;
           
            effective_count++;
                 
        }
        cout.precision(2);
        cout<<fixed<<radius[0]<<" "<<effective_count<<endl; */
    //}
    cout<<endl;
  }
    system("pause");
    return 0;
}

void qsort(long double a[], int lo, int hi) 
{
  int h, l;
  long double p,t;

  if (lo < hi) {
    l = lo;
    h = hi;
    p = a[hi];

    do {
      while ((l < h) && (a[l] <= p)) 
          l = l+1;
      while ((h > l) && (a[h] >= p))
          h = h-1;
      if (l < h) {
          t = a[l];
          a[l] = a[h];
          a[h] = t;
      }
    } while (l < h);

    a[hi] = a[l];
    a[l] = p;

    qsort( a, lo, l-1 );
    qsort( a, l+1, hi );
 }
}
    
