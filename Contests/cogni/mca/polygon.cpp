#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream infile("input_poly");
    long N;
    infile >> N;
    double x[N+1];
    double y[N+1];
    
    for(int i=0;i<N;i++)   // It assumes that the vertice are in order
    {
       infile >> x[i];
       infile >> y[i]; 
    }
    x[N]=x[0];
    y[N]=y[0];

    double volume;
    infile >> volume;

    double area=0;
    for(int i=0;i<N;i++)
    {
       area+=x[i]*y[i+1]-x[i+1]*y[i];
    }
    area=area/2;
    if(area<0)
         area=(-1)*area;
    
    double length=volume/area;
    cout.precision(2);
    cout<<fixed<<length;

    cout<<endl;
    return 0;
}





