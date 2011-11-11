
//  A program to find the maximum common substring in large set of strings 
//

#include <iostream>
using namespace std;
void merge_sort(int* ,int );
string* s;
int* length;

int main()
{
    int cases;
    cin>>cases;
    int result[cases];
    
  for(int p=0;p<cases;p++)
  {
    int count;
    cin>>count;
    s=new string[count];
    for(int i=0;i<count;i++)
         cin>>s[i];
         
    length=new int[count];
    for(int i=0;i<count;i++)
    {
            length[i]=s[i].size();                  
    }
    
   merge_sort(length,count);
    
    int len=length[0]/2;
    string substring[len];
    for(int i=0;i<len;i++)
    {
            substring[i]=s[0].substr(0,(i+1));
    }
    
    string str;
    for(int i=(len-1);i>=0;i--)
    {
            int counter=0;
            for(int j=0;j<count;j++)
            {
                    int pos1=s[j].find(substring[i]);
                    int pos2=s[j].rfind(substring[i]);
                    if(pos1==pos2)
                          break;
                    
                    counter++;      
            }
            if(counter==count)
            {
                   str=substring[i];
                   result[p]=str.size();           
                   break;
            }
    }
  }
  for(int p=0;p<cases;p++)
      cout<<result[p]<<endl;
      
    return 0;
}

void merge_sort(int* a,int n)
{
     for(int j=1;j<n;j++)
     {
             int key=a[j];
             string str=s[j];
             int i=j-1;
             while(i>=0 && a[i]>key)
             {
                        a[i+1]=a[i];
                        s[i+1]=s[i];
                        i--;
             }
             a[i+1]=key;
            s[i+1]=str;
     }
}
