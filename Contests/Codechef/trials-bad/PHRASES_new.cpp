#include <iostream>
using namespace std;
void merge_sort(string* ,int );
string* s;
string* substring;

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

    cin>>s[0];
    int smallest_size=s[0].size();
    string smallest_str=s[0];

    for(int i=1;i<count;i++)
    {	    
         cin>>s[i];
	 int temp=s[i].size();
	 if(temp<smallest_size)
	 {
		 smallest_size=temp;
		 smallest_str=s[i];
	 }
    }
         
     
    int len=smallest_size/2;
    int size=(len+1)*(len+2)/2;
//    cout<<size<<endl;   
    substring=new string[size];
    
    int k=0;
    for(int i=0;i<=len;i++)
    {
          for(int j=0;j<=(len-i);j++)
          {
            substring[k]=smallest_str.substr(i,(len-i-j+1));
  //          cout<<substring[k]<<"  ";
            k++;
          }
    }
   
    string str;

    int max_length=len+1; 
    int length_str=0;
    
    for(int i=(size-1);i>=0;i--)
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
                   int temp=str.size();
                   if(temp==max_length)
                         length_str=max_length;
                   else if(temp>length_str)
                   {
                         length_str=temp;
                   }   
                  
            }
    }
    result[p]=length_str;
  }
  for(int p=0;p<cases;p++)
      cout<<result[p]<<endl;
    system("pause");  
    return 0;
}


