#include <iostream>
#include <fstream>
using namespace std;

int* obstacles_x;
int* obstacles_y;
int* towers_x;
int* towers_y;
int towers_count;
int obstacles_count;
bool isOnLine(int ,int );
bool isOnline(int ,int ,int ,int ,int ,int );

int main()
{
    cin>>towers_count;
    towers_x=new int[towers_count];
    towers_y=new int[towers_count];

    for(int i=0;i<towers_count;i++)
    {
         cin >> towers_x[i];
         cin >> towers_y[i];
    }
 
    cin>>obstacles_count;
    obstacles_x=new int[obstacles_count];
    obstacles_y=new int[obstacles_count];
    for(int i=0;i<obstacles_count;i++)
    {
         cin >> obstacles_x[i];
         cin >> obstacles_y[i];
    }
  
   int count=towers_count-1;
   int communication_pairs=0;
  
   for(int i=0;i<towers_count;i++)
   {
      for(int j=(i+1);j<towers_count;j++)
      {
          if(!isOnLine(i,j))
                communication_pairs++;
      }
   }
   cout<<communication_pairs<<endl;
   return 0;
}

bool isOnLine(int tower1,int tower2)
{
   for(int k=0;k<obstacles_count;k++)  
   {
       if(isOnline(towers_x[tower1],towers_y[tower1],towers_x[tower2],towers_y[tower2],obstacles_x[k],obstacles_y[k]))
              return true;   
   }
   for(int k=0;k<tower1;k++)
   {
        if(isOnline(towers_x[tower1],towers_y[tower1],towers_x[tower2],towers_y[tower2],towers_x[k],towers_y[k]))
              return true;   
   }
   for(int k=tower1+1;k<tower2;k++)
   {
        if(isOnline(towers_x[tower1],towers_y[tower1],towers_x[tower2],towers_y[tower2],towers_x[k],towers_y[k]))
              return true;   
   }
   for(int k=tower2+1;k<towers_count;k++)
   {
        if(isOnline(towers_x[tower1],towers_y[tower1],towers_x[tower2],towers_y[tower2],towers_x[k],towers_y[k]))
              return true;   
   }
   return false;
}

bool isOnline(int x1,int y1,int x2,int y2,int ox,int oy)
{
     double slope1_y=(y2-y1);
     double slope1_x=(x2-x1);
     double slope2_y=(oy-y1);
     double slope2_x=(ox-x1);
     
     if(slope1_x==0 && x1==ox && oy>min(y1,y2) && oy<max(y1,y2))
                return true;
     
     double slope1=slope1_y/slope1_x;
     double slope2=slope2_y/slope2_x; 
     if(slope1==slope2)
          return true;
     else return false;
}

int max(int x,int y)
{
   return (x>y)?x:y;
}
int min(int x,int y)
{
  return (x<y)?x:y;
}
