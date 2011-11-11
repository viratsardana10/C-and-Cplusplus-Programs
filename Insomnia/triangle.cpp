#include <iostream>
#include <fstream>
using namespace std;

class coord 
{
    pubic:
        int x;
        int y;
};
class triangle
{
    public:
        coord v1;
        coord v2;
        coord v3;
};
int main()
{
    ifstream infile("input.txt");
    ofstream outfile("output.txt");
    
    int N;
    infile >> N;
    coord p[N];
   
    for(int i=0;i<N;i++)
    {
        infile >> p[i].x;
        infile >> p[i].y;
    }
    
    int T;
    infile >> T;
    triangle t[T];
    for(int i=0;i<T;i++)
    {
       infile >> t[i].v1.x;
       infile >> t[i].v1.y;
     
       infile >> t[i].v2.x;
       infile >> t[i].v2.y;
       
       infile >> t[i].v3.x;
       infile >> t[i].v3.y;      
    }
    
    for(int i=0;i<T;i++)
    {  
        for(int i=0;i<N-1;i++)
        {
             if(intersect(p[i],p[i+1],t[i].v1,t[i].v2))
             {
                  if(intersect)
             }
              
        }
    }    
} 
/**functions to determine intersection of two lines */
bool intersect(coord p1,coord p2,coord p3,coord p4)
{
    int d1=direction(p3,p4,p1);
    int d2=direction(p3,p4,p2);
    int d3=direction(p1,p2,p3);
    int d4=direction(p1,p2,p4);

    if(((d1>0 && d2<0) || (d3<0 && d4>0)) && ((d3>0 && d4<0) || (d3<0 && d4>0))) 
    {
        return true;
    }
    else if(d1==0 && onsegment(p3,p4,p1))
         return true;
    else if(d2==0 && onsegment(p3,p4,p2))
         return true;
    else if(d3==0 && onsegment(p1,p2,p3))
         return true;
    else if(d4==0 && onsegment(p1,p2,p4))
         return true;
    else return false; }

int direction(coord p0,coord p1,coord p2)
{
     return ((p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y));
}

bool onsegment(coord p0,coord p1,coord p2)
{
   int min_x=(p0.x<p1.x)?p0.x:p1.x;
   int max_x=(p0.x>p1.x)?p0.x:p1.x;
  
   int min_y=(p0.y<p1.y)?p0.y:p1.y;
   int min_y=(p0.y>p1.y)?p0.y:p1.y;

   if(p2.x>=min_x && max_y>=p2.x && p2.y>=min_y && max_y>=p2.y)
          return true;
   else 
         return false;
}

