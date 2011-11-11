#include <iostream>
#include <fstream>
using namespace std;

int* a;
void qsort(int [],int ,int );

int main()
{
    ifstream infile("input.txt");
    ofstream outfile("output.txt");
    
    int N;
    
    infile >> N;
    a=new int[N];
    for(int i=0;i<N;i++)
           infile >> a[i];

    qsort(a,0,(N-1));
    outfile << a[N-1] << "\n" << a[N-2] <<"\n";   
  
}
void qsort(int a[], int lo, int hi) 
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
